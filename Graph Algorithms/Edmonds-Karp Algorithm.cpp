/*
 Petar 'PetarV' Velickovic
 Algorithm: Edmonds-Karp Algorithm
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
#define MAX_N 500
#define INF 987654321
using namespace std;
typedef long long lld;

struct Node {
  vector<int> adj;
};
Node graf[MAX_N];
bool mark[MAX_N];
int cap[MAX_N][MAX_N];
int parent[MAX_N];

int v, e;
int s, t;

// Edmonds-Karpov algoritam za nalazenje maksimalnog protoka izmedju dva cvora u
// grafu Moze se koristiti i za nalazenje maksimalnog matchinga Slozenost: O(V *
// E^2)

inline int BFS() {
  int ret = 0;
  for (int i = 1; i <= v; i++) parent[i] = 0;
  queue<int> bfs_queue;
  queue<int> minCapacity;
  parent[s] = -1;
  bfs_queue.push(s);
  minCapacity.push(INF);
  while (!bfs_queue.empty()) {
    int xt = bfs_queue.front();
    int mt = minCapacity.front();
    bfs_queue.pop();
    minCapacity.pop();
    for (int i = 0; i < graf[xt].adj.size(); i++) {
      int xt1 = graf[xt].adj[i];
      if (cap[xt][xt1] > 0 && parent[xt1] == 0) {
        bfs_queue.push(xt1);
        minCapacity.push(min(mt, cap[xt][xt1]));
        parent[xt1] = xt;
        if (xt1 == t) {
          ret = min(mt, cap[xt][xt1]);
          break;
        }
      }
    }
  }
  if (ret > 0) {
    int currNode = t;
    while (currNode != s) {
      cap[parent[currNode]][currNode] -= ret;
      cap[currNode][parent[currNode]] += ret;
      currNode = parent[currNode];
    }
  }
  return ret;
}

inline int EdmondsKarp() {
  int flow = 0;
  while (true) {
    int currFlow = BFS();
    if (currFlow == 0)
      break;
    else
      flow += currFlow;
  }
  return flow;
}

int main() {
  v = 4, e = 5;
  s = 1, t = 4;

  graf[1].adj.push_back(2);
  graf[2].adj.push_back(1);
  cap[1][2] = 40;

  graf[1].adj.push_back(4);
  graf[4].adj.push_back(1);
  cap[1][4] = 20;

  graf[2].adj.push_back(4);
  graf[4].adj.push_back(2);
  cap[2][4] = 20;

  graf[2].adj.push_back(3);
  graf[3].adj.push_back(2);
  cap[2][3] = 30;

  graf[3].adj.push_back(4);
  graf[4].adj.push_back(3);
  cap[3][4] = 10;

  printf("%d\n", EdmondsKarp());

  return 0;
}
