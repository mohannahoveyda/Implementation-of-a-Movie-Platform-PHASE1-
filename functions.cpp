#include "functions.h"

int stooi(string text){
	string rest=text;
	int number=0;
	for(int i=0;i<text.length();i++){
		 if( text.substr(i,1)=="0" ){ number+=0;}
		 if( text.substr(i,1)=="1" ){ number+=1;}
		 if( text.substr(i,1)=="2" ){ number+=2;}
		 if( text.substr(i,1)=="3" ){ number+=3;}
		 if( text.substr(i,1)=="4" ){ number+=4;}
		 if( text.substr(i,1)=="5" ){ number+=5;}
		 if( text.substr(i,1)=="6" ){ number+=6;}
		 if( text.substr(i,1)=="7" ){ number+=7;}
		 if( text.substr(i,1)=="8" ){ number+=8;}
		 if( text.substr(i,1)=="9" ){ number+=9;}
		 number*=10;
	}
	return number/10;
}
float stoof(string text){
	int i=text.find(".");
	int ad=0;
	int ash=0;
	string adad=text.substr(0,i);
	string ashar;
	ad=stoi(adad);
	if( text.find(".")!=string::npos ){
		ashar=text.substr(i+1);
		ash=stoi(ashar);
	}
	int l=ashar.length();
	float mynum;
	mynum=ad+ ash*pow(  10,-l  );
	return mynum;
}
string nospace(string mystring){
	string rest=mystring;
	int i;
	bool flag=true;
	while(flag){
		i=rest.find(" ");
		if(rest.find(" ")==string::npos){ flag=false;
		}
		if(flag){rest= rest.substr(0,i) + rest.substr(i+1);}
	}
	return rest;
}

string RSHash(string str )
{
   int b    = 378551;
   int a    = 63689;
   int hash = 0;
   int i    = 0;
   for (i = 0; i < str.length(); i++)
   {
      hash = hash * a + str.at(i);
      a    = a * b;
   }
   return to_string(hash);
}
