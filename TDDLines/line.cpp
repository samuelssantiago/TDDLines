//
//  line.cpp
//  TDDLines
//
//  Created by Samuel Santiago on 4/26/20.
//  Copyright © 2020 Samuel Santiago. All rights reserved.
//

#include "line.hpp"

Line::Line(Point ip1, Point ip2)
:point1(ip1),point2(ip2)
{

}

Point Line::getPoint1()
{
    return point1;
}
Point Line::getPoint2()
{
    return point2;
}
