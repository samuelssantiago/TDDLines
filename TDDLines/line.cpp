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
    if (ip2.getXCoord() < ip1.getXCoord())
    {
        point1 = ip2;
        point2 = ip1;
    }
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
    //y = mx + b
    double mx = slope * point1.getXCoord();
    return point1.getYCoord() - mx;

}

bool Line::isOnLine(Point p)
{
    bool retVal = false;
    double ytemp = slope * p.getXCoord() + yIntercept;
    //double deleteme = p.getYCoord();
    double tester = abs(ytemp - p.getYCoord());
    
    if (p.getXCoord() >= point1.getXCoord() && p.getXCoord() <= point2.getXCoord())
    {
        
        double max_y = max(point1.getYCoord(), point2.getYCoord());
        double min_y = min(point1.getYCoord(), point2.getYCoord());
        if (p.getYCoord() >= min_y && p.getYCoord() <= max_y)
        {
            if (tester <= 0.000000001)
            {
                retVal = true;
            }
        }
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


    //line 1
    //slope1*x + yIntercept1 = slope2*x + yIntercept2

    double deleteme = l.yIntercept;
    
    double slopeTemp = slope - l.slope;
    double ytemp = l.yIntercept - yIntercept;
    double intersect = ytemp / slopeTemp;

    double y = slope * intersect + yIntercept;
    Point temp(intersect, y);
    


    if (isOnLine(temp) && l.isOnLine(temp))
    {
        retVal = true;
    }
    

    return retVal;
}
