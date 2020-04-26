//
//  main.cpp
//  TDDLines
//
//  Created by Samuel Santiago on 4/26/20.
//  Copyright © 2020 Samuel Santiago. All rights reserved.
//

#include <iostream>
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "line.hpp"
#include "point.hpp"

using namespace std;

TEST_CASE("Line Test") {
    
    Point p1(1.2, 2.4);
    
    REQUIRE(p1.getCoordinates() == "X:1.2 Y:2.4");
    
};

