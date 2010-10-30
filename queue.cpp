#include "node.cpp"
class Queue
{
  public:
    Node *First;
    Node *Last;
    int size;
    Queue();
    bool IsEmpty();
    void Info();
    void Add(Coordinate *input);
    Coordinate* Remove();
};

Queue::Queue()
{
  size = 0;
}


void Queue::Add(Coordinate *input){
  //add the new node to the end
  Node *node = new Node(input);
  //if this is the first node make first and last point to it
  if(size == 0){
    First = node;
    Last = node;
  }
  else{
    //make the last pointers next point to the new node
    Last->Next = node;
    //make the last pointer point to the new node
    Last = node;
  } size++;
}


Coordinate* Queue::Remove(){
  if(size == 0){
    return NULL;
  }

  Coordinate* first = First->Point;
  First = First->Next;
  size--;
  return first;
}

bool Queue::IsEmpty(){
  return size == 0;
}

void Queue::Info(){
  cout  << "\n\n========================" << endl;
  cout << "Queue " 
    << "IsEmpty:" << IsEmpty() << endl
    << "Size:" << size << endl
    << "First:"
    << First
    << ":" 
    << First->Point->ToString() 
    << "; Next:"
    << First->Next
    << endl
    << "Last:"
    << Last
    << ":" 
    << Last->Point->ToString();
  cout  << "\n========================\n\n" << endl;
}
