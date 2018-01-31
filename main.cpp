/* Name: Steven Santana
   Course: {135 Shankar, 136}
   Instructor: X. Zhang
   Assignment: Proj 3
*/	
/*

I) DESIGN DECISIONS
--------------------
1) Made classes for exception handling, listed in theBad.cpp/theBad.h

2)No error handling on inputs, constructors already take care of invalid entries.

	
*/
#include<iostream>
#include<cstdlib>
#include<string>

#include "Date.h"
#include "Holidays.h"
using namespace std;


//Date prototypes were here


//holidays proto was here

int main() {
	// sec 1
	int y, m, d;
	cout << "\nEnter year (1901 or later): ";
	cin >> y;
	cout << "\nEnter month (1-12): ";
	cin >> m;
	cout << "\nEnter day (1-31): ";
	cin >> d;
	
	Date currentDate(y, m, d);
	Holidays thisYear(y);
	
	// sec 2
	thisYear.setBirthday();
	
	//sec 3
	thisYear.declareHolidays();
	
	//sec 4
	thisYear.nextHoliday(currentDate);

}
