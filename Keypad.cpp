#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

string getString(int n){
	if(n==2){
		return("abc");
	}else if(n==3){
		return("def");
	}else if(n==4){
		return("ghi");
	}else if(n==5){
		return("jkl");
	}else if(n==6){
		return("mno");
	}else if(n==7){
		return("pqrs");
	}else if(n==8){
		return("tuv");
	}else if(n==9){
		return("wxyz");
	}else{
		return("");
	}
}

int subs(int input, string output[]){
	
	if(input==0){
		output[0]="";
		return 1;
	}

	int lastDigit=input%10;
	int smallNumber=input/10;
	int smallInput=subs(smallNumber, output);
	string str=getString(lastDigit);
	for(int i=0;i<str.length()-1;i++){
		for(int j=0;j<smallInput;j++){
			output[j+(i+1)*smallInput]=output[j];
		}
	}
	
	int k=0;
	for(int i=0;i<str.length();i++){
		for(int j=0;j<smallInput;j++){
			output[k]=output[k]+str[i];
			k++;
			}
	}
	return smallInput*str.length();
}


int main(){
	int input;
	cin>>input;

	string* output=new string[1000];
	int count=subs(input, output);
	for(int i=0;i<count;i++){
			cout<<output[i]<<"\n";
	}
}
