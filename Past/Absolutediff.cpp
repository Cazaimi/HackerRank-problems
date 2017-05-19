#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }

    //Sort the array...
    sort(a.begin(),a.end());

    //Find difference of pairs...
    int diff = a[1] - a[0];
    for(int i=0;i<n-1;i++){
      int diffdash = a[i+1] - a[i];
      if(diffdash < diff){
        diff = diffdash;
      }
    }

    cout << diff;
    return 0;
}
