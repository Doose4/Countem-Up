#include <iostream>


class GroceryCounter {
private:
	int tensmax = 9;
	int onesmax= 9;
	int tenthsmax = 9;
	int hundmax = 9;
	int tens;
	int ones;
	int tenths;
	int hundredths;
	int overflows;

public:
	explicit GroceryCounter(int startingnum = 0, int custommax = 0);
	void tens_button(int times_hit = 1);
	void ones_button(int times_hit = 1);
	void tenths_button(int times_hit = 1);
	void hundredths_button(int times_hit = 1);
	void total();
	void number_of_overflows();
	void clear();
	void decr_tens_button(int times_hit = 1);
	void decr_ones_button(int times_hit = 1);
	void decr_tenths_button(int times_hit = 1);
	void decr_hundredths_button(int times_hit = 1);
};