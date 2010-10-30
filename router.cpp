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

void Router::DisplayGrid(){
  cout  << "\n========================" << endl;
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cout << setw(4) << grid[i][j].RouteId
           << ":"
           << grid[i][j].StepId
           << ":"
           << grid[i][j].IsVisited;
    }
    cout << endl;
  }
  cout  << "========================\n" << endl;

}


void Router::resetGrid(){
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
  cout << "Propagating" << source->ToString() << " to " << target->ToString() << endl;

  int counter = 0;

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
    cout << "\nprocessing: " << current->ToString();
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
  }while(!queue->IsEmpty() && counter++ < 100 && !targetFound);

  DisplayGrid();

  //else add them to the queue
  //do the same with the rest of the elements in the queue until the target is
  //reached

}

void Router::backtrack(Coordinate *target, Coordinate *source){
  cout << "backtracking from " << target->ToString() << " to " << source->ToString();
  Coordinate *current = target;
  GridPoint currentGridPoint;
  GridPoint neighborGridPoint;
  int limit = 0;
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

      if(neighborGridPoint.StepId < currentGridPoint.StepId){
        current = &neighbors[i];
        //currentGridPoint = neighborGridPoint;
        break;
      }
    }
    //repeat until is source reached
  }while(!current->Equals(source) && limit++ < 100);
  //mark the source
  markRoute(source);
}

void Router::Route(Coordinate *source, Coordinate *target){
  //increaset the route identifier
  latestRouteId++;
  //propagate the wave
  propagate(source, target);
  //backtrack
  backtrack(target, source);
  DisplayGrid();
  //reset grid
}
