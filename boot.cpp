/*
 * Lee's router
 *
 * Author: Khaja Minhajuddin
 */

#include<iostream>
#include "gridpoint.cpp"
#include "node.cpp"
#include "queue.cpp"
#include "router.cpp"

using namespace std;

int main(){
  int rows, x, y;
  cout << "Please enter the size of the grid:" << endl;
  cin >> rows;
  Router *router = new Router(rows, rows);
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
