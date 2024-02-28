#include "Class.hpp"
#include <iostream>

using namespace std;

GroceryCounter::GroceryCounter() {
	tens = 0;
	ones = 0;
	tenths = 0;
	hundredths = 0;
	overflows = 0;
}

void GroceryCounter::tens_button(int times_hit) {
	tens = tens + times_hit;
	
	while (tens > 9)
	{
		tens = tens - 10;
		overflows++;
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
