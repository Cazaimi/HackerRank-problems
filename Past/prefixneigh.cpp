/* CONSOLE:

1. Benefit value function works properly.
2. Finding prefix neighbour pairs now.
Correction...

2. Writing the loop in main first for some clarity...
3. Have written the loop, now testing it...
*/

#include <bits/stdc++.h>

using namespace std;

int benefitvalue(string);
int found(string,string);

int main(){

    //Initializations... (sigh)
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> b(n);

    //Input the dictionary 'S' and initialize vector b...
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
       b.push_back(0);
    }

    //A O(n2) for loop to find prefix neighbours...
    for(int i=0;i<n;i++){
      int count = 0;
      for(int j=i+1;j<n;j++){
        int foundq = found(s[j],s[i]);
        int min = 0;
        // Take a note here : s[i] is being found in s[j]...
        //string was found...
        if(foundq == 1){
          /*Hey!, you did string being tested(in the outer loop), in the bigger
          string, but is it longer than the one you already found? */
          if(count == 0){
            min = s[j].length();
            count++;
          }
          else {
            int what = s[j].length();
            if(what < min){
              min = what;
              b[i] = j;
            }
          }

        }
        //string wasn't found...
        else if(foundq == 0){
          //...
      }
      }
    }

    for(int i=0;i<n;i++){
      cout << b[i] << " ";
    }
    return 0;
}

int found(string tbfound, string parent){
  int foundq = 0;
  foundq = parent.find(tbfound);
  if(foundq == -1){
    foundq = 0;
  }
  else(foundq != -1){
    foundq = 1;
  }
  return foundq;
}

int benefitvalue(string s){
  int value = 0;
  for(int i=0;i< s.size();i++){
    char c = s[i];
    value += c;
  }
  return value;
}
