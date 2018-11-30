#include <iostream>
#include <iostream>
#include <search.h>
#include <climits>
#include <cstdlib>

// C program to demonstrate insert operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h>

using namespace std;

struct Node {
    int value;
    struct Node * left;
    struct Node * right;
};

struct Node * newNode(int k) {
    struct Node * node = (struct Node *)(malloc(sizeof(Node)));
    node->left = NULL;
    node->right = NULL;
    node->value = k;
    return node;
}

struct Node * search(Node * node, int k) {
    if (node->value == k) {
        return node;
    }
    if (k <= node->value) {
        return search(node->left, k);
    } else {
        return search(node->right, k);
    }
    return NULL;
}

struct Node * insert(Node * node, int k) {
    if (node == NULL) {
        return newNode(k);
    }
    if (k <= node->value) {
        node->left = insert(node->left, k);
    } else {
        node->right = insert(node->right, k);
    }
}

// struct Node * deleteNodeMy(Node * node, int k) {
//     if (node == NULL) return node;
//     if (k < node->value) deleteNodeMy(node->left, k);
//     else if (k > node->value) deleteNodeMy(node->right, k);
//     else {
//         if (node->left == NULL) {
//             struct Node * tmp = node->right;
//             free(node);
//             return tmp;
//         }
//         if (node->right == NULL) {
//             struct Node * tmp = node->left;
//             free(node);
//             return tmp;
//         }
//         struct Node * minHere = node;
//         while (minHere->left != NULL) minHere = minHere->left;
//         node->value = minHere->value;
//         node->right = deleteNodeMy(node->right, minHere->value);
//     } 
//     return node;
// }

struct Node * deleteNode(struct Node * root, int value) 
{ 
    if (root == NULL) return root; 
    if (value < root->value) 
        root->left = deleteNode(root->left, value); 
    else if (value > root->value) 
        root->right = deleteNode(root->right, value); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct Node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct Node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct Node* temp = root->right;
        while (temp->left != NULL) temp = temp->left;
        root->value = temp->value; 
        root->right = deleteNode(root->right, temp->value); 
    } 
    return root; 
} 

int treeHeight(struct Node *root)
{
    if (root == NULL) return 0;
    int leftRootHeight = 1 + treeHeight(root->right);
    int rightRootHeight = 1 + treeHeight(root->left);
    return leftRootHeight > rightRootHeight ? leftRootHeight : rightRootHeight;
}

void inorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->value); 
        inorder(root->right); 
    } 
}

bool isBalanced(struct Node * root) {
    if (root == NULL) return true;

    int left = treeHeight(root->left);
    int right = treeHeight(root->right);

    if (abs(left - right) <= 1) return isBalanced(root->left) && isBalanced(root->right);

    return false;
}

int main()
{
    struct Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 

    // struct Node *searched = search(root, 20);
    // printf("%d \n", searched->value);

    // searched = search(root, 30);
    // printf("%d \n", searched->value);

    // searched = search(root, 70);
    // printf("%d \n", searched->value);

    // searched = search(root, 80);
    // printf("%d \n", searched->value);

    // cout << "-----" << endl;
 
    // inorder(root);

    // root = deleteNode(root, 40);

    // cout << "-----" << endl;

    // inorder(root);

    //cout << treeHeight(root) << endl;
    //cout << isBalanced(root) << endl;

    struct Node * root2 = NULL;
    root2 = insert(root2, 8);
    insert(root2, 3);
    insert(root2, 10);
    insert(root2, 1);
    insert(root2, 6);
    insert(root2, 4);
    insert(root2, 7);
    insert(root2, 14);
    insert(root2, 13);

    inorder(root2);
    cout << "ssss" << endl;
    deleteNode(root2, 6);
    inorder(root2);

    //cout << isBalanced(root2) << endl;
}