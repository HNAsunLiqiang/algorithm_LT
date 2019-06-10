//
//  BinaryTree.cpp
//  C_Plus_Project_Leet
//
//  Created by dida on 2019/2/21.
//  Copyright © 2019年 dida. All rights reserved.
//

using namespace std;

#include "BinaryTree.hpp"
#include <vector>
#include <queue>
#include <stack>
//vector<vector<int>> levelOrder(TreeNode* root) {
////    vector<vector<int>> result;
////    queue<TreeNode*> q;
////    q.push(root);
////    while (!q.empty()) {
////        vector<int> v;
////        int size = q.size();
////        for (int i = 0; i<size; i++) {
////            TreeNode *node = q.front();
////            if (node == nullptr) {
////                break;
////            }
////            v.push_back(node->val);
////            if (node->left) {
////                q.push(node->left);
////            }
////            if (node->right) {
////                q.push(node->right);
////            }
////            q.pop();
////        }
////        result.push_back(v);
////    }
////    return result;
//    
//    if (!root) return {};
//    vector<vector<int>> result;
//    queue<TreeNode*> q;
//    vector<int> cur_v;
//    q.push(root);
//    q.push(NULL);
//    while (!q.empty()) {
//        
//        TreeNode *node = q.front();
//        q.pop();
//        if (node == NULL) {
//            result.push_back(cur_v);
//            cur_v.resize(0);
//            if (!q.empty()) q.push(NULL);
//        } else {
//            cur_v.push_back(node->val);
//            if (node->left) q.push(node->left);
//            if (node->right) q.push(node->right);
//        }
//        
//    }
//    return result;
//    
////    if (!root) return {}; //Edge Case
////
////    queue<TreeNode*> q;
////    vector<vector<int> > result;
////    vector<int> cur_vec;
////
////    //Trick push NULL to maintain depth information
////    q.push(root);
////    q.push(NULL);
////
////    while(!q.empty())
////    {
////        TreeNode* curr = q.front(); q.pop();
////
////        if (curr==NULL)
////        {
////            result.push_back(cur_vec);
////            cur_vec.resize(0);
////            if (q.size() > 0) q.push(NULL);
////        }
////        else
////        {
////            cur_vec.push_back(curr->val);
////            if(curr->left!=NULL) q.push(curr->left);
////            if(curr->right!=NULL) q.push(curr->right);
////        }
////    }
////
////    return result;
//}
// 230. Kth Smallest Element in a BST
//int kthSmallest(TreeNode* root, int k) {
//    stack<TreeNode*> s;
//    s.push(root);
//    TreeNode *curNode = root;
//    int result;
////    while (!s.empty() || curNode) {
////        if (curNode) {
////            s.push(curNode);
////        }
////        if (curNode && curNode->left != NULL) {
////            curNode = curNode->left;
////        } else {
////            curNode = s.top();
////            k--;
////            if (k==0) {
////                result = curNode->val;
////                break;
////            }
////            s.pop();
////            curNode = curNode->right;
////        }
////    }
//    while (!s.empty() || curNode) {
//
//        if (curNode) {
//            s.push(curNode);
//            curNode = curNode->left;
//        } else {
//            curNode = s.top();
//            k--;
//            if (k==0) {
//                result = curNode->val;
//                break;
//            }
//            s.pop();
//            curNode = curNode->right;
//        }
//    }
//    return result;
//}
// [-1,0,3,-2,4,null,null,8]
// 236. Lowest Common Ancestor of a Binary Tree
//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//
//    vector<TreeNode*> v;
//    v.push_back(root);
//    int index = 0;
//    int index1 = 0;
//    int index2 = 0;
//    while (index < v.size()) {
//        TreeNode *node = v[index];
//        if (node->left) v.push_back(node->left);
//        if (node->right) v.push_back(node->right);
//        if (node == p) index1 = index;
//        if (node == q) index2 = index;
//        index++;
//    }
//
//    while (index1 != index2) {
//        int temp = max(index1, index2);
//        index1 = min(index1, index2);
//        index2 = temp;
//        for (int i = index2-1; i>=0; i--) {
//            if (v[i]->left == v[index2] || v[i]->right == v[index2]){
//                index2 = i;
//                break;
//            }
//        }
//    }
//
//    return v[index1];
//}


// 144. Binary Tree Preorder Traversal
// morris
//TreeNode* mostRightLeaf(TreeNode* node) {
//    TreeNode *mostRight = node;
//    while (mostRight && mostRight->right) {
//        mostRight = mostRight->right;
//    }
//    return mostRight;
//}
//
//vector<int> preorderTraversal(TreeNode* root) {
//    vector<int> result;
//    TreeNode *cur = root;
//    while (cur) {
//        TreeNode *mostRight = cur ->left;
//        if (mostRight) {
//            while (mostRight->right != NULL && mostRight->right != cur) {
//                mostRight = mostRight ->right;
//            }
//            if (mostRight->right == NULL) {
//                result.push_back(cur->val);
//                mostRight->right = cur;
//                cur = cur ->left;
//                continue;
//            } else {
//                mostRight->right = NULL;
//            }
//        } else {
//            result.push_back(cur->val);
//        }
//        cur = cur->right;
//    }
//
//    return result;
//}

