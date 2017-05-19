#include <iostream>
#include <vector>
#include <queue>

#define MAX 10000

using namespace std;

vector<int> visited(MAX);
vector<vector <int> > adj(MAX);

void BFS(int);
void print(vector <vector <int>>,int);

int main(){
    int n,m;
    //cout << "Input the # of vertices\n";
    cin >> n;
    //cout << "Input the # of edges\n";
    cin >> m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //cout << "reached here";
    //test print adj array.
    //print(adj,n); => array is getting printed correctly.

    //initializing the visited array to false.
    for(int i=1;i<=n;i++){
        visited[i] = 0;
    }

    BFS(1);
}

void BFS(int root){
    queue <int> q;
    q.push(root);
    while(!q.empty()) {     //while 'Q' is not empty.
        int s = q.front();
        q.pop();

        cout << s << " ";
        visited[s] = 1;

        for(int i = 0;i<adj[s].size();i++){
            if(!visited[adj[s][i]]){
                q.push(adj[s][i]);
            }
        }
    }
}

void print(vector <vector <int>> a,int n){
    for(int i=1;i<=n;i++){
        for(int j = 0;j<a[i].size();j++) cout << a[i][j] << " ";
        cout << endl;
    }
}
