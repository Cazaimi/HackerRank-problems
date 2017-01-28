#include <map>
#include <set>
#include <list>
#include <cmath>
#include <array>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int weight(string);
int main(){
    //input string...
    string s,sub,comp,sub_;
    cin >> s;
    //integers...
    int n,j=0,k=0,w=0,temp=0,l=0,t=0;
    vector <int> ar;
    //bools...
    bool flag = false;
    cin >> n;
    
        for(int i=0;i< s.size();i++){
            if(flag == false){
                j = 0;
                sub[j] = s[i];
                //cout  << "reached first if" << endl;
                temp = i;
            }
            if(s[i+1] == '\0' or s[i]!=s[i+1]){
                sub = s.substr(temp,j+1);
                //cout << "sub is: " << sub << endl;
                for(int k=1;k<=j+1;k++){
                    sub_ = sub.substr(0,k);
                    w = weight(sub_);
                    //cout << w << "|" <<  l+k-1 << endl;
                    ar.push_back(w);
                    t = k;
                }
                l = l+ t;
                //cout << l << endl;
                //ar[k] = w;
                //cout << w << endl;
                flag = false;
            }
            else{
                ++j;
               // cout << "reached this place at " << j << endl;
                flag = true;
            }
        }
    
    /*for(int i = 0 ;i< ar.size(); i++)
      cout << "ar[" << i << "] is:" << ar[i] << endl;*/
    
    sort (ar.begin(), ar.end());
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        // your code goes here
        
        bool trap = binary_search (ar.begin(), ar.end(), x);
                if(trap == true or x == ar[ar.size()-1])
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
        
            
            }
            
                
            
    
    
    
    return 0;
}

int weight(string sub){
    int leng = sub.length();
    int w = leng * (sub[0] - 'a'+1);
    return w;
}
