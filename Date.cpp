/* Name: Steven Santana
   Course: {135 Shankar, 136}
   Instructor: X. Zhang
   Assignment: Proj 3
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include "Date.h"
#include "theBad.h"
using namespace std;

string Date::mArr[] = { "January", "February", "March",
						"April", "May", "June",
						"July", "August", "September",
						"October", "November", "December"};

int Date::daysArr[] = { 31,28,31,
					30,31,30,
					31,31,30,
					31,30,31 };
					
string Date::wArr[] = { "Sun", "Mon", "Tues", "Wed", "Thu", "Fri", "Sat" };

//THE FUNCTIONS
//-------------

//Literally nothing. Used for sorting temporary Dates
Date::Date() {
	//literally nothing
	//For the case of sorting with some temp business.	
}


//Normal Constructor
//Precondition: Integers representing the year, month, and day have been supplied.
//Postcondition: A valid Date object is created.
Date::Date(int y, int m, int d) {
	
	// If illegal date, exit(1) ??
	try {
		
		if (y < 1901) { throw BadYear(y); }
		else { 
			year = y;
			isLeapYear = isLeap(year);
		}
		
		if ((m < 1) || (m > 12)) { throw BadMonth(m); }
		else month = m;
		
		int dayCap;
		if((month == 2) && (isLeapYear == true)) { dayCap = 29; }
		else dayCap = daysArr[month-1];

		if ((d < 1) || (d > dayCap)) { 
			if ((month == 2) && (isLeapYear == false) && (d == 29)) { day = 28; }
			else { throw BadDay(d); }
		}
		else { day = d; }
		
	}
	catch(BadYear e) {
		cerr << e.getYear() << " is not a valid year!" << endl;
		exit(1);
	}
	catch(BadMonth e) {
		cerr << e.getMonth() << " is not a valid month!" << endl;
		exit(1);
	}
	catch(BadDay e) {
	cerr << e.getDay() << " is not a valid day!" << endl;
	exit(1);
	}
	
	
}


/*Creates a date with the info specified, but on the num'th day 
of the week (specified by weekDay). */
//Precondition: Integers corresponding to year, and month, weekDay and num have
//been supplied.
//Postcondition: A valid date has been created.
Date::Date(int y, int m, int weekDay, int num) {
	
/* if num == -1, means find last day

*/
	
	// If illegal date, exit(1) ??
	try {
		
		if (y < 1901) { throw BadYear(y); }
		else { 
			year = y;
			isLeapYear = isLeap(year);	
		}
		
		if ((m < 1) || (m > 12)) { throw BadMonth(m); }
		else month = m;
		

	}
	catch(BadYear e) {
		cerr << e.getYear() << " is not a valid year!" << endl;
		exit(1);
	}
	catch(BadMonth e) {
		cerr << e.getMonth() << " is not a valid month!" << endl;
		exit(1);
	}
	
	
	//IF ALL IS WELL ABOVE, THEN...
	
	int yDays = Date::getYearToDays(1901, year);

	int mDays = Date::getMonthToDays(month) - Date::getMonthToDays(1);

	// Jumping off point;
	int start = yDays + mDays + 2; // 01/01/1901 was a Tuesday, hence 2 out of 0 to 6, inclusive;
	
	while (start >= 7) {
		start -= 7;
	}

	//Figure out how many of each week day in this month.
	int wHold[7] = {0, 0, 0, 0, 0, 0, 0};

	// day by day count # of week days til end of month. backtrack and retrieve desired date  
	int i = 0;
	if(num != -1) {
		while (i < daysArr[month-1]) {
			
			wHold[start]++;	
			
			if((start == weekDay) && (wHold[weekDay] == num)) {

				day = i + 1;
				break;
			}

			
			start++;
			i++;
			if(start > 6) start = 0;
			
			
		}
	}
	else if (num == -1) {
		while (i < daysArr[month-1]) {
			
			wHold[start]++;	

			if((start == weekDay) && (daysArr[month-1] - i < 7 )) {

				day = i + 1;
				break;
			}
			
			start++;
			i++;
			if(start > 6) start = 0;
			
			
		}
	}
}
//Determines if the given year of a date is a leap year
//Precondition: The supplied year is valid.
//Postcondition: A boolean result is returned.
bool Date::isLeap(int year) {
	bool leapStatus = false;
	
	if(year%4 != 0) { leapStatus = false; }
	else if(year%100 != 0) { leapStatus = true; }
	else if(year%400 != 0) { leapStatus = false; }
	else leapStatus = true;
	
	return leapStatus;
}

//Precondition: A valid Date is created.
//Postcondition: The Date's year is returned.
int Date::getYear() const {
	return year;
}

//Precondition: A valid Date is created.
//Postcondition: The Date's month is returned.
int Date::getMonth() const {
	return month;
}

//Precondition: A valid Date is created.
//Postcondition: The Date's day is returned.
int Date::getDay() const {
	return day;
}


//Precondition: A valid Date is created.
//Postcondition: The Date's month's name is returned.
string Date::getMonthName() const {
	return mArr[month - 1];
}

//Precondition: A valid Date is created.
//Postcondition: The Date's day's name is returned.
string Date::getDayName() {
	Date date(year, month, day);
	int daysHold = date.modernTime();
	int holder = 0;
	
	holder += daysHold + 2;
	
	while (holder >= 7) {
		holder -= 7;
	}
	
	return wArr[holder];
}


//Precondition: Two valid years (y > 1901) are supplied.
//Postcondition: The difference between the two years, in days, is returned.
int Date::getYearToDays(int y1, int y2) {
	int tempYrs = y2 - y1;
	int retDays = 0;
	
	int dispDays;
	for (int i = y1+1; i <= y2; i++) {
		
		if(i%4 != 0) { retDays += 365; dispDays = 365; }
		else if(i%100 != 0) { retDays += 366; dispDays = 366; }
		else if(i%400 != 0) { retDays += 365; dispDays = 365;}
		else { retDays += 366; dispDays = 366; }
	
	}
	return retDays;
}


//Precondition: A valid month (1 <= m <= 12) is supplied.
//Postcondition: The amount of days in the supplied month is returned.
int Date::getMonthToDays(int m) {
	int retDays = 0;
	for (int i = 1; i < m; i++) {
		retDays += daysArr[i-1];
	}
	return retDays;
}

//Creates a value referred to as "modern time".
//Precondition: A valid date was created.
//Postcondition: Returns the amount of days since Jan 1st 1901
unsigned int Date::modernTime() {
	//d1 here is 01/01/1901
	int yDays = Date::getYearToDays(1901, year);
	int mDays = Date::getMonthToDays(month) - Date::getMonthToDays(1);
	int dDiff = day - 1;

	int fDays = yDays + mDays + dDiff;

	return fDays;
}

//Precondition: A valid date is supplied.
//Postcondition: The date is printed as a sentence.
ostream& operator <<(ostream& os, const Date& date) {
	string outMonth;
	outMonth = date.getMonthName();
	
	os << outMonth << " " << date.getDay() << ", " << date.getYear(); 

	return os;
}


//Precondition: d2 is the later date than d1
//Postcondition: The difference between the two dates in days is returned.
const int operator -(const Date& d1, const Date& d2) {
	
	int yearDays =  Date::getYearToDays(d1.getYear(), d2.getYear());
	
	int monthDays = Date::getMonthToDays(d2.getMonth()) - Date::getMonthToDays(d1.getMonth());
	
	int daysDiff = d2.getDay() - d1.getDay();

	int finalDays = yearDays + monthDays + daysDiff;
	

	return finalDays;
}
