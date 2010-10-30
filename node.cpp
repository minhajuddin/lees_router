#include "coordinate.cpp"
class Node
{
  public:
    Node(Coordinate *input);
    Coordinate *Point;
    Node *Next;
};

Node::Node(Coordinate *input)
{
  this->Point = input;
}

