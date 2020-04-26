//
//  point.hpp
//  TDDLines
//
//  Created by Samuel Santiago on 4/26/20.
//  Copyright © 2020 Samuel Santiago. All rights reserved.
//

#pragma Once

#include <stdio.h>
#include <string>

using namespace std;

class Point{
private:
    double xVal;
    double yVal;
    
public:
    void setCoordinates(double x, double y);
    string getCoordinates();
    Point(double x, double y);
    string getXString();
    string getYString();



};
