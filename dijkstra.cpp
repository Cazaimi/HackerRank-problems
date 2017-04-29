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
	int n , m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		//u--;v--;

		adj[u].push_back(mp(v,w));
	}
	int src = -1,dest = -1;
	cin >> src >> dest;

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
