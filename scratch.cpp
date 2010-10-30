//This is a scratch file which doesn't have any production code
//It's just to test some random c++ stuff
//
#include<iostream>
#include "coordinate.cpp"
using namespace std;

int main(){

  Coordinate *points;
  points = new Coordinate[10];

  //cout << sizeof(points)/ sizeof(Coordinate);
  cout << sizeof(*points) << '|' << sizeof(Coordinate);

  cout << "|" << points[23].ToString();

  cout << endl;

}
