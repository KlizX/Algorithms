#include <iostream>
#include <list>

unsigned int offset = 1;

struct Vertex {
  std::list<int> to;
  bool visited;

  Vertex() : visited(false) { }
};

void DFS(Vertex v[], unsigned int vStart, std::list<int>& path) {
  vStart -= offset;
  if (!v[vStart].visited) {
    path.push_back(vStart + offset);
    v[vStart].visited = true;
    for (int& neighbour : v[vStart].to) {
      DFS(v, neighbour, path);
    }
  }
}

int main(int argc, char** argv)
{
  unsigned int numOfVertex, vStart;
  std::cin >> numOfVertex >> vStart;

  Vertex* v = new Vertex[numOfVertex];

  unsigned int x, y;
  if (argc > 1) {
    if (std::string(argv[1]) == "-d") {
      while (std::cin >> x >> y) {
        v[x - offset].to.push_back(y);
      }
    }
  }
  else {
    while (std::cin >> x >> y) {
      v[x - offset].to.push_back(y);
      v[y - offset].to.push_back(x);
    }
  }

  std::list<int> path;
  DFS(v, vStart, path);
  for (int& vDFS : path) {
    std::cout << vDFS << " ";
  }

  delete[] v;
}