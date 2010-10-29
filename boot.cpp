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
  int rows;
  cout << "Please enter the size of the grid:" << endl;
  cin >> rows;
  Router *router = new Router(rows, rows);
  router->Info();

  router->DisplayGrid();

  return 0;
}
