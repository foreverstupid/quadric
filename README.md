# Quadric
The console program that checks the quadric line type by the coordinates of the five points, that this line contains.

# Build

> make

# Usage

> ./quadric \<x1\> \<y1\> \<x2\> \<y2\> ... \<x5\> \<y5\>

Here \<xk\>, \<yk\> are XY-coordinates of some point.

**Note**: none four of the given points should be contained in the same straight line.

# Example

```
./quadric 0 1 1 0 0 -1 -1 0 0.7 0.7
Ellips

./quadric 0 1 1 0 0 -1 -1 0 0.5 0.5
Parallel lines
```
