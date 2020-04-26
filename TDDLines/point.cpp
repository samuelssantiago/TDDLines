//
//  point.cpp
//  TDDLines
//
//  Created by Samuel Santiago on 4/26/20.
//  Copyright © 2020 Samuel Santiago. All rights reserved.
//

#include "point.hpp"
#include <string>

using namespace std;

Point::Point(double x, double y){
    setCoordinates(x, y);
};

void Point::setCoordinates(double x, double y){
    xVal = x;
    yVal = y;
};

string Point::getCoordinates(){
    string retString;
    string x = to_string(xVal);
    string y = to_string(yVal);
    
    retString = "X:" + x + " " + "Y:" + y;
    
    return retString;
}

