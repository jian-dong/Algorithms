/*
 Petar 'PetarV' Velickovic
 Algorithm: Permutations
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
using namespace std;
typedef long long lld;

int n;
int niz[100];
bool inPerm[100];
int currPerm[100];

// Algoritam koji generise sve permutacije datog niza
// Slozenost: O(n!)

void generatePermutations(int pos) {
  if (pos == n) {
    for (int i = 0; i < n; i++) printf("%d ", currPerm[i]);
    printf("\n");
  }
  for (int i = 0; i < n; i++) {
    if (!inPerm[i]) {
      currPerm[pos] = niz[i];
      inPerm[i] = true;
      generatePermutations(pos + 1);
      inPerm[i] = false;
    }
  }
}

int main() {
  n = 3;
  niz[0] = 1;
  niz[1] = 2;
  niz[2] = 3;
  generatePermutations(0);
  return 0;
}
