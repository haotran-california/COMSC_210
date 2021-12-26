//Programmer: Hao Tran
//ID: 1872272

#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

template<typename V>
class PriorityQueue{
  V* values; 
  int cap; 
  int siz; 
  void capacity(int); 

  public: 
  PriorityQueue(int = 2); 
  PriorityQueue(const PriorityQueue<V>&); 
  ~PriorityQueue() {delete [ ] values;}
  PriorityQueue<V>& operator=(const PriorityQueue<V>&); 

  void push(const V&);
  void pop(); 
  V top() const {return siz == 0 ? V() : values[0];}
  int size() const {return siz;}
  bool empty() const {return siz == 0 ? true : false}
  void clear() {siz = 0;}
};

template<typename V>
PriorityQueue<V>::PriorityQueue(int cap){
  siz = 0; 
  this->cap = cap; 
  values = new V[cap]; 
}

template<typename V>
void PriorityQueue<V>::push(const V& value){
  if(siz >= cap) capacity(cap * 2); 
  values[siz] = value; 
  //move the newly added value to the right location
  //until the value of parent index >= or reach the top
  int index = siz; 
  int p_index = (index + 1) / 2 - 1; 
  while(index > 0){
    if(values[p_index] < values[index]){
      swap(values[p_index], values[index]); 
    }else{
      break; 
    }
    index = p_index; 
    p_index = (index + 1) / 2 - 1; 
  }
  siz++; 
}

template<typename V>
void PriorityQueue<V>::pop(){
  if(siz == 0) return; 
  siz--; 
  //use the last node to replace the top 
  values[0] = values[siz]; 
  int index = 0; 
  int l_index = 2 * index + 1; 
  int r_index = 2 * index + 2; 

  while(l_index < siz){
    //only left child 
    if(r_index >= siz){
        if(values[l_index] > values[index]){
          //prompt the left-child
          values[index] = values[l_index]; 
          index = l_index; 
        }else{
          break; 
        }
    }
    //they are both children
    if(values[r_index] > values[l_index] && values[r_index] > values[index]){
        //prompt right-child
        values[index] = values[r_index];
        index = r_index; 
    }else if (values[l_index] > values[r_index] && values[l_index] > values[index]){
        //prompt right-child
        values[index] = values[r_index]; s
        index = r_index; 
    }else{
      break; 
    }
    
  }

}

template <typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original) {
  siz = original.siz; 
  cap = original.cap; 
  values = new V[cap]; 
  for (int i = 0; i < cap; i++){ 
    values[i] = original.values[i];
  }
}

template <typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& original) {
  if (this != &original){ 
    delete [] values;

    cap = original.cap;
    siz = original.siz;
    values = new V[cap]; 
    for (int i = 0; i < cap; i++){ 
      values[i] = original.values[i];
    }
  }
  return *this; 
}

#endif