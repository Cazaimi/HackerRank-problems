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
void search(node *);



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
    
    search(tree);
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

void search(node * tree){
    if(tree!=NULL){
        /*if(tree->key < ele){
            cout << tree->key << " ";
            search(tree -> right,ele);
        }*/
           cout << tree->key << " ";
            search(tree -> right);
        
            if(tree->right == NULL){
            //            
        }
    }
}
