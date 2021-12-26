//Programmer: Hao Tran
//ID: 1872272
#include <iostream>
#include <cassert>
#include <string>
using namespace std; 

#include "DynamicArray.h" 
#include "DynamicArray.h" //ifndef test

//function prototypes 
void testIntArray(DynamicArray<int>); 
void testCharArray(DynamicArray<char>); 
void testStringArray(DynamicArray<string>); 

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  //initalize StaticArray objects 
  DynamicArray<int> intArray; 
  DynamicArray<char> charArray; 
  DynamicArray<string> stringArray; 

  testIntArray(intArray);
  testCharArray(charArray); 
  testStringArray(stringArray); 
}

//function definitions
void testIntArray(DynamicArray<int> intArray){
  //testing for the int dynamic array 
  cout << "\nInteger Dynamic Array test: \n"; 
  cout << "----------------------------\n"; 
  intArray[50] = 0; 

  //test the capacity function 
  cout << "\nTesting intArray::capacity\n"; 
  cout << "EXPECTED: 100\n"; 
  cout << "ACTUAL: " << intArray.capacity() << endl; 
  cout << "Pass !\n"; 

  //test the default constructor function 
  cout << "\nTesting Array::Array\n"; 
  for(int i = 0; i < intArray.capacity(); i++){
    assert(intArray[i] == int()); 
  }
  cout << "Pass !\n"; 

  //test the setter function 
  intArray[0] = 999; 
  intArray[50] = 100; 
  intArray[101] = 777; //expand the array 
  intArray[-1] = 222; //invalid range
  cout << "\nTesting Array:: operator [] setter \n"; 
  cout << "EXPECTED: intArray[0] == 100\n"; 
  cout << "ACTUAL: " << intArray[0] << endl;  
  assert(999 == intArray[0]); 
  cout << "EXPECTED: intArray[50] == 200\n"; 
  cout << "ACTUAL: " << intArray[50] << endl;  
  assert(intArray[50] == 100);
  cout << "EXPECTED: intArray[101] == 777\n"; 
  cout << "ACTUAL: " << intArray[101] << endl;  
  assert(intArray[101] == 777);
  cout << "EXPECTED: intArray.capacity() == 202\n"; 
  cout << "ACTUAL: " << intArray.capacity() << endl;  
  assert(intArray.capacity() == 202);
  cout << "EXPECTED: intArray[-1] == 222\n"; 
  cout << "ACTUAL: " << intArray[-1] << endl;  
  assert(intArray[-1] == 222);
  cout << "Pass !\n"; 
  

  //object copy test
  cout << "\nObject copy test\n";  
  DynamicArray<int> copy_intArray = intArray; 
  for(int i = 0; i < intArray.capacity(); i++){
    assert(copy_intArray[i] == intArray[i]);
  }
  for(int i = 0; i < intArray.capacity(); i++){
    intArray[i]++; 
    assert(intArray[i] != copy_intArray[i]); 
  }
  cout << "Pass !\n"; 

  //object assignment test 
  cout << "\nObject assignment test \n"; 
   DynamicArray<int> copy2_intArray; 
   copy2_intArray = intArray; 
   assert(copy2_intArray.capacity() == intArray.capacity()); 
   for(int i = 0; i < intArray.capacity(); i++){
    intArray[i]++; 
    assert(intArray[i] != copy2_intArray[i]); 
  }
  cout << "Pass !\n"; 
}

