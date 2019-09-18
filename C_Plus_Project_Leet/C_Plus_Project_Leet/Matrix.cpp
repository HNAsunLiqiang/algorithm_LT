//
//  Matrix.cpp
//  C_Plus_Project_Leet
//
//  Created by dida on 2019/6/26.
//  Copyright © 2019 dida. All rights reserved.
//

using namespace std;

#include "Matrix.hpp"
//#include <vector>
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
// a判断9*9的矩阵每一行、每一列、每个3*3的子矩阵，是否有重复的数字出行，若有返回false，否则返回ture。
// 首先遍历过程肯定要记录遍历过的元素，此时选择三个数组分别代表行、列、子矩阵，每个数字存储9个int数字，初始化为0。
// 利用位运算，二进制的第0位代表0，第一位代表1。。。，遍历过程判断当前行是否有标记过，若有返回false，否则把响应位置置1。列和子矩阵同理。
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
            int bitmove = digit-1;
            if (( (1 << bitmove) & rowMarks[row] ) == 0) {
                rowMarks[row] |= (1 << bitmove);
            }else {
                return false;
            }
            if (( (1 << bitmove) & colMarks[col] ) == 0) {
                colMarks[col] |= (1 << bitmove);
            }else {
                return false;
            }
            
            if (( (1 << bitmove) & subSudoMarks[(row/3)*3+col/3] ) == 0) {
                subSudoMarks[(row/3)*3+col/3] |= (1 << bitmove);
            }else {
                return false;
            }
        }
    }
    return true;
}
// 利用一个set数据结构和“编码”的方式来唯一记录一个位置的元素是否出现过。如第一行出行的3记录为“1（3）”，
//1、set和hashset都不允许元素重复，但是set是有序的，hashset无顺序，所以向set插入元素必须重载<操作符比较大小，而hashset只需重载equal()，比较是否相等即可。
// 2、set底层数据结构为红黑树，索引时间为log(n)，而hashset基于哈希表，比set要快一些，log(1)。
// https://leetcode.com/problems/valid-sudoku/discuss/15472/Short%2BSimple-Java-using-Strings
//public boolean isValidSudoku1(char[][] board) {
//    Set seen = new HashSet();
//    for (int i=0; i<9; ++i) {
//        for (int j=0; j<9; ++j) {
//            char number = board[i][j];
//            if (number != '.')
//                if (!seen.add(number + " in row " + i) ||
//                    !seen.add(number + " in column " + j) ||
//                    !seen.add(number + " in block " + i/3 + "-" + j/3))
//                    return false;
//        }
//    }
//    return true;
//}


// 73. Set Matrix Zeroes
// 给一个m*n的矩阵，当某个元素为0时，设置它所在的行和列都为0。要求控件复杂度为常数
// m+n空间复杂度的方法。准备两个数组mn，分别存某行/列是否存在0。
// 常数时间复杂度的方法。利用第一行和第一列来作为记录数组。再记录前先遍历第一行和第一列判断是否存在0。

void setZeroes(vector<vector<int>>& matrix) {
//    setZerosInMartix(matrix, 0, 0, matrix[0].size()-1, matrix.size()-1);
    
    bool firtRowIsZero = false,firtColIsZero = false;
    for (int c = 0; c < matrix[0].size(); c++) {
        if(matrix[0][c] == 0) {
            firtRowIsZero = true;
            break;
        }
    }
    for (int r = 0; r < matrix.size(); r++) {
        if(matrix[r][0] == 0) {
            firtColIsZero = true;
            break;
        }
    }
    for (int c = 1; c < matrix[0].size(); c++) {
        for (int r = 1; r < matrix.size(); r++) {
            if (matrix[r][c] == 0) {
                matrix[0][c] = 0;
                matrix[r][0] = 0;
            }
        }
    }
    for (int c = 1;  c < matrix[0].size(); c++) {
        if (matrix[0][c] == 0) {
            int r = 1;
            while (r < matrix.size()) {
                matrix[r][c] = 0;
                r++;
            }
        }
        if (firtRowIsZero) {
            matrix[0][c] = 0;
        }
    }
    for (int r = 1;  r < matrix.size(); r++) {
        if (matrix[r][0] == 0) {
            int c = 1;
            while (c < matrix[0].size()) {
                matrix[r][c] = 0;
                c++;
            }
        }
        if (firtColIsZero) {
            matrix[r][0] = 0;
        }
    }
    if (firtColIsZero || firtRowIsZero) {
        matrix[0][0] = 0;
    }
    
}

// 240. Search a 2D Matrix II
// 行、列有序的矩阵中判断value是否存在。
// 从左下或者右上开始遍历矩阵。
// ，例如从左下。
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rowCount = matrix.size();
    if (rowCount == 0) return false;
    int colCount = matrix[0].size();
    
    int row = rowCount-1 , col = 0;
    
    while (row >=0 && col < colCount) { //超出边界仍未找到则不存在这个value
        if (matrix[row][col] == target) {
            return true;
        }else if (matrix[row][col] < target){ //当前数大于value，向右移动
            col += 1;
        }else{ //当前数大于value，向上移动
            row -= 1;
        }
    }
    return false;
}
