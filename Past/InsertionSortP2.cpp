#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void print(vector <int>& r,int startpos, int endll){
  int i = 0;
  for(i=startpos;i<(r).size();i++){
    cout << (r)[i] << " ";
  }
    if(endll)
  cout << endl;
}


void insertionSort(vector <int>*  ar) {
    //initializations...
    int i = 0;
    int j = (*ar).back(); //last element
    int n = (*ar).size();
    if((*ar).size() > 1){

        if((*ar)[n-1] >= (*ar)[n-2]){

          //printing already sorted array...
          print((*ar),1,0);
      }

    else{
      for(i = n-2;i>0;i--){
        (*ar)[i+1] = (*ar)[i];
        if((j>(*ar)[i-1] and j<=(*ar)[i])){
          (*ar)[i] = j;
            print((*ar),1,0);
            break;
        }
      }}

    }

    else if((*ar).size() == 1){
        //cout << (*ar)[0] << " ";
    }

}


int main(void) {
    vector <int>  _ar;
    int _ar_size;
    //cout << "Input the array size:" << endl;
    cin >> _ar_size;
    _ar_size++;
    int n = _ar_size;
    _ar.push_back(0);
    for(int _ar_i=0; _ar_i<_ar_size-1; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;

        _ar.push_back(_ar_tmp);
        //if(_ar_i)
          // insertionSort(&_ar);

    }
    vector <int> subs;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        subs.push_back(_ar[_ar_i]);

        if(_ar_i >1){
            insertionSort(&subs);
            print(_ar,_ar_i+1,1);
        }


    }



        return 0;
}
