/*
 Petar 'PetarV' Velickovic
 Algorithm: Breadth-First Search
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

// Algoritam za pretrazivanje grafa u sirinu
// Slozenost: O(V + E)

inline void BFS(int start) {
  queue<int> bfs_queue;
  bfs_queue.push(start);
  while (!bfs_queue.empty()) {
    int xt = bfs_queue.front();
    bfs_queue.pop();
    mark[xt] = true;
    printf("Traversing Node ID %d\n", xt);
    for (int i = 0; i < graf[xt].adj.size(); i++) {
      if (!mark[graf[xt].adj[i]]) {
        bfs_queue.push(graf[xt].adj[i]);
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
  BFS(0);
  return 0;
}
