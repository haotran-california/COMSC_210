//Programmer: Hao Tran
//ID: 1872272

#ifndef STACK_H
#define STACK_H

template <typename V>
class Stack{
  V* values; 
  int cap; 
  int siz; 
  void capacity(int); 

  public: 
  Stack(); //default constructor with cap = 2; 
  Stack(const Stack<V>&); //copy constructor 
  ~Stack() {delete [ ] values;}
  Stack<V>& operator=(const Stack<V>&); 
  void push(const V&); 
  const V& peek(); 
  void pop() {if (siz > 0) --siz;}
  void clear() {siz = 0;}
  int size() const; 
  bool empty() const; 

}; 

//constructor 
template <typename V>
Stack<V>::Stack(){
  siz = 0; 
  cap = 2; 
  values = new V[cap]; 
  for(int i = 0; i < cap; i++){
    values[i] = V(); 
  }
}

//copy constructor
template <typename V>
Stack<V>::Stack(const Stack<V>& original){
  siz = original.siz;
  cap = original.cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

//double capacity
template <typename V>
void Stack<V>::capacity(int cap){
  V* temp = new V[cap];

  for(int i = 0; i < this->cap; i++){
    temp[i] = values[i]; 
  }

   for(int i = 0; i < this->cap; i++){
    temp[i] = V(); 
  }

  delete [ ] values; 
  values = temp; 
  this->cap = cap; 
}

//assignment operator 
template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original){
  if(this != &original){
    delete [ ] values; 
    cap = original.cap; 
    siz = original.siz; 
    values = new V[cap]; 
    for(int i = 0; i < cap; i++){
      values[i] = original.values[i]; 
    }
    return *this; 
  }
}

//peek
template <typename V>
const V& Stack<V>::peek(){
  if(siz > 0){
      return values[siz - 1];
  }else{
      return values[0]; 
  }
}

//push
template <typename V>
void Stack<V>::push(const V& data){
  values[this->siz] = data;     
}

//size getter
template <typename V>
int Stack<V>::size() const{
  return this->siz; 
}

//empty getter
template <typename V>
bool Stack<V>::empty() const{
  if(values[0] == V()){
      return true; 
  }else{
      return false; 
  }
}

#endif