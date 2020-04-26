//
//  point.cpp
//  TDDLines
//
//  Created by Samuel Santiago on 4/26/20.
//  Copyright © 2020 Samuel Santiago. All rights reserved.
//

#include "point.hpp"
#include <string>
#include <sstream>

using namespace std;

Point::Point(double x, double y){
    setCoordinates(x, y);
};

void Point::setCoordinates(double x, double y){
    xVal = x;
    yVal = y;
};

string Point::getCoordinates(){
    
    
    return "X:" + getXString() +" , Y:" + getYString();
}

string Point::getXString()
{
    string retVal = to_string(xVal);
    return retVal;


}

string Point::getYString()
{
    string retVal = to_string(yVal);
    return retVal;

}

