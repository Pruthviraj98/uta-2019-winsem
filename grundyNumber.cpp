#include<bits/stdc++.h>
using namespace std;

int mex(unordered_set<int> set){
  int mex=0;
  while(set.find(mex)!=set.end()){
    mex++;
  }
  return mex;
}

int grundy(int n){
  if(n==0){
    return 0;
  }
  unordered_set<int>set;
  for(int i=0;i<n-1;i++){
    set.insert(grundy(i));
  } 
  return(mex(set));
}


int main() {
	int n;
  	cin>>n;
  	cout<<grundy(n);
	// Write your code here
}
