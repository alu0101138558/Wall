#include "../include/rows.hpp"

Rows :: Rows (vector<int>& blocks, int& rowSize):
blocks_(blocks),
rowSize_(rowSize)
{
  vector<int> actualRow;
  for (int i = 0; i < blocks.size(); i++) {
    generatePosibleRows(actualRow, i);
  }
}

Rows :: ~Rows() {
  posibleRows_.clear();
  blocks_.clear();
}

void Rows :: printAllPosibilities (void) const {
  for (int i = 0; i < posibleRows_.size(); i++) {
    cout << "\nFila " << i + 1 << ":\n|";
    for (int j = 0; j < posibleRows_[i].size(); j++) { 
      for (int k = 0; k < posibleRows_[i][j]; k++) {
        cout << "x";
      }
      cout << "|";
    }
    cout << "\n";
  }
}

vector<vector<int>>& Rows :: getPosibleRows (void) {
  return posibleRows_;
}

int Rows :: getRowSize (void) const {
  return rowSize_;
}

void Rows :: generatePosibleRows (vector<int> actualRow, int& actualBlock) {
  if (actualSizeOfRow(actualRow) == rowSize_ && solutionNoExist(actualRow)) {
    posibleRows_.push_back(actualRow);
  } else if (actualSizeOfRow(actualRow) > rowSize_) {
    return;
  } else {
    actualRow.push_back(blocks_[actualBlock]);
    for (int i = 0; i < blocks_.size(); i++) {
      generatePosibleRows (actualRow, i);
    } 
  }
}

int Rows :: actualSizeOfRow (vector<int>& actualRow) const {
  int size = 0;
  for (int i = 0; i < actualRow.size(); i++) {
    size += actualRow[i];
  }
  return size;
}

bool Rows :: solutionNoExist (vector<int>& actualRow) const {
  for (int i = 0; i < posibleRows_.size(); i++) {
    if (posibleRows_[i] == actualRow) {
      return false;
    }
  }
  return true;
}