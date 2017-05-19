#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

int size(int x){
	int i = 1;
	while(x){
		x = x % 10;
		i++;
	}
	return i;
}

void print(char input[]){
    int i = 0;
    while(input[i] != '\0'){
        cout << input[i];
        i++;
    }

    cout << endl;
}

int main(){
    long int input = 101;
    int answer = complementit(input);
    cout << answer;
}
