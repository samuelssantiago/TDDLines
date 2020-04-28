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

    if (x < 0.0 || y < 0.0)
    {
        throw "Uh Oh. Can not have points in the negative quadrants.";
    }
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
    stringstream temp;
    temp << xVal;
    return temp.str();


}

string Point::getYString()
{
    stringstream temp;
    temp << yVal;
    return temp.str();

}

