/*
 * Lee's router
 *
 * Author: Khaja Minhajuddin
 */

#include<iostream>
#include "router.cpp"

using namespace std;

int main(){
  int rows, cols, x, y;
  cout << "Please enter the size of the grid:" << endl;
  cin >> rows >> cols;
  Router *router = new Router(rows, cols);
  router->Info();

  cout << "Please enter the source co-ordinates:";
  cin >> x >> y;
  Coordinate *source = new Coordinate(x, y);

  cout << "Please enter the target co-ordinates:";
  cin >> x >> y;
  Coordinate *target = new Coordinate(x, y);

  router->Route(source, target);
    
  return 0;
}
