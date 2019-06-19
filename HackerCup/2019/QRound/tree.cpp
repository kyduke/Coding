// https://www.facebook.com/hackercup/problem/330920680938986/
// Incorrect

#include <iostream>
#include <set>

using namespace std;

const int SIZE = 61;

int parent[SIZE];
int depth[SIZE];
int query[SIZE * 2][3];
set<int> children[SIZE];
set<int> visited;
set<int> found;

void printChildren(int n) {
  set<int>::iterator it;
  int i;

  for (i = 1; i <= n; i++) {
    printf("%d: [", i);
    for (it = children[i].begin(); it != children[i].end(); it++) {
      printf("%d, ", *it);
    }
    printf("]\n");
  }
}

void init(int n) {
  int i;

  for (i = 0; i <= n; i++) {
    parent[i] = 0;
    children[i].clear();
  }
}

void findChildren(int p) {
  set<int>::iterator it;

  if (visited.find(p) != visited.end()) return;
  visited.insert(p);

  for (it = children[p].begin(); it != children[p].end(); it++) {
    found.insert(*it);
    findChildren(*it);
  }
}

bool removeIndirectChildren(int n) {
  set<int>::iterator it;
  int i;

  for (i = 1; i <= n; i++) {
    visited.clear();
    found.clear();
    visited.insert(i);
    for (it = children[i].begin(); it != children[i].end(); it++) {
      findChildren(*it);
    }

    if (found.find(i) != found.end()) return false;

    for (it = found.begin(); it != found.end(); it++) {
      children[i].erase(*it);
    }
  }

  return true;
}

bool updateParent(int n, int p) {
  set<int> s;
  children[p].erase(n);

  s.insert(n);
  s.insert(p);
  while (parent[n] != 0) {
    n = parent[n];
    if (s.find(n) != s.end()) return false;
    s.insert(n);
  }

  children[p].insert(n);
  parent[n] = p;

  return true;
}

void setDepth(int n, int d) {
  set<int>::iterator it;

  depth[n] = d;
  d++;
  for (it = children[n].begin(); it != children[n].end(); it++) {
    setDepth(*it, d);
  }
}

int getLCA(int u, int v) {
  while (u != v) {
    if (depth[u] > depth[v]) {
      u = parent[u];
    } else if (depth[u] < depth[v]) {
      v = parent[v];
    } else {
      u = parent[u];
      v = parent[v];
    }
  }

  return u;
}

bool checkTree(int m) {
  int i;

  for (i = 0; i < m; i++) {
    if (getLCA(query[i][0], query[i][1]) != query[i][2]) {
      return false;
    }
  }

  return true;
}

int main(int argc, char** argv) {
  set<int> s;
  set<int>::iterator it;
  int t, ti, n, m, i, r;
  bool loop;

  scanf("%d", &t);
  for (ti = 1; ti <= t; ti++) {
    scanf("%d %d", &n, &m);

    init(n);

    for (i = 0; i < m; i++) {
      scanf("%d %d %d", &query[i][0], &query[i][1], &query[i][2]);
      if (query[i][0] != query[i][2]) {
        children[ query[i][2] ].insert(query[i][0]);
      }
      if (query[i][1] != query[i][2]) {
        children[ query[i][2] ].insert(query[i][1]);
      }
    }

    // printChildren(n);

    loop = !removeIndirectChildren(n);

    // printChildren(n);

    if (loop == false) {
      for (i = 1; i <= n; i++) {
        s = children[i];
        for (it = s.begin(); it != s.end(); it++) {
          loop = !updateParent(*it, i);
          if (loop == true) break;
        }
        if (loop == true) break;
      }
    }

    // printChildren(n);

    if (loop == false) {
      for (i = 1; i <= n; i++) {
        s.clear();
        s.insert(i);
        r = i;
        while (parent[r] != 0) {
          r = parent[r];
          if (s.find(r) != s.end()) {
            loop = true;
            break;
          }
          s.insert(r);
        }
        if (loop == true) break;
      }
    }

    if (loop == false) {
      r = 0;
      for (i = 1; i <= n; i++) {
        if (parent[i] == 0) {
          if (r == 0) {
            r = i;
          } else {
            children[r].insert(i);
            parent[i] = r;
          }
        }
      }

      setDepth(r, 0);
    }

    printf("Case #%d: ", ti);
    if (loop == false && checkTree(m) == true) {
      for (i = 1; i <= n; i++) {
        printf("%d ", parent[i]);
      }
      printf("\n");
    } else {
      printf("Impossible\n");
    }
  }

  return 0;
}

/*
6
3 1
1 2 3
3 3
1 2 2
2 3 3
3 1 1
4 2
2 1 2
1 4 3
6 3
2 4 3
6 5 4
1 2 6
7 4
7 3 5
4 1 2
6 3 6
6 4 5
12 9
1 5 7
11 2 6
9 4 12
8 12 6
10 1 7
4 3 12
3 10 6
8 11 8
2 5 10
=====
Case #1: 3 3 0
Case #2: Impossible
Case #3: 3 0 2 3
Case #4: Impossible
Case #5: 2 0 6 5 2 5 5
Case #6: 7 10 12 12 10 0 6 6 12 7 8 6
*/
