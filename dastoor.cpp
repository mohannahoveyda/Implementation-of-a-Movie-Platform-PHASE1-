#include "dastoor.h"

		dastoor :: dastoor(){
			int price=-1;
			name="";
			min_year=-1;
			max_year=1000000;
			length=-1;
			min_rate=-1;
			summary="";
			director="";
			is_publisher=false;
		}
		
		int dastoor :: get_price(){return price;}
		string dastoor :: get_name(){return name;}
		int dastoor :: get_min_year(){return min_year;}
		int dastoor :: get_max_year(){return max_year;}
		int dastoor :: get_length(){return length;}
		float dastoor :: get_min_rate(){return min_rate;}
		string dastoor :: get_summary(){return summary;}
		string dastoor :: get_director(){return director;}
		bool dastoor :: get_is_publisher(){return is_publisher;}
		////////
		void dastoor :: set_price(int p){price=p;}
		void dastoor :: set_name(string s){name=s;}
		void dastoor :: set_min_year(int y){min_year=y;}
		void dastoor :: set_max_year(int y){max_year=y;}
		void dastoor :: set_length(int y){length=y;}
		void dastoor :: set_min_rate(float f){min_rate=f;}
		void dastoor :: set_summary(string s){summary=s;}
		void dastoor :: set_director(string s){director=s;}
		void dastoor :: set_is_publisher(){is_publisher=true;}