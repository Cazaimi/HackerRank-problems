#include <iostream>
#include <vector>
#include <set>

#define MAXX 10000
#define mp make_pair

using namespace std;

vector <int> parent(MAXX);

int uf(int,int);

int main(){
    parent[1] = -1;
    parent[2] = -1;
    parent[3] = -1;
    parent[4] = 1;
    parent[5] = -1;
    parent[6] = -1;
    parent[7] = 2;
    int tru = uf(4,7);
    cout << tru;
    return 1;

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

    cout << a << b << endl;
    int subset = 0;
    if(a == b){
        subset = 1;
    }

    return subset;
}

void update(int src, int dest){
    parent[dest] = src;
}
