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

TEST_CASE("Point Test") {
    
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

    double d3 = 3.8;
    double d4 = 1.9;
    Point p2(d3,d4);

    REQUIRE(p2.getXCoord() == d3);
    REQUIRE(p2.getYCoord() == d4);

    string test = "X:" + p1.getXString() + " , Y:" + p1.getYString();
    REQUIRE(test == p1.getCoordinates());
    
};

TEST_CASE("Line Tests")
{

    Point p11(1.2, 1.4);
    Point p12(3.7, 2.5);
    Line l1(p11,p12);
    Point testpoint = l1.getPoint1();
    Point testpoint2 = l1.getPoint2();
    REQUIRE(testpoint.getCoordinates() == p11.getCoordinates());
    REQUIRE(testpoint2.getCoordinates() == p12.getCoordinates());
    
    Point lengthP1(1,1);
    Point lengthP2(1,3);
    Line ln(lengthP1,lengthP2);
    REQUIRE(ln.length() == 2.0);

    Point lengthP3(1,1);
    Point lengthP4(1,2);
    Line ln2(lengthP3,lengthP4);
    REQUIRE(ln2.length() == 1.0);
};

