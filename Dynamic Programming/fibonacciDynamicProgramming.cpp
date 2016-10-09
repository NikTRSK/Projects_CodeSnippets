#include <iostream>
#include <map>
#include <ctime>

using namespace std;

int fibonacciDPHelper(int n, std::map<int, int> m) {
  if (m.find(n) == m.end())
    m.insert(std::pair<int, int>(n, fibonacciDPHelper(n-1, m) + fibonacciDPHelper(n-2, m)));

  return m.find(n)->second;
} // O(n)

// bottom up approach
int fibonacciDynamicProgramming(int n) {
  std::map<int, int> m;
  m.insert(std::pair<int, int>(0, 0));
  m.insert(std::pair<int, int>(1, 1));

  return fibonacciDPHelper(n, m);
}

// top down approach
int fibonacciRecurssive(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  
  return (fibonacciRecurssive(n-1) + fibonacciRecurssive(n-2));
} // O(2^n)

int fibonacciIterative(int n) {
  if (n == 0)
    return 0;
  
  int x1 = 0, x2 = 1;
  for (int i = 2; i <= n; ++i) {
    int x3 = x1 + x2;
    x1 = x2;
    x2 = x3;
  }

  return x2;
} // O(n^2) space O(n)

// 1: Recurrsive
// 2: Iterative
// 3: Dynamic
double testRuntime(int f) {
  clock_t begin = clock();

  if (f == 1)
    cout << "Recurrsive: " << fibonacciDynamicProgramming(35) << endl;
  if (f == 2)
    cout << "Iterative: " <<  fibonacciIterative(35) << endl;
  if (f == 3)
    cout << "Dynamic: " << fibonacciRecurssive(35) << endl;

  clock_t end = clock();
  double elapsed_time = double(end-begin) / CLOCKS_PER_SEC;
  
  return elapsed_time; // returns the time elapsed
}

int main() {
  cout << "Fibonacci algorithm comparisson.\n\n";
  cout << "Using Recursion: " << testRuntime(1) << endl;
  cout << "Using Iterative: " << testRuntime(2) << endl;
  cout << "Using Dynamic: " << testRuntime(3) << endl;
}