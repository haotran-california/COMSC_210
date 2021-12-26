#ifndef LabExercise4_h
#define LabExercise4_h

template <typename T>
class DynamicArray{
  T* values; 
  int cap; 
  T dummy = T(); 

  public: 
  DynamicArray(int = 2); //set default value to 2 
  DynamicArray(const DynamicArray<T>&); //copy constructor
  ~DynamicArray() {delete [ ] values;} //destructor 
  DynamicArray<T>& operator=(const DynamicArray<T>&); //assignment operator
  int capacity() const; 
  void capacity(int); //setter 
  T operator[ ] (int) const; //getter 
  T& operator[ ] (int); //setter 
}; 

//default constructor function 
template<typename T>
DynamicArray<T>::DynamicArray(int cap){
  this->cap = cap; 
  values = new T[cap]; 
  for(int i = 0; i < cap; i++){
    values[i] = T(); 
  }
}

//copy constructor function 
template<typename T> 
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original){
  this->cap = original.cap; 
  this->values = new T[cap]; 
  for(int i = 0; i < cap; i++){
    values[i] = original.values[i]; 
  }
}

//assignment operator 
template<typename T> 
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& original){
  if(this != &original){
    delete [] values; 
    this->cap = original.cap; 
    this->values = new T[cap]; 
    for(int i = 0; i < cap; i++){
      values[i] = original.values[i]; 
    }
    return *this; 
  }
}

//getter 
template<typename T> 
T DynamicArray<T>::operator[ ] (int index) const{
  if(index < 0 || index >= cap) return T(); 
  return values[index]; 
}

//setter
template<typename T>
T& DynamicArray<T>::operator[ ](int index){
  if(index < 0) return dummy;
  if(index >= cap) capacity(2 * index); 
  return values[index]; 
}

//capacity 
template<typename T> 
int DynamicArray<T>::capacity() const{
  return this->cap; 
}

//capcity defintion 
template<typename T> 
void DynamicArray<T>::capacity(int cap){
  T* temp = new T[cap]; 
  //copy old content 
  int limit = cap < this->cap ? cap : this->cap; 
  for(int i = 0; i < limit; i++){
    temp[i] = values[i]; 
  }

  for(int i = limit; i < cap; i++){
    temp[i] = T(); 
  }

  delete [] values; //deallocate original array

  values = temp; //assign the data attribute to the new array 

  this->cap = cap; 
}

#endif 