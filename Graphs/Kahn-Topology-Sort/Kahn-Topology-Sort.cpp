#include <iostream>
#include <list>

unsigned int offset = 1;

struct Vertex {
  std::list<int> to;
  unsigned int numOfNeighbours;
  bool visited;

  Vertex() : numOfNeighbours(0), visited(false) { }
};

void Kahn(Vertex v[], unsigned int n, std::list<int>& out) {
  std::list<int> in;
  for (unsigned int i = 0; i < n; i++) {
    if (v[i].numOfNeighbours == 0) {
      in.push_back(i);
    }
  }
  int tmp;
  while (!in.empty()) {
    tmp = in.front();
    in.pop_front();
    out.push_back(tmp);
    for (int& neighbour : v[tmp].to) {
      v[neighbour].numOfNeighbours--;
      if (v[neighbour].numOfNeighbours == 0) {
        in.push_back(neighbour);
      }
    }
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
    v[y - offset].numOfNeighbours++;
  }

  std::list<int> out;
  Kahn(v, numOfVertex, out);

  for (int& o : out) {
    std::cout << o + offset << " ";
  }

  delete[] v;
}