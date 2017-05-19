#include <iostream>
#include <vector>
#include <set>

#define MAXX 10000
#define mp make_pair

using namespace std;

vector <int> visited(MAXX);
vector <pair<int,int> > adj[MAXX];

void prims(int);

int main(){
    int n,m,a,b,w;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b >> w;
        adj[a].push_back(mp(b,w));
        adj[b].push_back(mp(a,w));
    }

    for(int i =1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++){
            cout << "(" << adj[i][j].first << "," << adj[i][j].second << ")";
        }
        cout << endl;
    }

    prims(1);
    return 1;

}

void prims(int source){
    for(int i=0;i<MAXX;i++){
        visited[i] = 0;
    }
    //first integer is weight, second is the node number.
	multiset <pair<int,int>> least;

    least.insert(mp(0,source));
    while(!least.empty()){
        pair <int,int> stuf = *least.begin();
        int weight = stuf.first;
        int node = stuf.second;
        least.erase(stuf);

        cout << "The first element of the multiset is:" << "(" << node << "," << weight << ")\n";

        if(!visited[node]){
            visited[node] = 1;
            // /cout << node;
        }

        for(int i=0;i<adj[node].size();i++){
            pair <int,int> a = adj[node][i];
            if(!visited[a.first]){
                least.insert(mp(a.second,a.first));
            }
        }
    }

}
