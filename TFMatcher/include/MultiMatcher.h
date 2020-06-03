#ifndef _MULTIMATCHER_H_
#define _MULTIMATCHER_H_

#include <vector>
#include "Matcher.h"
#include "Polygon.h"

class MultiMatcher
{
    private:
    vector<Matcher> multiMatcherCollection;
    int polygonCounter = 0;

    public:
    MultiMatcher() {}
    void AddPolygon(const Polygon& polygon);
    void PopPolygon();
    void RemovePolygon(int index);
    
    int GetPolygonCount() const {return polygonCounter;}
};

#endif