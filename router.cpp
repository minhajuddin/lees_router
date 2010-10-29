#include<iostream>
using namespace std;
class Router
{
  public:
    Router(int rows, int cols);
    void Info();
  private:
    int rows;
    int cols;
};

Router::Router(int r, int c)
{
  rows = r;
  cols = c;
}

void Router::Info(){
  cout << "INFO:" << endl;
  cout << "Rows:" << rows << endl
       << "Cols:" << cols << endl;
}

