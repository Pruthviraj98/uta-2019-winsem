//Given a string S, remove consecutive duplicates from it recursively.

#include<iostream>
#include<string>
using namespace std;

void a(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
	if(input[0]=='\0'){
      return;
    }
  	
  	if(input[0]==input[1]){
      int i=0;
      for(;input[i]!='\0';i++){
        input[i]=input[i+1];
      }
      a(input);
    }
  a(input+1);
}

int main(){
	char *s;
	cin>>s;
	a(s);
}
