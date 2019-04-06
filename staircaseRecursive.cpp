/*A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count how many possible ways the child can run up to the stairs. 
You need to return number of possible ways W.*/

#include<iostream>
using namespace std;

int fun(int n){

if(n==1||n==0){
	return 1;
}
else if(n==2){
	return 2;
}
else{
return fun(n-3)+fun(n-2)+fun(n-1);
}
}

int main(){
	int n;
	cin>>n;
	cout<<fun(n);
}
