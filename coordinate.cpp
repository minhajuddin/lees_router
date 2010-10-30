#include<sstream>
using namespace std;
class Coordinate
{
  public:
    Coordinate();
    Coordinate(int x, int y);
    int x;
    int y;

    string ToString();
    Coordinate* GetNeighbors();
    bool Equals(Coordinate* input);
};

Coordinate::Coordinate()
{
  x = 0;
  y = 0;
}

Coordinate::Coordinate(int x, int y)
{
  this->x = x;
  this->y = y;
}

string Coordinate::ToString(){
  ostringstream sin;
  sin << "(" << x << ", " << y << ")";
  return sin.str();
}


Coordinate* Coordinate::GetNeighbors(){
  Coordinate *neighbors = new Coordinate[4];
  int basex = this->x;
  int basey = this->y;

  ////top
  neighbors[0].x = basex + 1;
  neighbors[0].y = basey;
  ////right
  neighbors[1].x = basex;
  neighbors[1].y = basey + 1;
  ////bottom
  neighbors[2].x = basex - 1;
  neighbors[2].y = basey;
  ////left
  neighbors[3].x = basex;
  neighbors[3].y = basey - 1;

  return neighbors;
}

bool Coordinate::Equals(Coordinate* input){
  return x == input->x && y == input->y;
}
