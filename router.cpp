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
    void visit(Coordinate *input, int stepId);
    bool isVisited(Coordinate *input);
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

void Router::visit(Coordinate *input, int stepId){
  grid[input->x][input->y].IsVisited = true;
  grid[input->x][input->y].StepId = stepId;
}

void Router::propagate(Coordinate *source, Coordinate *target){
  cout << "Propagating" << source->ToString() << " to " << target->ToString() << endl;

  int counter = 0;

  int stepId = 0;
  queue->Add(source);
  visit(source, stepId);
  Coordinate *current;

  do{
    //get the next node from queue
    stepId++;
    current = queue->Remove();
    cout << "\nprocessing: " << current->ToString();
    //get neighbors of source
    Coordinate *neighbors = current->GetNeighbors();

    int i;
    //if any of them is the target, stop,
    for (i = 0; i < 4; i++) {
      if(neighbors[i].Equals(target)){
        break;
      }

      //add it to the queue if 
      //it is not out of bounds
      //it is not visited
      if(neighbors[i].InBound(rows, cols) && !isVisited(&neighbors[i])){
        queue->Add(&neighbors[i]);
        visit(&neighbors[i], stepId);
        DisplayGrid();
        queue->Info();
      }

    }
  }while(!queue->IsEmpty() && counter++ < 100);


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


