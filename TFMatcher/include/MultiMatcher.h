#ifndef _MULTIMATCHER_H_
#define _MULTIMATCHER_H_

#include <vector>
#include "Matcher.h"
#include "Polygon.h"

class MultiMatcher
{
    private:
    Polygon referencePolygon;
    int polygonCounter = 0;

    public:
    MultiMatcher() {}
    void SetReference(const Polygon& reference);
    void AddPolygon(const Polygon& polygon);
    void PopPolygon();
    std::vector<double> virtual Process() const;
    
    int GetPolygonCount() const {return polygonCounter;}

    protected:
    std::vector<Matcher> multiMatcherCollection;
};

class MultiMatcherParallel : public MultiMatcher
{
    public:
    std::vector<double> virtual Process() const;
};

#endif