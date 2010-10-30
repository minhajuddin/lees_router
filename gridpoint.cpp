class GridPoint
{
  public:
    GridPoint();
    int RouteId;
    int StepId;
    bool IsVisited;
    void Info();
};

GridPoint::GridPoint()
{
  RouteId = 0;
  IsVisited = false;
  StepId = 0;
}

void GridPoint::Info(){
  cout << "\n\n========================" << endl;
  cout << "GridPoint RouteId:" << RouteId
       << ", StepId:" << StepId
       << ", IsVisited:" << IsVisited;
  cout << "\n========================\n\n" << endl;
}
