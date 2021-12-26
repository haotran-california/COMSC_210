//Programmer: Hao Tran
//ID: 1872272

#ifndef Array_h
#define Array_h

template <typename T, int CAP>
class StaticArray{
  T value[CAP]; 
  T dummy; 

  public: 
    StaticArray(); 
    int capacity( ) const; 
    T operator[ ](int) const; //getter 
    T& operator[ ](int); //setter 
};

template <typename T, int CAP>
StaticArray<T, CAP>::StaticArray(){
  dummy = T(); //default assignment of value 

  for(int i = 0; i < CAP; i++){
    value[i] = T(); 
  }
}

template <typename T, int CAP>
int StaticArray<T, CAP>::capacity() const {
    return CAP; 
}

template <typename T, int CAP>
T StaticArray<T, CAP>:: operator[ ] (int index) const{
  if(index < 0 || index >= CAP){
    return T(); 
  }

  return value[index]; 
}

template <typename T, int CAP>
T& StaticArray<T, CAP>:: operator[ ] (int index){
  if(index < 0 || index >= CAP){
    return dummy;  
  }

  return value[index]; //mutable reference 
}

#endif