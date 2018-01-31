/* Name: Steven Santana
   Course: {135 Shankar, 136}
   Instructor: X. Zhang
   Assignment: Proj 3
*/
#ifndef THEBAD_H
#define THEBAD_H

#include<iostream>
#include<cstdlib>
using namespace std;

//Exception helper
class BadYear {
	public :
		BadYear() {}
		BadYear(int y): year(y) {}
		int getYear() const;
	private:
		int year;
}; 
//Exception helper
class BadMonth {
	public :
		BadMonth() {}
		BadMonth(int m): month(m) {}
		int getMonth() const;
	private:
		int month;
};
//Exception helper
class BadDay {
	public :
		BadDay() {}
		BadDay(int d): day(d) {}
		int getDay() const;
	private:
		int day;
};
#endif
