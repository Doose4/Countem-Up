#include <iostream>


class GroceryCounter {
private:
	int tens;
	int ones;
	int tenths;
	int hundredths;
	int overflows;

public:
	explicit GroceryCounter();
	void tens_button(int times_hit = 1);
	void ones_button(int times_hit = 1);
	void tenths_button(int times_hit = 1);
	void hundredths_button(int times_hit = 1);
	void total();
	void number_of_overflows();
	void clear();
};