class GridPoint
{
  public:
    GridPoint();
    int RouteId;
    bool IsVisited;
};

GridPoint::GridPoint()
{
  RouteId = 0;
  IsVisited = false;
}

