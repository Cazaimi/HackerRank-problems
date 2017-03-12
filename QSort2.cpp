#include <bits/stdc++.h>
using namespace std;

void quickSort(vector <int> &arr) {

   vector <int> left;
   vector <int> equal;
   vector <int> right;


    if(arr.size() == 1){

    }
    else {

    for(int i = 0;i < arr.size();i++){
      if(i==0){
        equal.push_back(arr[i]);
      }
      else{
        if(arr[i] < equal[0]){
          left.push_back(arr[i]);
        }
        else if(arr[i] == equal[0]){
          equal.push_back(arr[i]);
        }
        else if(arr[i] > equal[0]){
          right.push_back(arr[i]);
        }
      }
    }


        //Now, we have left, right and equal...


        if(left.size()){
            quickSort(left);
        }
        if(right.size()){
            quickSort(right);
        }

          for(int i=0;i< arr.size();i++){
            if(i < left.size()){
                arr[i] = left[i];
            }
            else if( i == left.size()){
                arr[i] = equal[0];
            }
            else if(i > left.size()){
                arr[i] = right[i - left.size() - 1];
            }
        }

        //cout << "After manipulation, the array is:";
        for(int i=0;i<arr.size();i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        /* cout << "Left is: ";
        for(int i=0;i< left.size();i++){
        cout << left[i] << " ";
    }cout << ",Equal is: ";
    for(int i=0;i< equal.size();i++){
        cout << equal[i] << " ";
    }cout << ",Right is:";
    for(int i=0;i< right.size();i++){
        cout << right[i] << " ";
    }cout << endl << endl;
    }*/

    }}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
