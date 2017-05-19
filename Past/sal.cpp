#include <iostream>
#include <vector>
#include <set>

#define MAXX 10000
#define mp make_pair

using namespace std;

void dij(int,int);

vector  <pair<int,int> > adj[MAXX];
vector <int> sptset(MAXX);
vector <int> costs(MAXX);
multiset<pair<int,int > > multi;

int main(){
    // First, we initialize the board without ladders.
    for(int i = 1;i<=94;i++){
        for(int j=1;j<=6;j++){
            adj[i].push_back(mp(i+j,1));
        }
    }
    for(i = 95;i<=100;i++){
        for(int j=1;j<=100-i;j++){
            adj[i].push_back(mp(i+j,1));
        }
    }
    //this is done.
    //Now, we store the ladders and the snakes in the graph.
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(mp(b,0))
    }

    int s;
    cin >> s;
    for(int i=0;i<s;i++){
        cin >> a >> b;
        adj[a].push_back(mp(b,0))
    }


	int src = -1,dest = -1;

	for(int i =1;i<=n;i++){

		for(int j=0;j<adj[i].size();j++){
			pair <int,int> b = adj[i][j];
			cout << "(" <<  b.first << "," << b.second << ") ";

		}
			cout << endl;
	}
	dij(src,dest);
	return 1;
}

void dij(int root,int dest){

	for(int i=0;i<MAXX;i++){
		sptset[i] = 0;
		costs[i] = 999999;
		if(i == 1) costs[i] = 0;
	}

	int cost0 = 0;
	multi.insert(mp(cost0,root));

	while(!multi.empty()){  //while 'm' is not empty.

		pair <int,int>stuf = *multi.begin();
		int cost = stuf.first;
		int node = stuf.second;
		cout << "cost is:" << cost << " and node is:" << node << endl;
		multi.erase(stuf);

		if(node == dest) break;
		if(!sptset[node]){
			sptset[node] = 1;
		}

		for(int i=0;i<adj[node].size();i++){
			pair <int,int>a = adj[node][i];
			if(!sptset[ a.first ]){
				if(costs[a.first] > cost + a.second ){
					multi.insert(mp(cost + a.second,a.first));
					costs[a.first] = cost + a.second;
				}
			}
		}

	}


}
