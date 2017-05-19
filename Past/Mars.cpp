#include <iostream>
#include <string>

using namespace std;

int main() {
	string input,sub;
	int i=0,j=0;
	cin >> input;
	for(i=0; input[i] != 0;i+=3){
		sub = input.substr(i,3);
		if(sub[0]!= 'S'){
			j++;	
		} 
		if(sub[1]!='O'){
			j++;
		} 
		if(sub[2]!='S') {
			j++;
		}	
	}
	cout << j << endl;
	return 0;
}
