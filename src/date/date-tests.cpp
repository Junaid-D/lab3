#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Exercise 2.1
// COMMENT OUT THIS TEST AFTER INSPECTING THE OUTPUT 
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!
/*TEST_CASE("Date has uninitialised state") {	 
    // make a prior memory allocations - which will be the case in a typical program
	auto str = "hello"s;	
    
    Date today;	// rather use: auto today = Date{}; not used here to illustrate the issue
    std::cout << "Today is: " << endl;
    printDate(today);
}*/

/* The above printed out Today is:
0/1233255339/169 
If the default constructor were properly implemented, There would likely be some malformed date exception thrown
*/


TEST_CASE("Valid Date is initialised correctly") {
	auto heritage_day = Date{24, Month::September, 2000};
	CHECK(heritage_day.day() == 24);
	CHECK(heritage_day.month() == Month::September);
	CHECK(heritage_day.year() == 2000);
}


// Exercise 2.2
TEST_CASE("Creating Negative Year Throws Exception") {
    CHECK_THROWS_AS((Date{1,Month::September,-2000}),NonExistentYear);
}


TEST_CASE("Creating Out Of Range Day Throws Exception") {
    CHECK_THROWS_AS((Date{-4,Month::September,2000}),NonExistentDay);
    CHECK_THROWS_AS((Date{29, Month::February, 2001}), NonExistentDay);
    CHECK_NOTHROW((Date{29, Month::February, 2004}));// a leap year
}


// Exercise 2.3
//the equality is expected to evaluate to false if any one of the three member variables is unequal
TEST_CASE("Identical Dates are Equal") {
    auto date_1 = Date{1, Month::January, 2000};
    auto date_2 = Date{1, Month::January, 2000};

    CHECK(date_1 == date_2);
}

TEST_CASE("Differing Months Are Unequal") {
    auto date_1 = Date{1, Month::February, 2000};
    auto date_2 = Date{1, Month::January, 2000};

    CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Differing Days Are Unequal") {
    auto date_1 = Date{2, Month::January, 2000};
    auto date_2 = Date{1, Month::January, 2000};

    CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Differing Years Are Unequal") {
    auto date_1 = Date{1, Month::January, 2001};
    auto date_2 = Date{1, Month::January, 2000};

    CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Differing Date and Month Are Unequal") {
    auto date_1 = Date{1, Month::January, 2000};
    auto date_2 = Date{2, Month::February, 2000};

    CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Differing Date and Year Are Unequal") {
    auto date_1 = Date{1, Month::January, 2000};
    auto date_2 = Date{2, Month::January, 2001};

    CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Differing Year and Month Are Unequal") {
    auto date_1 = Date{1, Month::January, 2000};
    auto date_2 = Date{1, Month::February, 2001};

    CHECK_FALSE(date_1 == date_2);
}
TEST_CASE("Completely Different Are Unequal") {
    auto date_1 = Date{2, Month::February, 2001};
    auto date_2 = Date{1, Month::January, 2000};

    CHECK_FALSE(date_1 == date_2);
}


// Exercise 2.4

TEST_CASE("Increasing is Succesful When It does not Flow into a New Month/Year") {
    auto date_1 = Date{28, Month::February, 2004};
    date_1.increaseDate();
    CHECK(date_1 == (Date{29, Month::February, 2004}));
}

TEST_CASE("Increasing is Succesful at The End of Feb-Leap Year") {
    auto date_1 = Date{29, Month::February, 2004};
    date_1.increaseDate();
    CHECK(date_1 == (Date{1, Month::March, 2004}));
}


TEST_CASE("Increasing is Succesful When It Flows into a New Month, But not a new Year") {
    auto date_1 = Date{31, Month::January, 2001};
    date_1.increaseDate();
    CHECK(date_1 == (Date{1, Month::February, 2001}));
}

TEST_CASE("Increasing is Succesful When It Flows into a new Year") {
    auto date_1 = Date{31, Month::December, 2001};
    date_1.increaseDate();
    CHECK(date_1 == (Date{1, Month::January, 2002}));
}



// Exercise 2.5
TEST_CASE("Default Date is 1, Month::January, 1900") {
    auto def = Date{};
    auto testDate=Date{1, Month::January, 1900};
    CHECK(def==testDate);
    // the == operator has already been tested
}

TEST_CASE("SetDefaultDate allows the default date to change") {
    Date::setDefaultDate(1,Month::July,2008);
    auto def = Date{};
    CHECK(def==Date{1,Month::July,2008});
}



//test the exceptions thrown by setdefaultdate

TEST_CASE("Setting Default Year as Negative throws Exception") {
    CHECK_THROWS_AS(Date::setDefaultDate(1,Month::January,-1),NonExistentYear);
}

TEST_CASE("Setting Default Day as Out of Range Throws Exception") {
    CHECK_THROWS_AS(Date::setDefaultDate(-4,Month::September,2000),NonExistentDay);
    CHECK_THROWS_AS(Date::setDefaultDate(29, Month::February, 2001), NonExistentDay);
    CHECK_NOTHROW(Date::setDefaultDate(29, Month::February, 2004));// a leap year
}

TEST_CASE("Creating a default, changing the default date, does not change the original") {
   auto def1=Date{};
   Date::setDefaultDate(1,Month::July,2008);
   CHECK_FALSE(def1==(Date{1,Month::July,2008}));
    
}
