/*
 Petar 'PetarV' Velickovic
 Algorithm: Counting Sort
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
#define MAX_N 1000001
#define MAX_K 1000001
using namespace std;
typedef long long lld;

int n;
int niz[MAX_N];
int Count[MAX_K];

// Counting sort algoritam za sortiranje niza pozitivnih celih brojeva ne vecih
// od MAX_K Slozenost: O(n + k)

void countingSort() {
  for (int i = 0; i < n; i++) Count[niz[i]]++;
  int ii = 0;
  for (int i = 0; i < MAX_K; i++) {
    while (Count[i] > 0) {
      niz[ii++] = i;
      Count[i]--;
    }
  }
}

int main() {
  n = 5;
  niz[0] = 4;
  niz[1] = 2;
  niz[2] = 5;
  niz[3] = 1;
  niz[4] = 3;
  countingSort();
  for (int i = 0; i < n; i++) printf("%d ", niz[i]);
  printf("\n");
  return 0;
}
