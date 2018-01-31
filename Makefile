all: theBad Date Holidays main link

theBad: theBad.cpp
	g++ -o theBad.o -c theBad.cpp
Date: Date.cpp
	g++ -o Date.o -c Date.cpp
Holidays: Holidays.cpp
	g++ -o Holidays.o -c Holidays.cpp
main: main.cpp
	g++ -o main.o -c main.cpp
link: theBad.o Date.o main.o
	g++ -o project3 theBad.o Date.o Holidays.o main.o
clean:
	rm link
