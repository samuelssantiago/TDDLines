//
//  main.cpp
//  TDDLines
//
//  Created by Samuel Santiago on 4/26/20.
//  Copyright © 2020 Samuel Santiago. All rights reserved.
//

#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "line.hpp"
#include "point.hpp"

using namespace std;

TEST_CASE("Line Test") {
    
    Point p1(1.2, 2.4);
    double d1 = 1.2;
    double d2 = 2.4;
    stringstream point;
    point << d1;
    REQUIRE(p1.getXString() == point.str());

    stringstream point2;
    point2 << d2;
    REQUIRE(p1.getYString() == point2.str());
    REQUIRE(p1.getXString() != point2.str());

    REQUIRE_THROWS(Point(-.6, 2.5));

    string test = "X:" + p1.getXString() + " , Y:" + p1.getYString();
    REQUIRE(test == p1.getCoordinates());
    
};

