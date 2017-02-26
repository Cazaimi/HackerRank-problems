/*CONSOLE:

1. three cases... */

#include <bits/stdc++.h>

int classify(int);
int figure(int,int);

using namespace std;

int main(){
    int y;
    cin >> y;
    int decision = classify(y);
    int date = figure(decision,y);
    cout << date << ".09." << y;
    return 0;
}


int classify(int year){
  if(year <= 1917 and year >= 1700){
    return 0;
  }
  else if(year == 1918){
    return 1;
  }
  else if(year >= 1919 and year <= 2017){
    return 2;
  }
}

int figure(int c,int year){
  if(c == 0){
    if(year % 4 == 0){
      return 12;
    }
    else return 13;
  }
  else if(c == 2){
    if((year % 4 == 0 and year % 100 !=0) or (year % 400 == 0)){
      return 12;
    }
    else return 13;
  }
  else return 26;
}
