/*
  File: fibonacci.cc
  Details: Demonstration of different forms of dynamic programming using
    the fibonacci example
 */

int RecursiveFibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  return RecursiveFibonacci(n - 2) + RecursiveFibonacci(n -1); 
}

int TopDownFibonacciHelper(int n, int* numArr) {
  if (n == 0 || n == 1) {
    return n;
  }
  if (numArr[n] == 0) {
    numArr[n] = TopDownFibonacciHelper(n - 2, numArr) + TopDownFibonacciHelper(n - 1, numArr);
  } 
  return numArr[n];
}

int TopDownFibonacci(int n) {
  return TopDownFibonacciHelper(n, new int(n + 1));
}

int BottomUpFibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  int fibonacciArr[n];
  fibonacciArr[0] = 0;
  fibonacciArr[1] = 1;
  for (int i = 2; i < n; i++) {
    fibonacciArr[i] = fibonacciArr[i - 2] + fibonacciArr[i - 1];
  }
  return fibonacciArr[n - 2] + fibonacciArr[n - 1];
}