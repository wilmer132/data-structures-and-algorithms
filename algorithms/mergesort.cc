/*
  File: mergesort.cc
  Details: Implementation of mergesort 
 */

void merge(int* givenArray, int* helperArray, int low, int middle, int high) {
  for (int i = low; i <= high; i++) {
    helperArray[i] = givenArray[i];
  }
  int helperLeft = low;
  int helperRight = middle + 1;
  int current = low;
  while (helperLeft <= middle && helperRight <= high) {
    if (helperArray[helperLeft] <= helperArray[helperRight]) {
      givenArray[current] = helperArray[helperLeft];
      helperLeft++;
    } else {
      givenArray[current] = helperArray[helperRight];
      helperRight++;
    }
    current++;
  }
  int remaining = middle - helperLeft;
  for (int i = 0; i < remaining; i++) {
    givenArray[current + i] = helperArray[helperLeft + i];
  }
}

void mergesortHelper(int* givenArray, int* helperArray, int low, int high) {
  if (low < high) {
    int middle = low + (high - low) / 2;
    mergesortHelper(givenArray, helperArray, low, middle);
    mergesortHelper(givenArray, helperArray, middle + 1, high);
    merge(givenArray, helperArray, low, middle, high);
  }
}

int* mergesort(int* givenArray, int givenArrayLength) {
  int helperArray[givenArrayLength];
  mergesortHelper(givenArray, helperArray, 0, givenArrayLength - 1); 
  return givenArray;
}
