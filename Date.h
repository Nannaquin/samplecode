/* Name: Steven Santana
   Course: {135 Shankar, 136}
   Instructor: X. Zhang
   Assignment: Proj 3
*/
#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<cstdlib>
#include<string>
#include "Date.h"
using namespace std;

class Date {
	public:
		Date(); //Blank, does nothing
		Date(int y, int m, int d); // Outright defines the year, month, and date
		Date(int y, int m, int weekDay, int num); // Searches based upon the nth (n = num) day (day = weekDay) of the month
		bool isLeap(int year);
		int getYear() const;
		int getMonth() const;
		int getDay() const;

		string getMonthName() const;
		string getDayName();
		static int getYearToDays(int y1, int y2);
		static int getMonthToDays(int m);
		unsigned int modernTime();
		
		
	private:
		int year;
		int month;
		int day;
		
		bool isLeapYear;
		

		static string mArr[12];
		static int daysArr[12];
		static string wArr[7];
};

ostream& operator <<(ostream& os, const Date& date);

const int operator -(const Date& d1, const Date& d2);

#endif
