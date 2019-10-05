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
// 之字形层序遍历：还是用队列来层序遍历。设置一个标记表示该层是左-右还是右-左，初始化一个每层大小的数组，如果左到右就从左侧开始添加数据，反之相反。
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*>queue;
    queue.push(root);
    bool isLeftToRight = true;
    while (!queue.empty()) {
        int size = queue.size();
        int curIndex = 0;
        vector<int> row(size);
        while (curIndex < size) {
            if (isLeftToRight) {
                row[curIndex] = queue.front()->val;
            } else {
                row[size-curIndex-1] = queue.front()->val;
            }
            if (queue.front()->left) {
                queue.push(queue.front()->left);
            }
            if (queue.front()->right) {
                queue.push(queue.front()->right);
            }
            queue.pop();
            curIndex++;
        }
        isLeftToRight = !isLeftToRight;
        res.push_back(row);
    }
    
    return res;
}

// 105. Construct Binary Tree from Preorder and Inorder Traversal
// 用出前序和中序还原二叉树
// // 前序遍历对的第一个元素pre[0]，是当前树的跟节点root，根据pre[0]可以将中序遍历结果min分割成两部分left、right，分别是以root为根节点的左右子树，递归这个过程。
void construct(TreeNode* root,vector<int>& preorder, vector<int>& inorder);
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0) {
        return NULL;
    }
    TreeNode *root = new TreeNode(preorder[0]);
    
    construct(root, preorder, inorder);
    return root;
}

void construct(TreeNode* root,vector<int>& preorder, vector<int>& inorder){
    vector<int> inOrderleft,inOrderright;
    bool beforeRoot = true;
    // 每次都从0开始找效率较低，可以把上一次递归的中序开始和结束位置传进来，从开始位置开始遍历
    for (int i = 0; i<inorder.size(); i++) {
        if (inorder[i] == root->val) {
            beforeRoot = false;
            continue;
        }
        // 每次都产生新数组效率较低，可以用索引传进来来决定数组的开始和结束位置，不必分割数组
        if (beforeRoot) inOrderleft.push_back(inorder[i]);
        if (!beforeRoot) inOrderright.push_back(inorder[i]);
    }
    if (inOrderleft.size() != 0) {
        TreeNode *childL = new TreeNode(preorder[1]);
        root->left = childL;
        vector<int> preorderLeft(preorder.begin()+1,preorder.begin()+1+inOrderleft.size());
        construct(childL, preorderLeft, inOrderleft);
    }
    if (inOrderright.size() != 0) {
        TreeNode *childR = new TreeNode(preorder[1+inOrderleft.size()]);
        root->right = childR;
        vector<int> preorderRight(preorder.begin()+1+inOrderleft.size(),preorder.end());
        construct(childR, preorderRight, inOrderright);
    }
}
// 一个好的解法，思路相同，参数不同，不需要分割数组
/*
 public TreeNode buildTree(int[] preorder, int[] inorder) {
 return helper(0, 0, inorder.length - 1, preorder, inorder);
 }
 
 public TreeNode helper(int preStart, int inStart, int inEnd, int[] preorder, int[] inorder) {
 if (preStart > preorder.length - 1 || inStart > inEnd) {
 return null;
 }
 TreeNode root = new TreeNode(preorder[preStart]);
 int inIndex = 0; // Index of current root in inorder
 for (int i = inStart; i <= inEnd; i++) {
 if (inorder[i] == root.val) {
 inIndex = i;
 }
 }
 root.left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder);
 root.right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);
 return root;
 }
*/


// 617. 合并二叉树
// 递归
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL) {
        return t2;
    }
    if (t2 == NULL) {
        return t1;
    }
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}
