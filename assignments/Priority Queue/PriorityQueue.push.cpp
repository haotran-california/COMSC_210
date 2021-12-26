//Programmer: Hao Tran
//ID: 1872272

#include <iostream> 
#include <string> 
using namespace std;

#include <cassert>
#include <cmath> 
#include <cstdlib> 
#include <ctime> 

#include "PriorityQueue.h"

int main()
{
  srand(time(0)); rand( ); // seed the random number generator (in case you need it)

  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  
  
  int n = 1000000; 
  string bigOh = "O(log n)"; 
  int nReps = n / 100;
  
  cout.setf(ios::fixed);
  cout.precision(4);
  double elapsedSecondsNorm = 0;
  double expectedSeconds = 0;
  
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // problem setup 
    
   PriorityQueue<int> timeQ(n * 2);
    for (int i = 0; i < n; i++)
    {
      timeQ.push(i);
    }
    
    // assert that n is the size of the data structure if applicable
    assert(timeQ.size() == n);
    
   PriorityQueue<int> timeQ2 = timeQ;
    
    while (!timeQ.empty())
    {
      int temp = timeQ.top();
      timeQ.pop();
      assert(temp >= timeQ.top());
    }
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    
    for(int rep = 0; rep < nReps; rep++)
    {
      timeQ2.push(rand() % n);
    }
    
    // do something where n is the "size" of the problem
    clock_t endTime = clock();
    
    // validation block -- assure that process worked if applicable
    assert(timeQ2.size() == n + nReps);
    timeQ = timeQ2;
    while(!timeQ2.empty())
    {
      int temp = timeQ2.top();
      timeQ2.pop();
      assert(temp >= timeQ2.top());
    }
    
    // cleanup if applicable
    
    // compute timing results
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double factor = pow(2.0, double(cycle));
    if (cycle == 0)
      elapsedSecondsNorm = elapsedSeconds;
    else if (bigOh == "O(n)")
      expectedSeconds = factor * elapsedSecondsNorm;
    else if (bigOh == "O(n log n)")
      expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
    else if (bigOh == "O(n squared)")
      expectedSeconds = factor * factor * elapsedSecondsNorm;
    else if (bigOh == "O(log n)")
      expectedSeconds = log(double(n)) / log(n / factor) * elapsedSecondsNorm;
    
    // reporting block
    cout << elapsedSeconds;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedSeconds << ')';
    cout << " for n=" << n << endl;
  }
}