#ifndef DASTOOR_H
#define DASTOOR_H
#include <iostream>
using namespace std;
class dastoor{
	private:
		int price;
		string name;
		int min_year;//year
		int max_year;
		int length;
		float min_rate;
		string summary;
		string director;
		bool is_publisher;
	public:
		dastoor();
		////////
		int get_price();
		string get_name();
		int get_min_year();
		int get_max_year();
		int get_length();
		float get_min_rate();
		string get_summary();
		string get_director();
		bool get_is_publisher();
		////////
		void set_price(int p);
		void set_name(string s);
		void set_min_year(int y);
		void set_max_year(int y);
		void set_length(int y);
		void set_min_rate(float f);
		void set_summary(string s);
		void set_director(string s);
		void set_is_publisher();
};
#endif