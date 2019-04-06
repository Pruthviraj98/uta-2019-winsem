#include<iostream>
using namespace std;

void point(int a[]){
	for(int i=0;i<5;i++){
		a[i]++;
		
	}
}

int main(){
	int a[5]={1,2,3,4,5};
	int *p=&a[0];
	point(p);
	cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4];
}
