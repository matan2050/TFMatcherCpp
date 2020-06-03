#include "../include/MultiMatcher.h"

void MultiMatcher::AddPolygon(const Polygon& polygon)
{
    multiMatcherCollection.push_back(Matcher(referencePolygon, polygon));
}