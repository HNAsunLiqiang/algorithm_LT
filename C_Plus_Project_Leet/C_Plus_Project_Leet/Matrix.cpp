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
