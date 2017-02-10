#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> types(n);
    vector <int> noftypes(5);

    //Initializing the types vector...
    for(int i = 0;i<5;i++){
      noftypes.push_back(0);
    }


    //Counting # of each type...
    for(int types_i = 0; types_i < n; types_i++){
      int a;
       cin >> a;
       types[types_i] = a;
       if(a == 5){
         noftypes[4] += 1;
       }
       else if(a == 4){
         noftypes[3] += 1;
       }
       else if(a == 3){
         noftypes[2] += 1;
       }
       else if(a == 2){
        noftypes[1] += 1;
       }
       else if(a == 1){
         noftypes[0] += 1;
       }
    }

    //Finding the maximum # in types...
    int max = 0;
    for(int i =4;i > 0; i--){
      if(noftypes[i] >= noftypes[max]){
        max = i;
      }
    }

    /*for(int i=0;i<5;i++){
        cout << noftypes[i] << " ";
    }*/

    cout  << ++max << endl;


    return 0;
}
