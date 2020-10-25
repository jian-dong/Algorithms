/*
 Petar 'PetarV' Velickovic
 Algorithm: Depth-First Search
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

struct Node {
  vector<int> adj;
};
Node graf[MAX_N];
bool mark[MAX_N];

// Algoritam za pretrazivanje grafa u dubinu
// Slozenost: O(V + E)

inline void DFS(int start) {
  stack<int> dfs_stek;
  dfs_stek.push(start);
  while (!dfs_stek.empty()) {
    int xt = dfs_stek.top();
    dfs_stek.pop();
    mark[xt] = true;
    printf("Traversing Node ID %d\n", xt);
    for (int i = 0; i < graf[xt].adj.size(); i++) {
      if (!mark[graf[xt].adj[i]]) {
        dfs_stek.push(graf[xt].adj[i]);
        mark[graf[xt].adj[i]] = true;
      }
    }
  }
}

int main() {
  graf[0].adj.push_back(1);
  graf[0].adj.push_back(2);
  graf[2].adj.push_back(3);
  graf[3].adj.push_back(4);
  DFS(0);
  return 0;
}
