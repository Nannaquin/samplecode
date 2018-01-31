/* Name: Steven Santana
   Course: {135 Shankar, 136}
   Instructor: X. Zhang
   Assignment: Proj 3
*/
#ifndef HOLIDAYS_H
#define HOLIDAYS_H

#include<iostream>
#include<cstdlib>

#include "Date.h"
using namespace std;

class Holidays {
	public:
		Holidays(int y);
		void setBirthday();
		void declareHolidays();
		void nextHoliday (Date inDate);
	
	private:
		int year;
		
		Date* tDay; // Thanksgiving
		Date* iDay; // Independence Day
		Date* sDay; // School Day
		Date* bDay;	// birthday
};

#endif
