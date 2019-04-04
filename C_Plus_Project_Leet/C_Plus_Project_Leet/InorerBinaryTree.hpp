//
//  InorerBinaryTree.hpp
//  C_Plus_Project_Leet
//
//  Created by dida on 2019/1/28.
//  Copyright © 2019年 dida. All rights reserved.
//

#ifndef InorerBinaryTree_hpp
#define InorerBinaryTree_hpp

#include <stdio.h>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root);
};
#endif /* InorerBinaryTree_hpp */
