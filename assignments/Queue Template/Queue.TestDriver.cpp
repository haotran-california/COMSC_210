//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
using namespace std;

#include<cassert>

#include"Queue.h"
#include"Queue.h"

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  Queue<int> queue; 
  
  //testing for size function
  cout << "Testing constructor and size \n";
  assert(queue.size() == 0); 
  cout << "Passed\n";

  //testing for push, front, back, and pop function 
  cout << "Testing for the push, front, back, and pop functions \n"; 
  queue.push(100); 
  queue.push(200); 
  queue.push(300); 
  cout << "EXPECTED: 100 for 1rst element \n"; 
  cout << "ACTUAL: " << queue.front() << endl; 
  assert(queue.front() == 100); 
  cout << "EXPECTED: 300 for the last element \n"; 
  cout << "ACTUAL: " << queue.back() << endl; 
  assert(queue.back() == 300); 
  cout << "Testing empty queue \n"; 
  queue.pop();
  queue.pop();
  queue.pop();
  cout << "EXPECTED: 1 \n"; 
  cout << "ACTUAL: " << queue.empty() << endl;
  assert(queue.empty() == 1); 

  //testing clear test 
  queue.push(50); 
  cout << "Testing clear \n"; 
  queue.clear(); 
  cout << "EXPECTED: 0 \n"; 
  cout << "ACTUAL: " << queue.size() << endl; 
  assert(queue.size() == 0); 

  //const object test 
  const Queue<int> const_queue; 
  cout << "Constant object test \n"; 
  assert(const_queue.size() == 0); 
  assert(const_queue.empty()); 
  cout << "Passed \n"; 

  //object copy test
  cout << "Object copy test \n"; 
  Queue<int> copy(queue); 
  assert(queue.size() == copy.size()); 
  for(int i = 0; i < queue.size(); i++){
    assert(queue.front() == copy.front()); 
    queue.pop(); 
    copy.pop(); 
  }
  cout << "Passed \n";

  cout << "-------------------------------\n";
  cout << "Testing for string \n";

  Queue<string> s_queue; 

   //testing for size function
  cout << "Testing constructor and size \n";
  assert(s_queue.size() == 0); 
  cout << "Passed\n";

  //testing for push, front, back, and pop function 
  cout << "Testing for the push, front, back, and pop functions \n"; 
  s_queue.push("A"); 
  s_queue.push("B"); 
  s_queue.push("D"); 
  cout << "EXPECTED: A for 1rst element \n"; 
  cout << "ACTUAL: " << s_queue.front() << endl; 
  assert(s_queue.front() == "A"); 
  cout << "EXPECTED: D for the last element \n"; 
  cout << "ACTUAL: " << s_queue.back() << endl; 
  assert(s_queue.back() == "D"); 
  cout << "Testing empty s_queue \n"; 
  s_queue.pop();
  s_queue.pop();
  s_queue.pop();
  cout << "EXPECTED: 1 \n"; 
  cout << "ACTUAL: " << s_queue.empty() << endl;
  assert(s_queue.empty() == 1); 

  //testing clear test 
  s_queue.push("H"); 
  cout << "Testing clear \n"; 
  s_queue.clear(); 
  cout << "EXPECTED: 0 \n"; 
  cout << "ACTUAL: " << s_queue.size() << endl; 
  assert(s_queue.size() == 0); 

  //const object test 
  const Queue<string> const_squeue; 
  cout << "Constant object test \n"; 
  assert(const_squeue.size() == 0); 
  assert(const_squeue.empty()); 
  cout << "Passed \n"; 

  //object copy test
  cout << "Object copy test \n"; 
  Queue<string> s_copy(s_queue); 
  assert(s_queue.size() == s_copy.size()); 
  for(int i = 0; i < s_queue.size(); i++){
    assert(s_queue.front() == s_copy.front()); 
    s_queue.pop(); 
    s_copy.pop(); 
  }
  cout << "Passed \n";
  

}
