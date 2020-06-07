#ifndef _MULTIMATCHER_H_
#define _MULTIMATCHER_H_

#include <vector>
#include "Matcher.h"
#include "Polygon.h"

class MultiMatcher
{
    private:
    std::vector<Matcher> multiMatcherCollection;
    Polygon referencePolygon;
    int polygonCounter = 0;

    public:
    MultiMatcher() {}
    void SetReference(const Polygon& reference);
    void AddPolygon(const Polygon& polygon);
    void PopPolygon();
    std::vector<double> Process() const;
    
    
    int GetPolygonCount() const {return polygonCounter;}
};

#endif