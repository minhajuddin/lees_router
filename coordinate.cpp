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
