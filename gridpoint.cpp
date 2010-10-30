class GridPoint
{
  public:
    GridPoint();
    int RouteId;
    bool IsVisited;
    void Info();
};

GridPoint::GridPoint()
{
  RouteId = 0;
  IsVisited = false;
}

void GridPoint::Info(){
  cout << "\n\n========================" << endl;
  cout << "GridPoint RouteId:" << RouteId
       << ", IsVisited:" << IsVisited;
  cout << "\n========================\n\n" << endl;
}
