#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i =0;
    string chars,input;
    //Taking string input...
    cout << "Input the string:";
    getline(cin,input);
    char swap = ' ';

    // converting to lower case...
    for(i=0;i<input.length();i++){
      if(input[i] >= 65 && input[i] <= 90)
        input[i]+= 32;
    }

    //Writing Bubble sort...
    for(i = 0; i< input.length()-1; i++){
      for(int j = 0; j < input.length()-1;j++){
        //cout << "input[" << j << "] is:" << input[j] << " & input[" << j+1 << "] is:" << input[j+1] << endl;
        if(input[j] > input[j+1]){
          swap = input[j];
          input[j] = input[j+1];
          input[j+1] = swap;
        }
      }
    }
    bool flag = true;
    //cout << input.length() << endl;
    //Finding if pangram or not...
    int count = 0;
    for(i=0; i<input.length();i++){
      if(input[i] != input[i+1]){
        if(input[i] == ' '){

        }
        else
          count++;
      }
    }

    cout << "The count is:" << count << endl;
    cout << "Sorted string is:" << input << flag << endl;
    if(count == 25)
      cout<< "pangram\n";
    else
      cout << "not pangram\n";

    return 0;
}
