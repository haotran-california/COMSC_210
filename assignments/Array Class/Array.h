//Programmer: Hao Tran
//ID: 1872272

class Array{
  int values[100]; 
  int dummy = 0; 

  public: 
    Array(); 
    int capacity( ) const; 
    int operator[ ](int) const; //getter 
    int& operator[ ](int); //setter 
};

Array::Array(){
  for(int i = 0; i < 100; i++){
    values[i] = 0; 
  }
}

int Array::capacity() const {
    return 100; 
}

int Array:: operator[] (int index) const{
  if(index < 0 || index > 100){
    return 0; 
  }

  return values[index]; 
}

int& Array:: operator[] (int index){
  if(index < 0 || index >= 100){
    return dummy;  
  }

  return values[index]; //mutable reference 
}
