/*
 Petar 'PetarV' Velickovic
 Algorithm: Euclidean Algorithm
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

// Euklidov algoritam za racunanje najveceg zajednickog delioca (NZD) dva broja
// Slozenost: O(log^2 N)

int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int main() {
  printf("%d\n", gcd(6, 15));
  return 0;
}
