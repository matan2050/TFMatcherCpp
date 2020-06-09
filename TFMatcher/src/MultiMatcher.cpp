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
        int counter = 0;

        int n_threads = omp_get_max_threads();
        int divisor = multiMatcherCollection.size() / n_threads;
        int modulo = multiMatcherCollection.size() % n_threads;
        int deductable_modulo = modulo;

        std::unique_ptr<int[]> workers_job_number = std::make_unique<int[]>(n_threads);
        for (int i(0); i < n_threads; i++)
        {
            workers_job_number[i] = divisor;

            if (deductable_modulo > 0)
            {
                workers_job_number[i] += 1;
                deductable_modulo -= 1;
            }
        }

        #pragma omp parallel for
        for (int i(0); i < multiMatcherCollection.size(); i++)
        {
            results[i] = multiMatcherCollection[i].Distance();
        }
    }

    return results;
}