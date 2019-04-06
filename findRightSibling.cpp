/*
perm_identity
Find right sibling of a binary tree with parent pointers
Given a binary tree with parent pointers, find the right sibling of a given node(pointer to the node will be given), if it doesn’t exist return null. Do it in O(1) space and O(n) time?
hint: to find out first right child of nearest ancestor which is neither the current node nor parent of current node
*/
#include<iostream.h>
#include<stdlib.h>
using namespace std;
//given
struct Node { 
    int data; 
    Node* left, *right, *parent; 
}; 
//given
Node* newNode(int item, Node* parent) { 
    Node* temp = new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    temp->parent = parent; 
    return temp; 
}

//tobecoded
Node* findRightSibling(Node* node, int level) { 
    if (node == NULL || node->parent == NULL)  
        return NULL;     
  
    while (node->parent->right == node ||  
          (node->parent->right == NULL &&  
           node->parent->left == node)) { 
        if (node->parent == NULL)  
            return NULL; 
          
  
        node = node->parent; 
        level--; 
    } 
    node = node->parent->right; 
    while (level < 0) { 
        if (node->left != NULL)  
            node = node->left; 
        else if (node->right != NULL)  
            node = node->right; 
        else 
            break; 
          
        level++; 
    } 
  
    if (level == 0)  
        return node;     
    return findRightSibling(node, level); 
}

// Driver Program to test above functions 
int main() 
{ 
    Node* root = newNode(1, NULL); 
    root->left = newNode(2, root); 
    root->right = newNode(3, root); 
    root->left->left = newNode(4, root->left); 
    root->left->right = newNode(6, root->left); 
    root->left->left->left = newNode(7, root->left->left); 
    root->left->left->left->left = newNode(10, root->left->left->left); 
    root->left->right->right = newNode(9, root->left->right); 
    root->right->right = newNode(5, root->right); 
    root->right->right->right = newNode(8, root->right->right); 
    root->right->right->right->right = newNode(12, root->right->right->right); 
  
    // passing 10 
    Node *res = findRightSibling(root->left->left->left->left, 0); 
    if (res == NULL) 
    	cout<<"\nNo right sibling\n";
    else
       	cout<<"\n"<<res->data<<"\n"; 
} 


