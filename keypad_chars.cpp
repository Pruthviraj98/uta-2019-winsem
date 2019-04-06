#include<iostream>
#include<string.h>
using namespace std;

const char keypad[10][5]={"", "", "abc", "def", "ghi", "jkl", "mno","pqrs","tuv","wxyz"};
int num=0;



int printWordsUtil(int input[], int curr_digit, string member, int n, string output[], int x){
	int i;
	
	if(curr_digit==n){
		output[x++]=member;
		return(x);
	}

	for(int i=0;i<strlen(keypad[input[curr_digit]]);i++){
		
	//	cout<<"hi in here!!";
		
		member[curr_digit]=keypad[input[curr_digit]][i];
		cout<<keypad[input[curr_digit]][i]<<"\n";
		x=printWordsUtil(input, curr_digit+1, member, n, output, x);
		if(input[curr_digit]==0||input[curr_digit]==1){
			return x;
		}
	}
}


//done
int numCount(int input, int a[]){
	int dummy=input;
	int counter=0;
	while (dummy>0){
		int temp=dummy%10;
		dummy=dummy/10;
		a[counter]=temp;
		counter++;
	}
	return(counter);
}


//done
int subs(int input, string output[]){
	string memberString;
	int count;
	int a[100];
	count=numCount(input, a);
	int numArray[count];
	for(int i=0;i<count;i++){
		numArray[i]=a[i];
	}
	//int x;
	//cin>>x;
	int res=printWordsUtil(numArray, 0, memberString, count, output, 0);
	
	cout<<"ans=="<<res;
	return(res);
}

int main(){
	int number;
	cin>>number;
	string* output=new string[1000];
	int count=subs(number, output);
	for(int i=0;i<count;i++){	
		cout<<output[i]<<"\n";
	}
}

