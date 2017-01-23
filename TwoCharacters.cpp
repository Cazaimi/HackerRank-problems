#include <iostream>
#include <string>
using namespace std;

string removal(char, char, string,int);
bool allowed(string);
int strlength(string, bool);

int main() {

	// initializations and input...
	string chars = "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ";
	string input = " ",copy,removed="                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ";
	int length = 0,i=0,j=0,jj = -1,counter=0;
	bool flag = false;
	//cout << "Input string length\n";
	cin >> length;
	getline(cin,input);
	//cout << "Input the string\n";
	getline(cin, input);

	//finding all different characters in the input string...
	i=0;
	while(i<length){
		j = 0;
		flag = false;
		while(j< length){
            //cout << "Chars[j] is: "  << chars[j] << endl;
            //cout << "input[i] is: " << input[ i] << endl;

            if(chars[j] != input[i]){
				// blah../
			}
			else if(input[i] == chars[j]){
				break;
			}
            if(input[i] == ' ')
                break;

			j++;
		}
        //cout << "j is:" << j << endl;
        if(j == length)
            flag = true;
		//cout << "j is " << j << endl;// << "& flag is "<< flag << endl;
		if(flag == true){
			chars[jj+1] = input[i];
			//cout << chars[jj+1] << " " << endl;
            //cout << "Chars array is:" << chars << endl;
			jj++;
		}
		i++;
	}
    chars[jj+1] = '\0';
    //cout << "jj is: " << jj << endl;
	// Resetting the boolean flag...
	flag = false;
    //cout << "The chars array is:" << chars << endl;
	int max = 0;
	for(i=0;chars[i]!='\0';i++){
		for(j=i+1;chars[j]!='\0';j++){
			int k = 0;
			/*1while(k < 100){
				removed[k] = '\0';
				k++;
			}*/
			//cout << "The characters that will be tested are:" << chars[i] <<" & " << chars[j] << endl;
			removed = removal(chars[i],chars[j],input,length);
			flag = allowed(removed);
			//cout << "Flag is:" << flag << endl;
			length = strlength(removed, flag);
			//cout << "Length is:" << length << endl;
			//cout << removed << endl;
			if(length >  max)
				max = length;
            removed="                                                                                                    ";
		}
	}

	cout << max;
	return 0;
}

string removal(char a, char b, string input, int length){

	int i = 0,j=0,k=0;
	while(input[i] != '\0'){

		if(input[i] == a || input[i] == b){
			//Do nothing...
			i++;
		}
		else{
			//Delete the invalid char and shift the string forward...
			j = i;
			while(input[j]!='\0'){
				input[j] = input[j+1];
				j++;
			}
		}
	}
		return input;
}

bool allowed(string input){

	int i =0;
	bool flag = true;
	for(int i = 1 ; input[i]!= '\0' ; i++ ){
		if(input[i-1] == input[i]){
			flag = false;
		}
	}
	return flag;
}

int strlength(string input, bool flag){

	int i=0 , length = 0;
	if(flag == true){
		while(input[i] != '\0')
			i++;
		length = i;
	}

	return length;
}
