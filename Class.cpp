#include "Class.hpp"
#include <iostream>

using namespace std;

GroceryCounter::GroceryCounter(int startingnum, int custommax) {
	newmax = custommax;
	tens = 0;
	ones = 0;
	tenths = 0;
	hundredths = 0;
	overflows = 0;

	bool inprocess = true;
	while (inprocess)
	{
		if (startingnum < 10000 && startingnum > -1)
		{
			int divsor = startingnum / 1000;
			int remainder = startingnum % 1000;
			tens_button(divsor);
			divsor = remainder / 100;
			remainder = remainder % 100;
			ones_button(divsor);
			divsor = remainder / 10;
			remainder = remainder % 10;
			tenths_button(divsor);
			ones_button(remainder);
			inprocess = false;
		}
		else
		{
			cout << endl << "input was not vaild, please enter a number between 0 and 9999. " << endl;
			cin >> startingnum;
		}
	}
	
}

void GroceryCounter::tens_button(int times_hit) {
	tens = tens + times_hit;
	
	if (newmax == 0) {
		while (tens > 9)
		{
			tens = tens - 10;
			overflows++;
		}
	}
}

void GroceryCounter::ones_button(int times_hit) {
	ones = ones + times_hit;

	if(ones > 9)
	{
		tens_button(ones / 10);
		ones = ones % 10;
	}
}

void GroceryCounter::tenths_button(int times_hit) {
	tenths = tenths + times_hit;

	if (tenths > 9)
	{
		ones_button(tenths / 10);
		tenths = tenths % 10;
	}
}

void GroceryCounter::hundredths_button(int times_hit) {
	hundredths = hundredths + times_hit;

	if (hundredths > 9)
	{
		tenths_button(hundredths / 10);
		hundredths = hundredths % 10;
	}
}

void GroceryCounter::total() {
	int starting_number;
	if (tens <1)
	{
		starting_number = ones;
	}
	else {
		starting_number = (tens * 10) + ones;
	}

	cout << "$" << starting_number << "." << tenths << hundredths << endl;
}

void GroceryCounter::number_of_overflows() {
	cout << overflows << " overflows." << endl;
}

void GroceryCounter::clear() {
	tens = 0;
	ones = 0;
	tenths = 0;
	hundredths = 0;
	overflows = 0;
}


void GroceryCounter::decr_tens_button(int times_hit) {
	tens = tens - times_hit;

	if (newmax == 0) {
		while (tens < 0)
		{
			tens = tens + 10;
			overflows++;
		}
	}
}

void GroceryCounter::decr_ones_button(int times_hit) {
	ones = ones - times_hit;

	if (ones < 0)
	{
		ones = ones + 10;
		decr_tens_button(ones / 10);
		ones = ones % 10;
	}
}

void GroceryCounter::decr_tenths_button(int times_hit) {
	tenths = tenths - times_hit;

	if (tenths < 0)
	{
		tenths = tenths + 10;
		decr_ones_button(tenths / 10);
		tenths = tenths % 10;
	}
}

void GroceryCounter::decr_hundredths_button(int times_hit) {
	hundredths = hundredths - times_hit;

	if (hundredths < 0)
	{
		hundredths = hundredths + 10;
		decr_tenths_button((hundredths / 10)+1);
		hundredths = hundredths % 10;
	}
}