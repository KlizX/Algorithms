#include <iostream>
#include <algorithm>
#include <vector>

struct Edge {
  int from;
  int to;
  int weight;

  Edge(int _from, int _to, int _weigth) : from(_from), to(_to), weight(_weigth) { }
  bool operator<(const Edge& e);
};

bool Edge::operator<(const Edge& e) {
  return weight < e.weight;
}

struct Tree {
  int* rank;
  int* parent;
  int maxRank;

  Tree(int n);
  int Find(int i);
  void Union(int x, int y);
};

Tree::Tree(int n) {
  maxRank = 1;
  parent = new int[n];
  rank = new int[n];

  for (int i = 0; i < n; i++) {
    parent[i] = -1;
    rank[i] = 1;
  }
}

int Tree::Find(int i) {
  if (parent[i] == -1)
    return i;

  return parent[i] = Find(parent[i]);
}

void Tree::Union(int x, int y) {
  if (rank[x] < rank[y]) {
    parent[x] = y;
    rank[y] += rank[x];
    maxRank = rank[y];
  }
  else {
    parent[y] = x;
    rank[x] += rank[y];
    maxRank = rank[x];
  }
}

void View(std::vector<Edge>& edges) {
  for (Edge& e : edges) {
    std::cout << e.from << " " << e.to << " " << e.weight << '\n';
  }
}

void MST(std::vector<Edge>& mst, std::vector<Edge>& edges, int n) {
  Tree t(n);

  int x, y;
  for (Edge& e : edges) {
    x = t.Find(e.from);
    y = t.Find(e.to);

    if (x != y) {
      t.Union(x, y);
      mst.push_back(e);
    }

    if (n < t.maxRank) {
      return;
    }
  }
}

int main() {
  std::vector<Edge> mst;
  {
    int nVertex;
    int from, to, weight;
    std::cin >> nVertex;
    std::vector<Edge> edges;
    while (std::cin >> from >> to >> weight) {
      edges.push_back(Edge(from, to, weight));
    }
    std::sort(edges.begin(), edges.end());
    MST(mst, edges, nVertex);
  }
  View(mst);
}