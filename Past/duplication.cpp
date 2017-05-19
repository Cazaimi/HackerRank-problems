#include <bits/stdc++.h>

using namespace std;



string concat(string s1, string s2){
	int i = 0,j=0;
	for(i=0;s1[i] == '1' or s1[i] == '0';i++){

	}
	for(j=0;s2[j] == '1' or s2[j] == '0';j++){

	}
	//cout << "i is:" << i << " and j is:" << j << endl;
	s1 = s1.substr(0,i) + s2.substr(0,j);
	return s1;

}

string initialize(string input){
	for(int i=0;i<input.size();i++){
		string a = " ";

		input.replace(i,i+1," ");
	}
	return input;
}

string complementit(string input){
	//cout << "complementit begins..." << endl;
	for(int i=0;i<input.length();i++){
		//cout << "input[i] is:" << (int)input[i] << " ";
		if((int)input[i] == 49) {input[i] = '0';} //cout << "1\n";}
		else if(input[i] == '0') {input[i] = '1';} //cout << "0\n";}
		//cout << "now, input[i] is:" << input[i] << endl;

	}
	//cout << "complementit ends..." << endl;
	return input;
}

char duplication(int x){
    // Complete this function
    //okay.

	string complement(x,' '),temp(x,' ');

	complement = initialize(complement);
	temp = initialize(temp);

	int iterations = ceil( (log(x+1)) / (log(2)) );
	//cout << "Number of iterations is:" << iterations << endl;
	complement[0] = '0';
	for(int i= 0;i<iterations;i++){
		//cout << "OG string is:" << complement << " a";
		//cout << endl <<  endl ;
		temp = complementit(complement);
		//cout << "complement is:" << temp << " ";
		complement = concat(complement,temp);
		//cout << "concatenated string is:" << complement<< endl;
//		cout << "complement is:" << temp << endl;
	}

	char answer = complement[x];
	return answer;


}



int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int x;
        cin >> x;
        char result = duplication(x);
        cout << result << endl;
    }
    return 0;
}
