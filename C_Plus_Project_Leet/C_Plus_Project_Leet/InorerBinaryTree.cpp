//
//  InorerBinaryTree.cpp
//  C_Plus_Project_Leet
//
//  Created by dida on 2019/1/28.
//  Copyright © 2019年 dida. All rights reserved.
//

#include "InorerBinaryTree.hpp"
#include<stack>

// Definition for a binary tree node.
//void inorderNode(TreeNode* node , vector<int>* v) {
//    if (node == NULL) {
//        return;
//    }
//    inorderNode(node->left,v);
//    v->push_back(node->val);
//    inorderNode(node->right,v);
//}
//
//vector<int> inorderTraversal(TreeNode* root) {
//    vector<int> vi;
//    inorderNode(root,&vi);
//    return vi;
//
//}
// [1,null,2,3]
//void inorderNode(TreeNode* node , vector<int>* v) {
//
//    TreeNode *head = node;
//    stack<TreeNode*> s;
//    while (!s.empty() || head != NULL) {
//        if (head != NULL) {
//            s.push(head);
//            head = head->left;
//        } else {
//            head = s.top();
//            v->push_back(head->val);
//            s.pop();
//            head = head->right;
//        }
//    }
//}

void inorderNode(TreeNode* node , vector<int>* v) {
    stack<TreeNode*>s;
    TreeNode *head = node;
    if (head != NULL) {
        // 此路不通
        s.push(head);
        while (!s.empty()) {
            if (head->right != NULL) {
                s.push(head->right);
            }
            if (head->left != NULL) {
                s.push(head->left);
            }
        }
        
    }
}


//void preorderNode(TreeNode* node , vector<int>* v) {
//    if (node == NULL) {
//        return;
//    }
//    v->push_back(node->val);
//    preorderNode(node->left, v);
//    preorderNode(node->right, v);
//}

void preorderNode(TreeNode* node , vector<int>* v) {
//    stack<TreeNode*>s;
//    TreeNode *head = node;
//    while (head != NULL || !s.empty()) {
//        if (head != NULL) {
//            v->push_back(head->val);
//            s.push(head);
//            head = head->left;
//        } else {
//            head = s.top()->right;
//            s.pop();
//        }
//    }
    stack<TreeNode*>s;
    TreeNode *head = node;
    if (head != NULL) {
        s.push(head);
        
        if (!s.empty()) {
            head = s.top();
            v->push_back(head->val);
            s.pop();
            if (head->right != NULL) {
                s.push(head->right);
            }
            if (head->left != NULL) {
                s.push(head->left);
            }
        }
    }
    
    
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vi;
    preorderNode(root, &vi);
    return vi;
}
// [1,null,2,3]

void postOrderNode(TreeNode* node,vector<int>* v) {
    
    if (node != NULL) {
        stack<TreeNode*> s1;
        //        stack<TreeNode*> s2;
        TreeNode *head = node;
        s1.push(head);
        while (!s1.empty()) {
            head = s1.top();
            s1.pop();
            if (head != NULL) {
                v -> insert(v->begin(), head->val);
                if (head->left != NULL) {
                    s1.push(head->left);
                }
                if (head->right != NULL) {
                    s1.push(head->right);
                }
            }
            
        }
    }
    
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> vi;
    postOrderNode(root, &vi);
    return vi;
}






