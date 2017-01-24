#include <cmath>
#include <cstdio>



#include <vector>



#include <iostream>



#include <algorithm>



using namespace std;

int main(){
    int length;
    cin >> length;
    string input;
    cin >> input;
    int rotate;
    cin >> rotate;
    rotate %= 26;
    for(int i=0;i<length;i++){
        int temp =0,temp2 = 0;
        if((input[i]>='a' && input[i] <='z') || (input[i] >= 'A' && input[i] <= 'Z')) {
            temp2 = input[i];
            //cout << temp2 << endl;
            temp2+=rotate;
            //cout << temp2 << endl;
            if((temp2 > 'Z' && temp2 <= 115) and (input[i] >= 'A' and input[i] <= 'Z')){
                    temp = temp2 -'Z';
                    input[i] = 'A' + temp - 1;
                    //cout << temp << endl;
                }
            else if(temp2 > 'z'){
                    temp = temp2 - 122;
                    //cout << temp << endl;
                    input[i] = 'a' + temp - 1;
                }
            
            else{
                input[i] = temp2;
            }
        }
    }

    cout << input << endl;
    return 0;
}

