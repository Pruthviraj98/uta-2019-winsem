/*
Suppose you have a string made up of only 'a' and 'b'. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false
*/

#include<iostream>
#include<string.h>
using namespace std;

bool funct(char input[], int current, int n, bool aAfterB=false, bool status=true){
	
	if(current==n-1){
		if(aAfterB==false){
			return(true);
		}else{
			return(false);
		}
	}
	
	if(aAfterB==true){
		return(false);
	}
	
	
	
	switch(input[current+1])
	{
		case 'b':
			if(input[current+2]=='b'){
				status=true;
			}else{
				aAfterB=true;
				status=false;
			}break;
		case 'a':
			status=true;
			break;
		default:
			aAfterB=true;
			status=false;
			break;
	}
		
	status=funct(input, current+1, n, aAfterB, status);	
	return(status);
}

bool checkAB(char input[]){
	if(input[0]=='a'){
      if(strlen(input)==1){
        return(true);
      }
		return funct(input, 0, strlen(input)-1);	
	}else{
      return(false);
    }      	
    
}

int main(){
	string inp;
	cin>>inp;
	char input[inp.length()];
	for(int i=0;i<inp.length();i++){
		input[i]=inp[i];
	}
	input[inp.length()]='\0';
	//cout<<input;
	bool result=checkAB(input);
	cout<<"\n"<<result;
}
