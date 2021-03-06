/*
 Petar 'PetarV' Velickovic
 Algorithm: Bubble Sort
*/

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <complex>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MAX_N 5001
using namespace std;
typedef long long lld;

int n;
int niz[MAX_N];

// Bubble sort algoritam za sortiranje niza
// Slozenost: O(n^2)

inline void bubbleSort() {
  bool swapped;
  int it = 0;
  do {
    swapped = false;
    for (int i = 0; i < n - it - 1; i++) {
      if (niz[i] > niz[i + 1]) {
        swap(niz[i], niz[i + 1]);
        swapped = true;
      }
    }
    it++;
  } while (swapped);
}

int main() {
  n = 5;
  niz[0] = 4;
  niz[1] = 2;
  niz[2] = 5;
  niz[3] = 1;
  niz[4] = 3;
  bubbleSort();
  for (int i = 0; i < n; i++) printf("%d ", niz[i]);
  printf("\n");
  return 0;
}
