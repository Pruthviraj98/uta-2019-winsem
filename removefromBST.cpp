/*
Remove BST keys outside the given range
Given a Binary Search Tree (BST) and a range [min, max], 
remove all keys which are outside the given range. The modified tree should also be BST. 
For example, consider the following BST and range [-10, 13]. 
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int key;
	struct node *right;
	struct node *left;
};

//to remove from range
node* removeFromRange(node* root, int min, int max){
	if(root==NULL){//base case
		return NULL;
	}
	
	//extracting the left and right subtrees
	root->left=removeFromRange(root->left, min, max);
	root->right=removeFromRange(root->right, min, max);

	// case 1.1 if the key is less than min
	if(root->key<min){
		node *rchild=root->right;
		delete root;
		return rchild;
	}	
	//case 1.2 if the key is greater than max
	if(root->key>max){
		node *lchild=root->left;
		delete root;
		return lchild;
	}
	// case 2. if the key is in range
	return root;
}


//to create the new node for empty root slot
node* createNode(int n){
	node* temp= new node;
	temp->key=n;
	temp->left=NULL;
	temp->right=NULL;
//	cout<<"aaa\n";
	return temp;
		
}
//to populate
node* ins(node* root, int n){
//cout<<"aaa\n";
	if(root==NULL){//if empty
		return createNode(n);
	}
	if(root->key<n)
		root->right=ins(root->right, n);
	else
		root->left=ins(root->left, n);
	return root;
}
//print the tree
void inorderTrav(node* root){
	if(root){
		inorderTrav(root->left);
		cout<<"\t"<<root->key;
		inorderTrav(root->right);
	}
}

int main(){
	int n;
	cin>>n;
	int temp;
	
	node* root=NULL;
	for(int i=0;i<n;i++){
		cin>>temp;
//		cout<<"aaa\n";
		root=ins(root, temp);
	}
	cout<<"\n\n ----inorder trav--- \n\n";
	
	inorderTrav(root);
	cout<<"\n\n ----ordered--- \n\n";

	int min, max;
	cin>>min>>max;
	root=removeFromRange(root, min, max);
	//final Print
	cout<<"\n\n ------- \n\n";
	inorderTrav(root);		
}
