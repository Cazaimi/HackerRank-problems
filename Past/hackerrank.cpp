#include <bits/stdc++.h>

using namespace std;

int found(string,int,int);

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;

        int start = 0,what = 0, yes = 0;
        //The processing...
        while(what < 10){
          int foundprime = found(s,start,what);
          //cout << "fp:" << foundprime << " what:" << what << " start:" << start << endl ;
          what++;
          if(foundprime == -1){

            yes = 0;
            break;
          }
            if(what == 10 and foundprime != -1){
              yes = 1;
              break;
            }
          start = foundprime;
        }
        if(yes == 1){
            cout << "YES" << endl;
        }
        if(yes != 1){
            cout << "NO" << endl;
        }

    }

    //for ends...
    return 0;
}

int found(string s,int start,int what){
  int p = -1;
  string subs;
  start++;
  if(what == 0){
    p = s.find('h');
    //cout << 0;
  }
  else if(what == 1){
    subs = s.substr(start);
    p = subs.find('a');
      //cout << 1;
  }
  else if(what == 2){
    subs = s.substr(start);
    p = subs.find('c');
      //cout << 2;
  }
  else if(what == 3){
    subs = s.substr(start);
    p = subs.find('k');
  }
  else if(what == 4){
    subs = s.substr(start);
    p = subs.find('e');
  }
  else if(what == 5){
    subs = s.substr(start);
    p = subs.find('r');
  }
  else if(what == 6){
    subs = s.substr(start);
    p = subs.find('r');
  }
  else if(what == 7){
    subs = s.substr(start);
    p = subs.find('a');
  }
  else if(what == 8){
    subs = s.substr(start);
    p = subs.find('n');
  }
  else if(what == 9){
    subs = s.substr(start);
    p = subs.find('k');
  }
    //cout << "p is:" << p << " And substring is:" << subs << endl ;
    if(p!= -1){
        p += start;
    }
  return p;
}

//Hence, we write such a function, that returns the value of the character we're
//interested in...
