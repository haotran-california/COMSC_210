//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
#include <cassert>
using namespace std; 

class Array{
  int values[100]; 
  int dummy = 0; 

  public: 
    Array(); 
    int capacity( ) const; 
    int operator[ ](int) const; //getter 
    int& operator[ ](int); //setter 
};

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  Array obj1; 

  //testing constructor function 
  cout << "Testing Array::Array() \n"; 
  for(int i = 0; i < 100; i++){
    assert(obj1[i] == 0); 
  }
  cout << "ACTUAL: Works" << endl;  

  //testing capacity function 
  cout << "Testing Array::capacity\n"; 
  cout << "EXPECTED: 100\n"; 
  cout << "ACTUAL: " << obj1.capacity() << endl; 
  assert(obj1.capacity() == 100); 


  //testing setter function 
  obj1[0] = 100; 
  obj1[50] = 200; 
  obj1[-1] = 999; 
  cout << "Testing Array:: operator [] setter \n"; 
  cout << "EXPECTED: obj1[0] == 100\n"; 
  cout << "ACTUAL: " << obj1[0] << endl;  
  assert(100 == obj1[0]); 
  cout << "EXPECTED: obj1[50] == 200\n"; 
  cout << "ACTUAL: " << obj1[50] << endl;  
  assert(obj1[50] == 200);
  cout << "EXPECTED: obj1[-1] == 999\n"; 
  cout << "ACTUAL: " << obj1[-1] << endl;  
  assert(obj1[-1] == 999);
  assert(obj1[200] == 999); //testing dummy value for invalid range 
  assert(obj1[99] == 0); //testing upper bound 
  assert(obj1[2] == 0); //testing lower bound


  //testing getter function 
  const Array copy_obj1 = obj1; 
  cout << "Testing Array:: operator [] getter \n"; 
  for(int i = 0; i < 100; i++){
    assert(copy_obj1[i] == obj1[i]);
  }

  //const object test 
  cout << "Constant object test \n"; 
  const Array const_obj2 ; 
  assert(const_obj2.capacity() == 100); 
  assert(const_obj2[0] == const_obj2[0]); 
  assert(const_obj2[-1] == const_obj2[-1]);
  
}

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
