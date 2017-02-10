#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

double average(int,int);

int main(){
    int n;
    cin >> n;
    bool flag = false;
    vector <double> input;
    vector <double> averages;
    //Initializing...
    //averages.push_back(0);
    //Geting array of numbers...
    for(int i=0;i<n;i++){
        int in = 0;
        cin >> in;
        input.push_back(in);
    }
    
    //sorting array...
    sort(input.begin(),input.end());
    
    int counter = 0; //Variable storing the number of average elements...
    //Calculating averages...
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
            
            //Calculating the average...
            double temp = average(input[i],input[j]);
            
           /* Linear search happening here... 
            //if(ceil(temp))
            //Linear search...
            for(int k=0;k<n;k++){
                //cout << input[k] << " " << temp << endl;
                if(temp == input[k]){
                   
                    flag = true;
                    break;
                }
                else if(temp != input[k]){
                  
                    flag = false;
                }
            }
            */
            
            bool flag = binary_search(input.begin(),input.end(),temp);
           //cout << "input[i]:" << input[i] << " input[j]:" << input[j] << " Average:" << temp << " Flag:" << flag << endl;    
            
            
            
            
            
            
            
            //If the average of the two numbers is found in the input,
            //put it into the averages array(actually vector)...
            if(flag){
                //cout << "First flag cleared\n " << flag;
                sort(averages.begin(),averages.end());
                bool flag2 = binary_search(averages.begin(),averages.end(),temp);
                
                
                
                if(!flag2){
                    //cout << "Second flag cleared\n";
                    averages.push_back(temp);   
                }
                
                
            }
        }
    }
    
    
    
    
    
    
    
    
    int i=0;
    /*while(i<averages.size()){
        cout << averages[i] << " " ;
        i++;
    }*/
    
    counter = averages.size() ;
    cout << counter << endl;
    return 0;
}

double average(int a, int b){
    double average = 0;
    average = (a + b);
    average /= 2;
    return average;
}
