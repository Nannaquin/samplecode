/* Name: Steven Santana
   Course: {135 Shankar, 136}
   Instructor: X. Zhang
   Assignment: Proj 3
*/
#include<iostream>
#include<cstdlib>
#include "theBad.h"
using namespace std;

// Error Checking functions for the corresponding private members of Date.
int BadYear::getYear() const { return year; }
			
int BadMonth::getMonth() const { return month; }

int BadDay::getDay() const { return day; }
