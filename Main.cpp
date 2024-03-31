#include "Class.hpp"
#include <iostream>

using namespace std;

void tester() {
	GroceryCounter counter = GroceryCounter();

	counter.total();

	counter.tens_button();
	counter.ones_button();
	counter.tenths_button();
	counter.hundredths_button();

	counter.total();

	counter.tens_button(5);
	counter.ones_button(4);
	counter.tenths_button(3);
	counter.hundredths_button(2);

	counter.total();

	counter.clear();

	counter.total();

	//has a starting num
	GroceryCounter startingnum = GroceryCounter(2000);
	startingnum.total();

	//has a starting num that isn't vaild
	GroceryCounter invalidcount = GroceryCounter(-100);
	invalidcount.total();

	//custom max
	GroceryCounter customMax = GroceryCounter(0,1000);
	customMax.total();
	customMax.ones_button(1);
	customMax.total();
	customMax.tens_button(1);
	customMax.total();
	customMax.ones_button(9);
	customMax.total();


	//both
	GroceryCounter bothcount = GroceryCounter(1789, 1890);
	bothcount.total();
	bothcount.tens_button(110);
	startingnum.total();

	//decrement
	startingnum.total();
	startingnum.decr_tens_button();
	startingnum.total();
	startingnum.decr_ones_button();
	startingnum.total();
	startingnum.decr_tenths_button();
	startingnum.total();
	startingnum.decr_hundredths_button();
	startingnum.total();

}

int main() {

	tester();

	return 0;
}