/*
 Petar 'PetarV' Velickovic
 Algorithm: Insertion Sort
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

// Insertion sort algoritam za sortiranje niza
// Slozenost: O(n^2)

inline void insertionSort() {
  for (int i = 1; i < n; i++) {
    int j = i - 1;
    int tmp = niz[i];
    while (j >= 0 && niz[j] > tmp) {
      niz[j + 1] = niz[j];
      j--;
    }
    niz[j + 1] = tmp;
  }
}

int main() {
  n = 5;
  niz[0] = 4;
  niz[1] = 2;
  niz[2] = 5;
  niz[3] = 1;
  niz[4] = 3;
  insertionSort();
  for (int i = 0; i < n; i++) printf("%d ", niz[i]);
  printf("\n");
  return 0;
}