void testCharArray(DynamicArray<char> charArray){
  //testing for the char dynamic array 
  cout << "\nCharacter Dynamic Array test: \n"; 
  cout << "----------------------------\n"; 
  charArray[50] = char(); 

  //test the capacity function 
  cout << "\nTesting charArray::capacity\n"; 
  cout << "EXPECTED: 100\n"; 
  cout << "ACTUAL: " << charArray.capacity() << endl; 
  cout << "Pass !\n"; 

  //test the default constructor function 
  cout << "\nTesting Array::Array\n"; 
  for(int i = 0; i < charArray.capacity(); i++){
    //cout << charArray[i] << endl; 
    assert(charArray[i] == char()); 
  }
  cout << "Pass !\n"; 

  //test the setter function 
  charArray[25] = 'a'; 
  charArray[101] = 'f'; //expand the array 
  charArray[-1] = 'z'; //invalid range
  cout << "\nTesting Array:: operator [] setter \n"; 
  cout << "EXPECTED: charArray[25] == 'a' \n"; 
  cout << "ACTUAL: " << charArray[0] << endl;  
  assert('a' == charArray[25]); 
  cout << "EXPECTED: charArray[101] == 'f'\n"; 
  cout << "ACTUAL: " << charArray[101] << endl;  
  assert(charArray[101] == 'f');
  cout << "EXPECTED: charArray.capacity() == 202\n"; 
  cout << "ACTUAL: " << charArray.capacity() << endl;  
  assert(charArray.capacity() == 202);
  cout << "EXPECTED: charArray[-1] == 'z'\n"; 
  cout << "ACTUAL: " << charArray[-1] << endl;  
  assert(charArray[-1] == 'z');
  cout << "Pass !\n"; 
  

  //object copy test
  cout << "\nObject copy test\n";  
  DynamicArray<char> copy_charArray = charArray; 
  for(int i = 0; i < charArray.capacity(); i++){
    assert(copy_charArray[i] == charArray[i]);
  }
  for(int i = 0; i < charArray.capacity(); i++){
    charArray[i]+= 'a'; 
    assert(charArray[i] != copy_charArray[i]); 
  }
  cout << "Pass !\n"; 

  //object assignment test 
  cout << "\nObject assignment test \n"; 
   DynamicArray<char> copy2_charArray; 
   copy2_charArray = charArray; 
   assert(copy2_charArray.capacity() == charArray.capacity()); 
   for(int i = 0; i < charArray.capacity(); i++){
    charArray[i] += 'p'; 
    assert(charArray[i] != copy2_charArray[i]); 
  }
  cout << "Pass !\n"; 
}

void testStringArray(DynamicArray<string> stringArray){
  //testing for the string dynamic array 
  cout << "\nString Dynamic Array test: \n"; 
  cout << "----------------------------\n"; 
  stringArray[50] = string(); 

  //test the capacity function 
  cout << "\nTesting stringArray::capacity\n"; 
  cout << "EXPECTED: 100\n"; 
  cout << "ACTUAL: " << stringArray.capacity() << endl; 
  cout << "Pass !\n"; 

  //test the default constructor function 
  cout << "\nTesting Array::Array\n"; 
  for(int i = 0; i < stringArray.capacity(); i++){
    assert(stringArray[i] == string()); 
  }
  cout << "Pass !\n"; 

  //test the setter function 
  stringArray[25] = "DVC"; 
  stringArray[101] = "Contra Consta"; //expand the array 
  stringArray[-1] = "Physics"; //invalid range
  cout << "\nTesting Array:: operator [] setter \n"; 
  cout << "EXPECTED: stringArray[25] == DVC \n"; 
  cout << "ACTUAL: " << stringArray[25] << endl;  
  assert(stringArray[25] == "DVC"); 
  cout << "EXPECTED: stringArray[101] == Contra Consta \n"; 
  cout << "ACTUAL: " << stringArray[101] << endl;  
  assert(stringArray[101] == "Contra Consta");
  cout << "EXPECTED: stringArray.capacity() == 202 \n"; 
  cout << "ACTUAL: " << stringArray.capacity() << endl;  
  assert(stringArray.capacity() == 202);
  cout << "EXPECTED: stringArray[-1] == Physics\n"; 
  cout << "ACTUAL: " << stringArray[-1] << endl;  
  assert(stringArray[-1] == "Physics");
  cout << "Pass !\n"; 
  

  //object copy test
  cout << "\nObject copy test\n";  
  DynamicArray<string> copy_stringArray = stringArray; 
  for(int i = 0; i < stringArray.capacity(); i++){
    assert(copy_stringArray[i] == stringArray[i]);
  }
  for(int i = 0; i < stringArray.capacity(); i++){
    stringArray[i]+= "a"; 
    assert(stringArray[i] != copy_stringArray[i]); 
  }
  cout << "Pass !\n"; 

  //object assignment test 
  cout << "\nObject assignment test \n"; 
   DynamicArray<string> copy2_stringArray; 
   copy2_stringArray = stringArray; 
   assert(copy2_stringArray.capacity() == stringArray.capacity()); 
   for(int i = 0; i < stringArray.capacity(); i++){
    stringArray[i]+= "a"; 
    assert(stringArray[i] != copy2_stringArray[i]); 
  }
  cout << "Pass !\n"; 
}
