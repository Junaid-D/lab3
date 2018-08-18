#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Exercise 2.1
// COMMENT OUT THIS TEST AFTER INSPECTING THE OUTPUT 
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!
TEST_CASE("Date has uninitialised state") {	 
    // make a prior memory allocations - which will be the case in a typical program
	auto str = "hello"s;	
    
    Date today;	// rather use: auto today = Date{}; not used here to illustrate the issue
    std::cout << "Today is: " << endl;
    printDate(today);
}

// Write code to make this test pass
//TEST_CASE("Valid Date is initialised correctly") {
//	auto heritage_day = Date{24, Month::September, 2000};
//	CHECK(heritage_day.day() == 24);
//	CHECK(heritage_day.month() == Month::September);
//	CHECK(heritage_day.year() == 2000);
//}


// Exercise 2.2
// Supply additional tests for the constructor here, which
// verify that an exception is thrown when an attempt is made
// to construct an invalid date. Think carefully about which
// invalid dates to test.


// Exercise 2.3
//TEST_CASE("Identical Dates are Equal") {
//    auto date_1 = Date{1, Month::January, 2000};
//    auto date_2 = Date{1, Month::January, 2000};
//
//    CHECK(date_1 == date_2);
//}

// Supply at least three additional tests for
// the equality operator here, to ensure that
// it is working correctly.


// Exercise 2.4
// Provide tests for a new member function of the Date class
// which will increase the date by one day.


// Exercise 2.5
// Write tests for the new default constructor and the
// setDefaultDate method.
