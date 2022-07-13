#include <iostream>
#include <list>

unsigned int offset = 1;

struct Vertex {
  std::list<int> to;
  bool visited;

  Vertex() : visited(false) { }
};

void DFS(Vertex v[], unsigned int i, std::list<int>& out) {
  if (!v[i].visited) {
    v[i].visited = true;
    for (int& neighbour : v[i].to) {
        DFS(v, neighbour, out);
    }
    out.push_front(i);
  }
}

int main()
{
  unsigned int numOfVertex;
  std::cin >> numOfVertex;

  Vertex* v = new Vertex[numOfVertex];

  unsigned int x, y;
  while (std::cin >> x >> y) {
    v[x - offset].to.push_back(y - offset);
  }

  std::list<int> out;
  for (unsigned int i = 0; i < numOfVertex; i++) {
    DFS(v, i, out);
  }

  for (int& o : out) {
    std::cout << o + offset << " ";
  }

  delete[] v;
}