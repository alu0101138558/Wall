#include "../include/walls.hpp"

Walls :: Walls (vector<int>& blocks, int& rowSize, int& heightWall):
posibleRows_(blocks, rowSize),
heightWall_(heightWall)
{
  vector<vector<int>> actualWall;
  for (int i = 0; i < posibleRows_.getPosibleRows().size(); i++) {
    generatePosibleWalls(actualWall, i);
  }
}

Walls :: ~Walls () {
  posibleWalls_.clear();
}

void Walls :: printAllPosibilities (void) const {
  for (int i = 0; i < posibleWalls_.size(); i++) {
    cout << "\nMuro " << i + 1 << ":\n";
    for (int j = 0; j < posibleWalls_[i].size(); j++) {
      cout << "|";
      for (int k = 0; k < posibleWalls_[i][j].size(); k++) {
        for (int l = 0; l < posibleWalls_[i][j][k]; l++) {
          cout << "x";
        }
        cout << "|";
      }
      cout << "\n";
    }
  }
}

void Walls :: generatePosibleWalls (vector<vector<int>> actualWall, int& actualRow) {
  if (actualWall.size() == heightWall_ && areRowsBalanced(actualWall) && solutionNoExist(actualWall)) {
    posibleWalls_.push_back(actualWall);
  } else if (actualWall.size() > heightWall_) {
    return;
  } else {
    actualWall.push_back(posibleRows_.getPosibleRows()[actualRow]);
    if (areRowsBalanced(actualWall)) {
        for (int i = 0; i < posibleRows_.getPosibleRows().size(); i++) {
        generatePosibleWalls (actualWall, i);
      } 
    } else {
      return;
    }
  }
}

bool Walls :: areRowsBalanced (vector<vector<int>>& actualWall) const {
  if (actualWall.size() >= 2) {
    int row1 = actualWall[actualWall.size() - 1][0];
    int row2 = actualWall[actualWall.size() - 2][0];
    int positionRow1 = 1;
    int positionRow2 = 1;
    while (row1 != posibleRows_.getRowSize() || row2 != posibleRows_.getRowSize()) {
      if (row1 == row2) {
        return false;
      } else if (row1 > row2) {
        row2 += actualWall[actualWall.size() - 2][positionRow2];
        positionRow2++;
      } else {
        row1 += actualWall[actualWall.size() - 1][positionRow1];
        positionRow1++;
      }
    }
  }
  return true;
}

bool Walls :: solutionNoExist (vector<vector<int>>& actualWall) const {
  for (int i = 0; i < posibleWalls_.size(); i++) {
    if (actualWall == posibleWalls_[i]){
      return false;
    }
  }
  return true;
}