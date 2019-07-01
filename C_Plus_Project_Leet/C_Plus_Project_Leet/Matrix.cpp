//
//  Matrix.cpp
//  C_Plus_Project_Leet
//
//  Created by dida on 2019/6/26.
//  Copyright © 2019 dida. All rights reserved.
//

using namespace std;

#include "Matrix.hpp"
#include <vector>
#include <queue>
#include "Array.hpp"

// 378. Kth Smallest Element in a Sorted Matrix
// 大根堆
int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> queue;
    for (int i = 0 ; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            queue.push(matrix[i][j]);
            if (queue.size() == k+1) queue.pop();
        }
    }
    return queue.top();
}

// 36. Valid Sudoku
bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> rowMarks(9,0);
    vector<int> colMarks(9,0);
    vector<int> subSudoMarks(9,0);
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                continue;
            }
            int digit = board[row][col] - '0';
            if (digit < 1 || digit > 9) {
                return false;
            }
            if (( (1 << digit) & rowMarks[digit] ) == 0) {
                rowMarks[digit] |= (1 << digit);
            }else {
                return false;
            }
            if (( (1 << digit) & colMarks[digit] ) == 0) {
                colMarks[digit] |= (1 << digit);
            }else {
                return false;
            }
            
            if (( (1 << digit) & subSudoMarks[(row/3)*3+col/3] ) == 0) {
                subSudoMarks[(row/3)*3+col/3] |= (1 << digit);
            }else {
                return false;
            }
        }
    }
    return true;
}