// 94. Binary Tree Inorder Traversal
//vector<int> inorderTraversal(TreeNode* root) {
//    vector<int> result;
//    TreeNode *cur = root;
//    while (cur) {
//        TreeNode *mostRight = cur ->left;
//        if (mostRight) {
//            while (mostRight->right != NULL && mostRight->right != cur) {
//                mostRight = mostRight ->right;
//            }
//            if (mostRight->right == NULL) {
//                mostRight->right = cur;
//                cur = cur ->left;
//                continue;
//            } else {
//                result.push_back(cur->val);
//                mostRight->right = NULL;
//            }
//        } else {
//            result.push_back(cur->val);
//        }
//        cur = cur->right;
//    }
//
//    return result;
//}

// 145. Binary Tree Postorder Traversal
//vector<int> postorderTraversal(TreeNode* root){
//    vector<int> result;
//    TreeNode *cur = root;
//    while (cur) {
//        TreeNode *mostRight = cur ->left;
//        if (mostRight) {
//            while (mostRight->right != NULL && mostRight->right != cur) {
//                mostRight = mostRight ->right;
//            }
//            if (mostRight->right == NULL) {
//                mostRight->right = cur;
//                cur = cur ->left;
//                continue;
//            } else {
//                result.push_back(cur->val);
//                mostRight->right = NULL;
//            }
//        } else {
//            result.push_back(cur->val);
//        }
//        cur = cur->right;
//    }
//
//    return result;
//}


void morrisPreTraversal(TreeNode* head) {
    
    TreeNode *cur = head;
    
    while (cur) {
        if (cur->left) {
            TreeNode *mostRight = cur->left;
            while (mostRight->right != NULL && mostRight->right != cur) {
                mostRight = mostRight->right;
            }
            if (mostRight->right == NULL) {
                mostRight->right = cur;
                cur = cur->left;
            } else if(mostRight->right == cur) {
                cur = mostRight->right;
                mostRight->right = NULL;
                cur = cur-> right;
            }
            
        } else {
            cur = cur-> right;
        }
    }
    
}

// 333. Largest BST Subtree

struct returnData {
    TreeNode *head;
    int size;
    int max;
    int min;
    returnData(TreeNode *head,int size,int max,int min):head(head),size(size),max(max),min(min){}
};

returnData BSTSubProcess(TreeNode* node) {
    
    if (node == NULL) {
        return returnData(NULL, 0, INT_MIN, INT_MAX);
    }
    
    returnData leftData = BSTSubProcess(node->left);
    returnData rightData = BSTSubProcess(node->right);
    
    int includeSelfSize = 0;
    if (leftData.head == node->left && rightData.head == node->right && leftData.max < node->val && rightData.min > node->val) {
        includeSelfSize = leftData.size + 1 + rightData.size;
    }
    
    int maxSize = max(includeSelfSize, max(leftData.size, rightData.size));
    TreeNode *head = ( maxSize == includeSelfSize?node:((leftData.size>rightData.size)?leftData.head:rightData.head) );
    return returnData(head, maxSize, max(leftData.max, rightData.max), min(leftData.min, rightData.min));
    
}

TreeNode* largestBSTSubtree(TreeNode* root){
    return BSTSubProcess(root).head;
}

struct isBReturnData {
    bool isB;
    int h;
    isBReturnData(bool isB,int h): isB(isB),h(h){};
};

isBReturnData isBProcess(TreeNode* node) {
    if (node == NULL) {
        return isBReturnData(true, 0);
    }
    isBReturnData leftData = isBProcess(node->left);
    isBReturnData rightData = isBProcess(node->right);
    
    if (leftData.isB == false || rightData.isB == false) {
        return isBReturnData(false, 0);
    }
    if (abs(leftData.h - rightData.h) > 1) {
        return isBReturnData(false, 0);
    }
    return isBReturnData(true, max(leftData.h, rightData.h)+1);
}


// 103. Binary Tree Zigzag Level Order Traversal
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*>queue;
    queue.push(root);
    bool isLeftToRight = true;
    while (!queue.empty()) {
        int size = queue.size();
        int curIndex = 0;
        vector<int> row(size);
        while (size > 0) {
            if (isLeftToRight) {
                row[]
            }
            if (queue.front()->left) {
                queue.push(queue.front()->left);
            }
            if (queue.front()->right) {
                queue.push(queue.front()->right);
            }
        }
    }
    
    return res;
}
