#include<iostream>
#include<vector>
using namespace std;


vector<int> removeDuplicates(vector<int> input){
	
  vector<int>::iterator it;
  for(it=input.begin();it!=input.end();++it){
    if(*it!=*(it+1)){
      cout<<*it<<"\t";
    }
  }
}
int main(){
  int n;
  cin>>n;
  vector<int>input(n);
  for(int i=0;i<n;i++){
    cin>>input[i];
  }
  removeDuplicates(input);
}

