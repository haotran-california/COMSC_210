//Programmer: Hao Tran
//ID: 1872272

#ifndef QUEUE_H
#define QUEUE_H

template<typename V>
class Queue{

struct node{
  V value; 
  node* next;
};

int siz; 
node* firstNode; 
node* lastNode; 
V dummy; 

public: 
Queue();
Queue(const Queue&); //copy constructor
Queue<V>& operator=(const Queue<V>&); //assignment operator 
~Queue(){clear();} 
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
  for (node* p = original.firstNode; p; p = p->next)
  {
    node* temp = new node;
    temp->value = p->value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

template <typename V>
Queue<V>& Queue<V>::operator=(const Queue<V>& original){
  if (this != &original){
    // deallocate existing list
    while (firstNode){
      node* p = firstNode; 
      firstNode = firstNode->next; 
      delete p; 
    }

    // build new list
    for (node* p = original.firstNode; p; p = p->next){
      node* temp = new node;
      temp->value = p->value;
      temp->next = nullptr;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}

template <typename V>
void Queue<V>::push(const V& value){
  node* temp = new node{value}; 
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
    node* temp = firstNode;
    firstNode = firstNode->next;
    delete temp;
    --siz;
  }
  if(siz == 0){
    lastNode = 0;
  }
}

template <typename V>
void Queue<V>::clear(){
  while (firstNode){
    node* temp = firstNode;
    firstNode = firstNode->next;
    delete temp;
    --siz;
  }
  lastNode = 0;
}
#endif