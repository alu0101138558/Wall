#pragma once
#include "../include/rows.hpp"

class Walls {

  private:
    
    vector<vector<vector<int>>> posibleWalls_;
    Rows posibleRows_;
    int heightWall_;

  public:

    Walls (vector<int>& blocks, int& rowSize, int& heightWall);
    ~Walls();
    void printAllPosibilities (void) const;
  
  private:

    void generatePosibleWalls (vector<vector<int>> actualWall, int& actualRow);
    bool areRowsBalanced (vector<vector<int>>& actualWall) const;
};