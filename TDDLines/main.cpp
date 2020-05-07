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

    Point lengthP5(1, 1);
    Point lengthP6(3, 3);
    Line ln3(lengthP5, lengthP6);
    REQUIRE(ln3.generateSlope() == 1);
    REQUIRE(ln3.generateYIntercept() == 0);

    Point lengthP7(2, 2);
    Point lengthP8(7, 8);
    Point length9(4, 4);
    Point test_same(3, 3);
    Point test_fail(3, 2.999999);
    REQUIRE(ln3.isOnLine(lengthP7));
    REQUIRE(ln3.isOnLine(lengthP6));
    REQUIRE(!ln3.isOnLine(lengthP8));
    REQUIRE(!ln3.isOnLine(length9));
    REQUIRE(ln3.isOnLine(test_same));
    REQUIRE(!ln3.isOnLine(test_fail));
    
    Point p13(2,2);
    Point p14(4,4);
    Line par(p13,p14);
    REQUIRE(par.isParrallel(ln3));


    Point p15(1, 1);
    Point p16(3, 3);
    Point p17(2, 2);
    Point p18(1, 1);
    Line intersect(p15, p16);
    Line intersect2(p17, p18);
    REQUIRE(!intersect.isIntersecting(intersect2));
    
    Point p19(2, 2);
    Point p20(5, 3);
    Point p21(2, 2);
    Point p22(0, 10);
    Line intersect3(p19, p20);
    Line intersect4(p21, p22);
    REQUIRE(intersect3.isIntersecting(intersect4));


    Point p23(15,10);
    Point p24(49, 25);
    Point p25(29,5);
    Point p26(32, 32);
    Line intersect5(p23, p24);
    Line intersect6(p25, p26);
    REQUIRE(intersect5.isIntersecting(intersect6));


    Point p27(2, 3);
    Point p28(1, 4);
    Point p29(5, 7);
    Point p30(10, 9);
    Line intersect7(p27, p28);
    Line intersect8(p29, p30);
    REQUIRE(!intersect7.isIntersecting(intersect8));

};

