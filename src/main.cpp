#include "../include/walls.hpp"

int main (void) {

  vector<int> posibleRows;
  posibleRows.push_back(2);
  posibleRows.push_back(3);
  posibleRows.push_back(5);

  int rowSize = 15;
  int heightWall = 3;

  Walls test (posibleRows, rowSize, heightWall);
  test.printAllPosibilities();
}