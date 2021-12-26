//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
#include <cassert>
#include <string>
using namespace std; 

#include "StaticArray.h"
#include "StaticArray.h" //ifndef test

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  //initalize StaticArray objects 
  StaticArray<int, 50> intArray; 
  StaticArray<double, 50> doubleArray; 
  StaticArray<char, 50> charArray; 
  StaticArray<string, 50> stringArray; 

  //test the capacity function 
  //integer test 
  cout << "Testing intArray::capacity\n"; 
  cout << "EXPECTED: 50\n"; 
  cout << "ACTUAL: " << intArray.capacity() << endl; 
  //double test 
  cout << "Testing doubleArray::capacity\n"; 
  cout << "EXPECTED: 50\n"; 
  cout << "ACTUAL: " << doubleArray.capacity() << endl; 
  //char test 
  cout << "Testing charArray::capacity\n"; 
  cout << "EXPECTED: 50\n"; 
  cout << "ACTUAL: " << charArray.capacity() << endl; 
  //string test 
  cout << "Testing stringArray::capacity\n"; 
  cout << "EXPECTED: 50\n"; 
  cout << "ACTUAL: " << stringArray.capacity() << endl; 

  //test the setter function 
  //integer test 
  intArray[0] = 100; 
  intArray[49] = 200; 
  intArray[-1] = 999; 
  cout << "Testing Array:: operator [] setter \n"; 
  cout << "EXPECTED: intArray[0] == 100\n"; 
  cout << "ACTUAL: " << intArray[0] << endl;  
  assert(100 == intArray[0]); 
  cout << "EXPECTED: intArray[49] == 200\n"; 
  cout << "ACTUAL: " << intArray[49] << endl;  
  assert(intArray[49] == 200);
  cout << "EXPECTED: intArray[-1] == 999\n"; 
  cout << "ACTUAL: " << intArray[-1] << endl;  
  assert(intArray[-1] == 999);
  //double test 
  doubleArray[0] = 1.11; 
  doubleArray[49] = 2.22; 
  doubleArray[-1] = 3.33; 
  cout << "Testing Array:: operator [] setter \n"; 
  cout << "EXPECTED: doubleArray[0] == 1.11\n"; 
  cout << "ACTUAL: " << doubleArray[0] << endl;  
  assert(1.11 == doubleArray[0]); 
  cout << "EXPECTED: doubleArray[49] == 2.22\n"; 
  cout << "ACTUAL: " << doubleArray[49] << endl;  
  assert(doubleArray[49] == 2.22);
  cout << "EXPECTED: doubleArray[-1] == 3.33\n"; 
  cout << "ACTUAL: " << doubleArray[-1] << endl;  
  assert(doubleArray[-1] == 3.33);
  //char test 
  charArray[0] = 'A'; 
  charArray[49] = 'B'; 
  charArray[-1] = 'C'; 
  cout << "Testing Array:: operator [] setter \n"; 
  cout << "EXPECTED: charArray[0] == 'A'\n"; 
  cout << "ACTUAL: " << charArray[0] << endl;  
  assert('A' == charArray[0]); 
  cout << "EXPECTED: charArray[49] == 'B'\n"; 
  cout << "ACTUAL: " << charArray[49] << endl;  
  assert(charArray[49] == 'B');
  cout << "EXPECTED: charArray[-1] == 'C'\n"; 
  cout << "ACTUAL: " << charArray[-1] << endl;  
  assert(charArray[-1] == 'C');
  //string test 
  stringArray[0] = "array"; 
  stringArray[49] = "static array"; 
  stringArray[-1] = "vector"; 
  cout << "Testing Array:: operator [] setter \n"; 
  cout << "EXPECTED: stringArray[0] == array\n"; 
  cout << "ACTUAL: " << stringArray[0] << endl;  
  assert("array" == stringArray[0]); 
  cout << "EXPECTED: stringArray[49] == static array\n"; 
  cout << "ACTUAL: " << stringArray[49] << endl;  
  assert(stringArray[49] == "static array");
  cout << "EXPECTED: stringArray[-1] == vector\n"; 
  cout << "ACTUAL: " << stringArray[-1] << endl;  
  assert(stringArray[-1] == "vector");


  //test the getter function 
  //integer test 
  const StaticArray<int, 50> copy_intArray = intArray; 
  cout << "Testing intArray:: operator [] getter \n"; 
  for(int i = 0; i < 50; i++){
    assert(copy_intArray[i] == intArray[i]);
  }
  cout << "Test passed\n";
  //double test 
  const StaticArray<double, 50> copy_doubleArray = doubleArray; 
  cout << "Testing doubleArray:: operator [] getter \n"; 
  for(int i = 0; i < 50; i++){
    assert(copy_doubleArray[i] == doubleArray[i]);
  }
  cout << "Test passed\n";
  //char test 
  const StaticArray<char, 50> copy_charArray = charArray; 
  cout << "Testing charArray:: operator [] getter \n"; 
  for(int i = 0; i < 50; i++){
    assert(copy_charArray[i] == charArray[i]);
  }
  cout << "Test passed\n"; 
  //string test 
  const StaticArray<string, 50> copy_stringArray = stringArray; 
  cout << "Testing stringArray:: operator [] getter \n"; 
  for(int i = 0; i < 50; i++){
    assert(copy_stringArray[i] == stringArray[i]);
  }
  cout << "Test passed\n"; 

  //cosnt object test 
  //int test 
  cout << "Constant object test for intArray\n"; 
  const StaticArray<int, 50> c_intArray; 
  assert(c_intArray.capacity() == 50); 
  assert(c_intArray[0] == c_intArray[0]); 
  assert(c_intArray[-1] == c_intArray[-1]);
  cout << "Test passed\n"; 
  //double test 
  cout << "Constant object test doubleArray\n"; 
  const StaticArray<double, 50> c_doubleArray; 
  assert(c_doubleArray.capacity() == 50); 
  assert(c_doubleArray[0] == c_doubleArray[0]); 
  assert(c_doubleArray[-1] == c_doubleArray[-1]);
  cout << "Test passed\n"; 
  //char test 
  cout << "Constant object test charArray\n"; 
  const StaticArray<char, 50> c_charArray; 
  assert(c_charArray.capacity() == 50); 
  assert(c_charArray[0] == c_charArray[0]); 
  assert(c_charArray[-1] == c_charArray[-1]);
  cout << "Test passed\n";    
  //string test 
  cout << "Constant object test stringArray\n"; 
  const StaticArray<string, 50> c_stringArray; 
  assert(c_stringArray.capacity() == 50); 
  assert(c_stringArray[0] == c_stringArray[0]); 
  assert(c_stringArray[-1] == c_stringArray[-1]);
  cout << "Test passed\n";

}