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
int isit(node * tree,int level, int n);
int Node(node * tree);

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
    int a = isit(tree,0,n);
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

int times = 1;
int isi = 1;
int isit(node * tree,int level, int n){
    if(tree!= NULL){
		level++;
		//Calculating the number of nodes...
		int nodes = Node(tree);

		if(level < (log(n+1) / log(2)) and nodes == 2){
			isit(tree -> left,level,n);
            if(isi == 1){
                isit(tree -> right,level,n);
            }
			times += 2;
		}
		else if(level == (log(n+1) / log(2)) and nodes == 0){
			isit(tree -> left,level,n);
			isit(tree -> right,level,n);
			times += 2;		
		}
		else {
			cout << "NO";
            isi = 0;
		}
        //cout << "number of times isit has been called:" << times << "\n";
        //cout << "With tree->key:" << tree -> key << " and level:" << level << endl;
		if(times == (n+1)*2 - 1){
				cout << "YES";
		}

	}
	else {
		//times--;
	}
    return isi;
}


int Node(node * tree){
	int number = 0;
	if(tree -> left != NULL){
		number++;
	}
	if(tree -> right != NULL){
		number++;
	}
	return number;
}
