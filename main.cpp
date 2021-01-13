#include "netflix.h"
#include "film.h"
#include "user.h"
#include "publisher.h"
#include "comment.h"
#include "reply.h"
#include "functions.h"
#include "dastoor.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[])
{
  string fileAddress=argv[1];
  ifstream fff;
  fff.open(fileAddress);
  string newline;
  Netflix n;
  
  if(!fff){
  cerr << "Error: file could not be opened"<<endl;
  exit(1);
  }
  while( getline(fff,newline)){
    n.process(newline);
  }

  return 0;
}
