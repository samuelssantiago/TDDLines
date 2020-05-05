//
//  line.cpp
//  TDDLines
//
//  Created by Samuel Santiago on 4/26/20.
//  Copyright © 2020 Samuel Santiago. All rights reserved.
//

#include "line.hpp"
#include <math.h>
Line::Line(Point ip1, Point ip2)
:point1(ip1),point2(ip2)
{
    slope = generateSlope();
    yIntercept = generateYIntercept();
}

Point Line::getPoint1()
{
    return point1;
}
Point Line::getPoint2()
{
    return point2;
}
double Line::length()
{
    return sqrt(pow(point1.getYCoord() - point2.getYCoord(),2) + pow(point1.getXCoord() - point2.getXCoord(),2));
}

double Line::generateSlope()
{
    return (point1.getYCoord() - point2.getYCoord()) / (point1.getXCoord() - point2.getXCoord());
}

double Line::generateYIntercept()
{
    //   y = mx + b
    double mx = slope * point1.getXCoord();
    return point1.getYCoord() - mx;

}

bool Line::isOnLine(Point p)
{
    bool retVal = false;
    if (p.getYCoord() == slope * p.getXCoord() + yIntercept)
    {
        retVal = true;
    }

    return retVal;
}

bool Line::isParrallel(Line l)
{
    if (abs(slope - l.slope) < .000001)
    {
        return true;
    }
    return false;
}


bool Line::isIntersecting(Line l)
{

    bool retVal = false;

    if (isParrallel(l))
    {
        //
    }
    else if (isOnLine(l.getPoint1()) || isOnLine(l.getPoint2()))
    {
        retVal = true;
    }




    return retVal;
}
