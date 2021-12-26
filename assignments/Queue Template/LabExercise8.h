//Programmer: Hao Tran
//ID: 1872272

#ifndef QUEUE_H
#define QUEUE_H

template<typename V>
class Queue{

struct node{
  V value; 
  node* next;
}
int siz; 
node* firstNode; 
node* lastNode; 
V dummy; 

public: 
Queue();
Queue(const Queue&) //copy constructor
Queue<V>& operator=(const Queue<V>&); //assignment operator 
~Queue(); 
void push(const V&); 
const V& front() const; //return immutable reference to oldest node
const V& back() const; //return immutable reference to newest node
void pop(); //remove oldest node
int size() const{return siz;}
bool empty() const {return siz == 0;}
void clear(); 
};

template <typename V>
Queue<V>::Queue(){
  lastNode = 0;
  siz = 0;
}

template <typename V>
Queue<V>::Queue(const Queue<V>& original)
{
  firstNode = 0;
  lastNode = 0; 
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->value = p->value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

template <typename V>
void Queue<V>::push(const V& value){
  Node* temp = new Node{value}; 
  if (lastNode) lastNode->next = temp;
  else firstNode = temp;
  lastNode = temp;
  ++siz;
}

template <typename V>
const V& Queue<V>::front() const{
  if(firstNode)return firstNode->value;
  return dummy; 
}

template <typename V>
const V& Queue<V>::back() const{
  if(lastNode) return lastNode->value;
  return dummy; 
}

template <typename V>
void Queue<V>::pop(){
  if (firstNode){
    Node* temp = firstNode;
    firstNode = firstNode->next;
    delete temp;
    --siz;
  }
  if(siz == 0){
    lastNode = 0;
  }
}

template <typename V>
void Queue<V>::clear()
{
  while (firstNode){
    Node* temp = firstNode;
    firstNode = firstNode->next;
    delete temp;
    --siz;
  }
  lastNode = 0;
}
#endif