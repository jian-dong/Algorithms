/*
 Petar 'PetarV' Velickovic
 Algorithm: Power Set
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

// Metoda koja generise partitivni skup nekog skupa
// Slozenost: O(2^n)

int n;
int skup[100];
bool inSet[100];

void powerSet(int pos) {
  if (pos == n) {
    for (int i = 0; i < n; i++)
      if (inSet[i]) printf("%d ", skup[i]);
    printf("\n");
    return;
  }
  inSet[pos] = false;
  powerSet(pos + 1);
  inSet[pos] = true;
  powerSet(pos + 1);
}

int main() {
  n = 3;
  skup[0] = 1;
  skup[1] = 2;
  skup[2] = 3;
  powerSet(0);
  return 0;
}
