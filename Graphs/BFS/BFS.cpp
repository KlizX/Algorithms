#include <iostream>
#include <list>

unsigned int offset = 1;

struct Vertex {
  std::list<int> to;
  bool visited;

  Vertex() : visited(false) { }
};

void BFS(Vertex v[], int vStart, std::list<int>& path) {
  std::list<int> vl;
  vl.push_back(vStart);
  v[vStart].visited = true;
  while (!vl.empty()) {
    int vertex = vl.front();
    path.push_back(vertex + offset);
    for (int& neighbour : v[vertex].to) {
      if (!v[neighbour].visited) {
        vl.push_back(neighbour);
        v[neighbour].visited = true;
      }
    }
    vl.pop_front();
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
        v[x - offset].to.push_back(y - offset);
      }
    }
  }
  else {
    while (std::cin >> x >> y) {
      v[x - offset].to.push_back(y - offset);
      v[y - offset].to.push_back(x - offset);
    }
  }

  std::list<int> path;
  BFS(v, vStart - offset, path);
  for (int& vBFS : path) {
    std::cout << vBFS << " ";
  }

  delete[] v;
}