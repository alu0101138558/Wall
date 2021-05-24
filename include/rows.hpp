#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Rows {

  private:

    vector<vector<int>> posibleRows_;
    vector<int> blocks_;
    int rowSize_;

  public:

    Rows (vector<int>& blocks, int& rowSize); 
    ~Rows();
    void printAllPosibilities (void) const;
    vector<vector<int>>& getPosibleRows (void);
    int getRowSize (void) const;

  private:

    void generatePosibleRows (vector<int> actualRow, int& actualBlock);
    int actualSizeOfRow (vector<int>& actualRow) const;
    bool solutionNoExist (vector<int>& actualRow) const;
};