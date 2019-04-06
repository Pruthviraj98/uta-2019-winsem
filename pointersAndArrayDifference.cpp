#include<iostream>
using namespace std;
int main(){
	int a[5];
	cout<<a<<endl;
	cout<<&a[0]<<endl;
	
	a[0]=5;
	a[1]=10;
	cout<<*a<<endl;
	cout<<*(a+1)<<endl;
	
	int* p=&a[0];
	
	cout<<a<<endl;
	cout<<p<<endl;
	
//value of p is associated with 3 values. i.e address of a, paddress of p and value of a
	cout<<&a<<endl;
	cout<<&p<<endl;
	

//size of a is more than that of p
	cout<<sizeof(a)<<endl;
	cout<<sizeof(p)<<endl;
	
//we can increment the value of p but not of a as a is an array instead we can do p=a+1
	p=p+1;
	a=a+1;
}
