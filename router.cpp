#include<iostream>
#include<iomanip>
#include "coordinate.cpp"

using namespace std;
class Router
{
  public:
    Router(int rows, int cols);
    void Info();
    void DisplayGrid();
    void Route(Coordinate *source, Coordinate *target);
  private:
    int rows;
    int cols;
    GridPoint **grid;
    void resetGrid();
};

Router::Router(int r, int c)
{
  rows = r;
  cols = c;

  //initialize the grid
  grid = new GridPoint*[rows];
  int i;
  for (i = 0; i < cols; i++) {
    grid[i] = new GridPoint[cols];
  }
}

void Router::Info(){
  cout << "INFO:" << endl;
  cout << "Rows:" << rows << endl
    << "Cols:" << cols << endl;
}

void Router::DisplayGrid(){
  cout  << "\n\n========================\n" << endl;
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cout << setw(5) << grid[i][j].RouteId;
    }
    cout << endl;
  }
  cout  << "\n========================\n\n" << endl;

}


void Router::resetGrid(){
}


void Router::Route(Coordinate *source, Coordinate *target){
  cout << "Routing " << source->ToString() << " to " << target->ToString() << endl;
}
