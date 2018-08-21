#ifndef DATE_H
#define DATE_H
// date.h
// class Date declaration

#include <cassert>
#include <iostream>
using namespace std;
class NonExistentDay{};
class NonExistentYear{};
enum class Month 
{
	January, 
	February,
	March, 
	April,
	May,
	June,
	July, 
	August, 
	September,
	October,
	November, 
	December
};
	
class Date
{
public:	
	// return the day of the month
    
    Date(int day,Month month,int year);
    Date();
    static void setDefaultDate(int day, Month month, int year);
	int	day () const;
	// return the month of the year
	Month month () const;
	// return the year
	int year () const;
	// return true if it is a leap-year, false if not
	bool isLeapYear () const;	
    bool operator==(const Date& rhs) const;
    void increaseDate();

private:
	// return the number of days in the month_
	int	daysInMonth () const;	
	
	int	day_;
	Month month_;
	int	year_;
    static Date default_;

};

// standalone function for printing the date
void printDate(const Date& date);

#endif