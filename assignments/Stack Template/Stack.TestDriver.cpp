//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
using namespace std;

#include<cassert>

#include "Stack.h"
#include "Stack.h"

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  //initalize stack objects
  Stack<int> stack;

  //testing constructor function 
  cout << "Testing Stack constructor size()\n";
  for (int i = 0; i < stack.size(); i++){
    assert(stack.peek() == 0);
    stack.pop();
  }

  //testing push, peek, and pop
  cout << "\nTesting Stack push(), peek(), and pop()\n";
  stack.push(456);
  stack.push(123);
  cout << "EXPECTED: 123 for 2nd add\n";
  int addT = stack.peek();
  stack.pop();
  cout << "ACTUAL: " << addT << endl;
  assert(123 == addT);
  cout << "EXPECTED: 546 for 1st add\n";
  int addO = stack.peek();
  stack.pop();
  cout << "ACTUAL: " << addO << endl;

  //testing empty 
  cout << "Testing Stack empty()\n";
  cout << "EXPECTED: true (1) \n";
  cout << "ACTUAL: " << stack.empty() << endl;

  //testing clear 
  stack.push(111);
  stack.push(222);
  cout << "Testing Stack clear()\n";
  stack.clear();
  cout << "EXPECTED size = 0\n";
  cout << "ACTUAL: " << stack.size() << endl;

  //testing constant object test 
  cout << "\nConst object test" << endl;
  const Stack<int> c;
  assert(c.size() == 0);
  assert(c.empty());

  stack.push(1000);
  stack.push(2000);
  cout << "\nObject copy test\n";
  Stack<int> d(stack); // making a copy
  assert(stack.size() == d.size());
  for (int i = 0; i < stack.size(); i++){
    assert(stack.peek() == d.peek());
    stack.pop();
    d.pop();
  }

  stack.push(3000);
  stack.push(4000);
  
  // object assignment test
  cout << "\nObject assignment test\n";
  Stack<int> e;
  e = stack;
  assert(stack.size() == e.size());
  for (int i = 0; i < 10; i++) {
    assert(stack.size() == e.size());
    stack.pop();
    e.pop();
  }
}