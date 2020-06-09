#include <omp.h>
#include <memory>
#include "../include/MultiMatcher.h"

void MultiMatcher::SetReference(const Polygon& reference)
{
    referencePolygon = reference;
}

void MultiMatcher::AddPolygon(const Polygon& polygon)
{
    multiMatcherCollection.push_back(Matcher(referencePolygon, polygon));
    polygonCounter++;
}

void MultiMatcher::PopPolygon()
{
    multiMatcherCollection.pop_back();
    polygonCounter--;
}

std::vector<double> MultiMatcher::Process() const
{
    std::vector<double> results(multiMatcherCollection.size());
    int counter = 0;

    for (std::vector<Matcher>::const_iterator matchIter = multiMatcherCollection.begin();
        matchIter != multiMatcherCollection.end();
        matchIter++)
        {
             results[counter] = matchIter->Distance();
             counter++;
        }

    return results;
}

std::vector<double> MultiMatcherParallel::Process() const
{
    std::vector<double> results(multiMatcherCollection.size());

    if (0 != multiMatcherCollection.size())
    {
        #pragma omp parallel for
        for (int i(0); i < multiMatcherCollection.size(); i++)
        {
            results[i] = multiMatcherCollection[i].Distance();
        }
    }

    return results;
}