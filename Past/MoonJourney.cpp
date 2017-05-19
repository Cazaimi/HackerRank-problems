#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}

struct node{
	int key;
	node * parent;
};

node * graph0 = new node;

node * insert(node* graph,int ele);

int main()
{ 
    int N, I;
    cin >> N >> I;
    vector<vector<int> > pairs(N);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;

        if(i=0){
		    //For 0...    
		    graph0 -> key = 0;
    		graph0 -> parent = NULL;
			graphs[0] = graph0;         	
        }
		search        
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }

    node * graphs[N];
    

	for(int i=0;i < pairs.size();i++){
		for(int j = 0;j< pairs[i].size();j++){
			
		}
	}

}

node * insert(node* graph,int ele){
	if(graph == NULL){
		graph = new node;
		graph -> key = ele;
		graph -> parent = NULL;
	}
	else {
		//graph
	}
	return graph;
}

