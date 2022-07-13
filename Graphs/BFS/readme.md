Input file format:
n s
x y
x y
x y
x y

First row:
n - number of all vertex
s - vertex from which start travelling over others vertex

Any other row:
x y - From vertex x there is an edge to vertex y.

!Vertex should be counted from 1 to n.

Algorithm works by default for undirected graphs. So by default if there is an edge between x and y that means there is also an edge between y and x. In order to make it work for directed graph