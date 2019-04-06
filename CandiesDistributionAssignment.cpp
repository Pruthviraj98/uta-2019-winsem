#include<bits/stdc++.h>
using namespace std;

long long check(long long mid, long long arr[], int n, int k){
  int sum=0;
  for(int i=0;i<n;i++){
  	sum=sum+arr[i]/mid;
  }
  if(sum>=k){
  	return sum;
  }else{
  	return -1;
  }
}

int main() {
	// Write your code here
  int t;
  cin>>t;
  while(t>0){
	
    int n, k;
    cin>>n>>k;
    long long arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    
    sort(arr, arr+n);
    
    long long start=0;
    long long end=arr[n-1];
	
//	cout<<"\n initial max is: "<<end<<"\n";
    
    long long ans=0;
    
    while(start<=end){
      long long mid=start+(end-start)/2;
      long long ret=check(mid, arr, n, k);
      if(ret==-1){
        end=mid-1;
      }else{
  //    	cout<<mid<<"\n";
		ans=mid;
        start=mid+1;
      }
    }
    
    cout<<ans;
    
    t--;
  }
  
}
