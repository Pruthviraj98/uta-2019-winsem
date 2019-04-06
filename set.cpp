#include<iostream>
#include<set>
#include<iterator>

using namespace std;
int main(){
	set<int, greater<int> > ss;
	int n;
	cin>>n;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		ss.insert(temp);
	}
	set<int> ss1(ss.begin(), ss.end());
	
	set<int, greater<int> >::iterator itr;
	
	for(itr=ss1.begin(); itr!=ss1.end();++itr){
		cout<<"\t"<<*itr;
	}
}
