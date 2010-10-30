/*
 * Lee's router
 *
 * Author: Khaja Minhajuddin
 */

#include<iostream>
#include "router.cpp"

using namespace std;

int main(){
  int rows, x, y;
  cout << "Please enter the size of the grid:" << endl;
  //cin >> rows;
  //HARDCODED_INPUT
  rows = 5;
  Router *router = new Router(rows, rows);
  router->Info();

  cout << "Please enter the source co-ordinates:";
  //cin >> x >> y;
  //HARDCODED_INPUT
  x = 4; y = 4;
  Coordinate *source = new Coordinate(x, y);

  cout << "Please enter the target co-ordinates:";
  //cin >> x >> y;
  //HARDCODED_INPUT
  x = 1; y = 2;
  Coordinate *target = new Coordinate(x, y);

  router->Route(source, target);

  return 0;
}
