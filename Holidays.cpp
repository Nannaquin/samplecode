/* Name: Steven Santana
   Course: {135 Shankar, 136}
   Instructor: X. Zhang
   Assignment: Proj 3
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include "Holidays.h"
#include "Date.h"
using namespace std;


Holidays::Holidays(int y) {

	
	year = y;
	tDay = new Date(y, 11, 4, 4);
	iDay = new Date(y, 7, 4);
	sDay = new Date(y, 8, 1, -1);

	return;
}

void Holidays::setBirthday() {
	int y, m, d;
	
	cout << endl;
	cout << "\nEnter birth year (1901 or later): ";
	cin >> y;
	cout << "\nEnter birth month (1-12): ";
	cin >> m;
	cout << "\nEnter birth day (1-31): ";
	cin >> d;
	
	bDay = new Date(year, m, d);
	return;
}

void Holidays::declareHolidays() {
	
	cout << "Independence Day will occur on " << *iDay << ", which is day " << iDay->modernTime() << " in modern time." << endl;
	cout << "School Day will occur on " << *sDay << ", which is day " << sDay->modernTime() << " in modern time." << endl;
	cout << "Thanksgiving will occur on " << *tDay << ", which is day " << tDay->modernTime() << " in modern time." << endl;
	cout << "Your birthday will occur on " << *bDay << ", which is day " << bDay->modernTime() << " in modern time." << endl;
	
	return;
}

void Holidays::nextHoliday(Date inDate) {
	
	int y;
	if((inDate.getMonth() > 11)||
	((inDate.getMonth()>tDay->getMonth())&&(inDate.getDay()>tDay->getDay()))) { y  = year + 1; }
	else y = year;
	
	Date dateHold[4];
	
	dateHold[0] = Date(y, 11, 4, 4);
	dateHold[1] = Date(y, 7, 4);
	dateHold[2] = Date(y, 8, 1, -1);
	dateHold[3] = Date(y, bDay->getMonth(), bDay->getDay());
	
	string nHold[4] = {"Thanksgiving", 
					"Independence Day", 
					"School Day", 
					"Your Birthday" };
	int j; 
	Date temp;
	string str;
		
	for (int i = 0; i < 4; i++){
		j = i;
		
		while ((j > 0) && (dateHold[j].modernTime() - inDate.modernTime() < dateHold[j-1].modernTime() - inDate.modernTime())){
			  temp = dateHold[j];
			  str = nHold[j];
			  
			  dateHold[j] = dateHold[j-1];
			  nHold[j] = nHold[j-1];
			  
			  dateHold[j-1] = temp;
			  nHold[j-1] = str;
			  j--;
			  }
		}
   
   cout << "The next holiday is " << nHold[0] << ", on " << dateHold[0] <<
    ", which is in " << dateHold[0].modernTime() - inDate.modernTime() << " days!" << endl;
   
	return;	
}
