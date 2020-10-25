/*
 Petar 'PetarV' Velickovic
 Data Structure: Binary Indexed Tree
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
using namespace std;
typedef long long lld;

int n;
int bit[MAX_N];

// Struktura za efikasno cuvanje kumulativnih suma
// Slozenost: O(log N) po operaciji

inline void update(int x, int val) {
  while (x <= n) {
    bit[x] += val;
    x += (x & -x);
  }
}

inline int read(int x) {
  int ret = 0;
  while (x > 0) {
    ret += bit[x];
    x -= (x & -x);
  }
  return ret;
}

int main() {
  n = 10;
  update(1, 1);
  update(3, 1);
  update(5, 5);
  update(2, -2);
  update(5, -1);
  printf("%d\n", read(6));
  return 0;
}
