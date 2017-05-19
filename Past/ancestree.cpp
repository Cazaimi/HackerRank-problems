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
int counter = 0;
int level = 1;

node *insert(node * tree,int ele);
int Node(node * tree);
int search(node *tree, int ele);
int ancestry(node * tree, int n1, int n2);

int main() {
	
	int n = 0;
	cin >> n;
     int r = 0;
	for(int i = 0;i < n;i++){		
		int in = 0;
		cin >>  in;
		tree = insert(tree,in);
	}
	int n1 = 0,n2 = 0;
	cin >> n1 >> n2;	
	int swap = 0;
	if(n2 < n1){
		swap = n1;
		n1 = n2;
		n2 = swap;
	}
/*     int f1 = search(tree,n1);
     int f2 = search(tree,n2);
     cout << "n1 was found? Ans:" << f1;
     cout << endl << "n2 was found? Ans:" << f2; */
     int ancestor = ancestry(tree,n1,n2);
    cout << ancestor; 
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


int search(node * tree, int ele){
	int found = 0;
	if(tree != NULL){
		if(tree -> key == ele ){
			found = 1;
		}	
		else if(tree -> key < ele){
			found = search(tree -> right,ele);
		}
		else if(tree -> key > ele){
			found = search(tree -> left, ele);
		}
	}
	return found;
}

int ancestry(node * tree, int n1, int n2){
	int ancestor = 0,f1 = 0,f2 = 0;
	if(tree != NULL){
		
		f1 = search(tree,n1);
		f2 = search(tree,n2);
		if(f1 and f2){
			if(n1 < tree->key and n2 < tree-> key){
				ancestor = ancestry(tree -> left,n1,n2);
			}
			else if(n1 < tree->key and n2 > tree-> key){
				ancestor = tree -> key;
			}
			else if(n1 > tree->key and n2 > tree-> key){
				ancestor = ancestry(tree -> right,n1,n2);
			}
			else if(n2 == tree -> key or n1 == tree->key){
				ancestor = tree -> key;
			}	
		}
		else{
			
		}
	}
	return ancestor;
}
