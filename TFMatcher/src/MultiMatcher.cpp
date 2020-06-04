#include "../include/MultiMatcher.h"

void MultiMatcher::AddPolygon(const Polygon& polygon)
{
    multiMatcherCollection.push_back(Matcher(referencePolygon, polygon));
}

void MultiMatcher::PopPolygon()
{
    multiMatcherCollection.pop_back();
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
        }

    return results;
}