#include <iostream>
#include <vector>
#include <set>

#define MAXX 10000
#define mp make_pair

using namespace std;

vector <int> parent(MAXX);
vector <int> visited(MAXX);
vector <pair<int,int> > adj[MAXX];
multiset <pair<int,pair<int,int>>> m;


int uf(int,int);
void kruskals(int);
void update(int,int);
void print(int);

int main(){
    int n,md,a,b,w;
    cin >> n >> md;
    for(int i=0;i<md;i++){
        cin >> a >> b >> w;
        adj[a].push_back(mp(b,w));
        adj[b].push_back(mp(a,w));
        m.insert( mp( w,mp(a,b) ) );
    }


    kruskals(n);

    return 1;

}

void kruskals(int v){
    int i = 0;
    for(int i =1;i<=v;i++){
        parent[i] = -1;
    }
    while(!m.empty()){
    //    if(i == v-1) break;

        pair<int,pair<int,int>> stuf = *m.begin();
        int weight = stuf.first;
        int source = stuf.second.first;
        int dest = stuf.second.second;

        int tru = uf(source,dest);
        print(v);
        cout << "tru is:" << tru << endl;
        if(!tru){
            cout << "Source:" << source << " Dest:" << dest <<  " Weight:" << weight << endl;
            update(source,dest);
        }


        m.erase(stuf);
        i++;
    }
}

int uf(int src, int dest){

    //two operations:
    // one for src, one for dest.
    int a = src;
    while(parent[a] != -1){
        a = parent[a];
    }
    int b = dest;
    while(parent[b] != -1){
        b = parent[b];
    }

    //cout << a << b << endl;
    int subset = 0;
    if(a == b){
        subset = 1;
    }

    return subset;
}

void update(int src, int dest){
    int a = src;
    while(parent[a] != -1){
        a = parent[a];
    }
    int b = dest;
    while(parent[b] != -1){
        b = parent[b];
    }
    parent[b] = a;
    //cout << "src:" << endl ;
}

void print(int n){
    for(int i =1;i<=n;i++){
        cout << parent[i] << " ";
    }
    cout << endl;
}
