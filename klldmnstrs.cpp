#include <bits/stdc++.h>


using namespace std;

multiset <int> monsters;

int getMaxMonsters(int n, int hit, int t){
    // Complete this function
    //okay.
    int slayed = 0;
    for(int i=0;i<t;i++){
        int lowestmonster = *monsters.begin();
        //cout << lowestmonster << " ";
        lowestmonster -= hit;
        if(lowestmonster <= 0){
            slayed++;
            monsters.erase(monsters.begin());
        }
        else {
            monsters.erase(monsters.begin());
            monsters.insert(lowestmonster);
        }
    }
    return slayed;

}

int main() {
    int n;
    int hit;
    int t;
    cin >> n >> hit >> t;

    for(int h_i = 0; h_i < n; h_i++){
       int temp;
       cin >> temp;
       monsters.insert(temp);
    }
    int result = getMaxMonsters(n, hit, t);
    cout << result << endl;
    return 0;
}
