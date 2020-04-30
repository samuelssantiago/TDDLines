//
//  line.hpp
//  TDDLines
//
//  Created by Samuel Santiago on 4/26/20.
//  Copyright © 2020 Samuel Santiago. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "point.hpp"

class Line
{

    Point point1;
    Point point2;
    double slope;
    double yIntercept;

    public:

    Line(Point ip1, Point ip2);
    Point getPoint1();
    Point getPoint2();
    double length();
    double generateSlope();
    double generateYIntercept();
    bool isOnLine(Point p);
};

