//Programmer: Hao Tran
//ID: 1872272

#ifndef SORTABLEARRAY_H
#define SORTABLEARRAY_H

template<typename V> 
class SortableArray{
  V* value; 
  V dummy; 
  int cap; 

  public: 
  SortableArray(int = 2); 
  SortableArray(const SortableArray<V>&); //copy constructor 
  ~SortableArray() {delete [ ] value;}
  SortableArray<V>& operator=(const SortableArray<V>&); 

  int capacity() const {return cap;}
  void capacity(int); 
  V operator[ ] (int) const; 
  V& operator[ ] (int); 

  void sort(int); 
};

//default constructor function 
template<typename T>
SortableArray<T>::SortableArray(int cap){
  this->cap = cap; 
  value = new T[cap]; 
  for(int i = 0; i < cap; i++){
    value[i] = T(); 
  }
}

//copy constructor function 
template<typename T> 
SortableArray<T>::SortableArray(const SortableArray<T>& original){
  this->cap = original.cap; 
  this->value = new T[cap]; 
  for(int i = 0; i < cap; i++){
    value[i] = original.value[i]; 
  }
}

//assignment operator 
template<typename T> 
SortableArray<T>& SortableArray<T>::operator=(const SortableArray<T>& original){
  if(this != &original){
    delete [] value; 
    this->cap = original.cap; 
    this->value = new T[cap]; 
    for(int i = 0; i < cap; i++){
      value[i] = original.value[i]; 
    }
    return *this; 
  }
}

//getter 
template<typename T> 
T SortableArray<T>::operator[ ] (int index) const{
  if(index < 0 || index >= cap) return T(); 
  return value[index]; 
}

//setter
template<typename T>
T& SortableArray<T>::operator[ ](int index){
  if(index < 0) return dummy;
  if(index >= cap) capacity(2 * index); 
  return value[index]; 
}

//capcity defintion 
template<typename T> 
void SortableArray<T>::capacity(int cap){
  T* temp = new T[cap]; 
  //copy old content 
  int limit = cap < this->cap ? cap : this->cap; 
  for(int i = 0; i < limit; i++){
    temp[i] = value[i]; 
  }

  for(int i = limit; i < cap; i++){
    temp[i] = T(); 
  }

  delete [] value; //deallocate original array

  value = temp; //assign the data attribute to the new array 

  this->cap = cap; 
}

template <typename V>
void SortableArray<V>::sort(int endIndex)
{
  int* temp = new int[endIndex];
  for (int delta = 1; delta < endIndex; delta *= 2)
  {
    int index = 0;
    for (int i = 0; i < endIndex; i++) temp[i] = value[i];
    for (int i = 0; i < endIndex; i += 2 * delta)
    {
      int left = i;
      int leftMax = min(left + delta, endIndex);
      int right = leftMax;
      int rightMax = min(right + delta, endIndex);
      while (true)
      {
        if (left == leftMax && right == rightMax) break;
        if (left == leftMax) value[index++] = temp[right++];
        else if (right == rightMax) value[index++] = temp[left++];
        else if (temp[right] < temp[left]) value[index++] = temp[right++];
        else value[index++] = temp[left++];
      }
    }
  }
}





#endif 