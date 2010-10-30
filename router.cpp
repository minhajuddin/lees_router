#include<iostream>
#include<iomanip>
#include "queue.cpp"
#include "gridpoint.cpp"

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
    Queue *queue;
    void resetGrid();
    void propagate(Coordinate *source, Coordinate *target);
};

Router::Router(int r, int c)
{
  rows = r;
  cols = c;

  queue = new Queue();

  //initialize the grid
  grid = new GridPoint*[rows];
  int i;
  for (i = 0; i < cols; i++) {
    grid[i] = new GridPoint[cols];
  }
}

void Router::Info(){
  cout  << "\n========================" << endl;
  cout << "INFO:" << endl;
  cout << "Rows:" << rows << endl
    << "Cols:" << cols << endl;
  cout  << "========================\n" << endl;
}

void Router::DisplayGrid(){
  cout  << "\n========================" << endl;
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cout << setw(5) << grid[i][j].RouteId;
    }
    cout << endl;
  }
  cout  << "========================\n" << endl;

}


void Router::resetGrid(){
}

void Router::propagate(Coordinate *source, Coordinate *target){
  cout << "Propagating" << source->ToString() << " to " << target->ToString() << endl;

  //get neighbors of source
  Coordinate *neighbors = source->GetNeighbors();

  int i;
  //if any of them is the target, stop,
  for (i = 0; i < 4; i++) {
    if(neighbors[i].Equals(target)){
      break;
    }
    queue->Add(&neighbors[i]);
  }

  queue->Info();

  //else add them to the queue
  //do the same with the rest of the elements in the queue until the target is
  //reached

}

void Router::Route(Coordinate *source, Coordinate *target){
  //propagate the wave
  propagate(source, target);

  //backtrack
  //reset grid
}
