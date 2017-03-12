#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	
	int key;
	node * left;
	node * right;
};

node * tree = NULL;

node *insert(node * tree,int ele);
void preorder(node *);
void postorder(node *);
void inorder(node *);




int main() {
	
	int n = 0;

	cin >> n;
    int r = 0;
	for(int i = 0;i < n;i++){		
		int in = 0;
		cin >>  in;
        //cout << " first i";
		tree = insert(tree,in);
      //  cout << i << " ";
	}
    inorder(tree);
    cout << endl;
    preorder(tree);
    cout << endl;
    postorder(tree);
    return 0;
}

node * insert(node * tree, int ele){
	if(tree == NULL){
        tree = new node;
		tree->key = ele;
		tree->left = NULL;
		tree->right = NULL;
		return tree;
	}
	else{
        if(ele <= tree->key){
            tree->left = insert(tree->left, ele);
        }
        else if(ele > tree->key){
        	tree->right = insert(tree->right,ele);
        }
		return tree;
	}
}

void preorder(node * tree){
	if(tree != NULL){
        cout << tree->key  << " ";
	    preorder(tree->left);
  	    preorder(tree->right);  
    }
   
}

void inorder(node * tree){
  if(tree != NULL){

    inorder(tree->left);
	cout << tree->key  << " ";
	inorder(tree->right);
  }
}


void postorder(node * tree){
	if(tree != NULL){

    postorder(tree->left);
	postorder(tree->right);
	cout << tree->key << " ";
    }
        
}
