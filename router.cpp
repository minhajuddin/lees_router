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
    void DisplayGrid(int mode);
    void Route(Coordinate *source, Coordinate *target);
  private:
    int rows;
    int cols;
    int latestRouteId;
    GridPoint **grid;
    Queue *queue;
    GridPoint getGridPointAt(Coordinate *location);
    void resetGrid();
    void visit(Coordinate *input, int stepId);
    void markRoute(Coordinate *input);
    bool isVisited(Coordinate *input);
    void propagate(Coordinate *source, Coordinate *target);
    void backtrack(Coordinate *target, Coordinate *source);
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

void Router::DisplayGrid(int mode){
  cout  << "\n========================" << endl;
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if(mode == 0){
        cout << setw(8) << grid[i][j].RouteId
          << ":"
          << grid[i][j].StepId
          << ":"
          << grid[i][j].IsVisited;
      }
      else{
        cout << setw(8) << grid[i][j].RouteId;
      }
    }
    cout << endl;
  }
  cout  << "========================\n" << endl;

}


void Router::resetGrid(){
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      grid[i][j].IsVisited = false;
      grid[i][j].StepId = 0;
    }
  }
}

bool Router::isVisited(Coordinate *input){
  return input->InBound(rows,cols) && grid[input->x][input->y].IsVisited;
}

void Router::markRoute(Coordinate *input){
  grid[input->x][input->y].RouteId = latestRouteId;
}

void Router::visit(Coordinate *input, int stepId){
  grid[input->x][input->y].IsVisited = true;
  grid[input->x][input->y].StepId = stepId;
}

GridPoint Router::getGridPointAt(Coordinate *location){
  return grid[location->x][location->y];
}

void Router::propagate(Coordinate *source, Coordinate *target){
  int stepId = 0;
  queue->Add(source);
  visit(source, stepId);
  Coordinate *current;
  GridPoint currentGridPoint;
  bool targetFound = false;

  do{
    //get the next node from queue
    current = queue->Remove();
    currentGridPoint = getGridPointAt(current);
    stepId = currentGridPoint.StepId + 1;
    //get neighbors of source
    Coordinate *neighbors = current->GetNeighbors();

    int i;
    //if any of them is the target, stop,
    for (i = 0; i < 4; i++) {
      if(neighbors[i].Equals(target)){
        visit(&neighbors[i], stepId);
        targetFound = true;
        break;
      }

      //add it to the queue if 
      //it is not out of bounds
      //it is not visited
      if(neighbors[i].InBound(rows, cols) && !isVisited(&neighbors[i])){
        queue->Add(&neighbors[i]);
        visit(&neighbors[i], stepId);
      }

    }
  }while(!queue->IsEmpty() && !targetFound);

  //else add them to the queue
  //do the same with the rest of the elements in the queue until the target is
  //reached

}

void Router::backtrack(Coordinate *target, Coordinate *source){
  Coordinate *current = target;
  GridPoint currentGridPoint;
  GridPoint neighborGridPoint;
  do{
    currentGridPoint = getGridPointAt(current);
    //mark the route id
    markRoute(current);
    //find the next node

    Coordinate *neighbors = current->GetNeighbors();
    int i;
    //if any of them is the target, stop,
    for (i = 0; i < 4; i++) {
      if(!neighbors[i].InBound(rows, cols)){
        continue;
      }
      neighborGridPoint = getGridPointAt(&neighbors[i]);

      if((neighborGridPoint.StepId < currentGridPoint.StepId && neighborGridPoint.StepId != 0) || neighbors[i].Equals(source)){
        current = &neighbors[i];
        break;
      }
    }
    //repeat until is source reached
  }while(!current->Equals(source));
  //mark the source
  markRoute(source);
}

void Router::Route(Coordinate *source, Coordinate *target){
  //increaset the route identifier
  latestRouteId++;
  //propagate the wave
  propagate(source, target);
  cout << "\n\n Wave Propagation";
  DisplayGrid(0);
  //backtrack
  backtrack(target, source);
  cout << "\n\n Backtracking";
  DisplayGrid(0);
  //reset grid
  resetGrid();
  cout << "\n\n After Reset";
  DisplayGrid(0);

  cout << "With just the path";
  DisplayGrid(1);
}
