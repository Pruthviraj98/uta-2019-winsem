#include<iostream>
using namespace std;


long long merge(int A[],int left,int mid,int right){

	int i=left,j=mid,k=0;

	int temp[right-left+1];
	long long sum = 0;
	
	long long tempo=0;
	while(i<mid && j<=right){
		if(A[i] < A[j]){
			
	//		cout<<"\n--------"<<A[i]<<"---------------\n";
			
			sum=sum+(right-j+1)*A[i];
		//	tempo=(sum+right-j+1)*A[i];
			temp[k++] = A[i++];
			
		}else{
			temp[k++] = A[j++];
		}
	}
	while(i<mid){
		temp[k++] = A[i++];
	}
	while(j<=right){
		temp[k++] = A[j++];
	}

	for(int i=left,k=0;i<=right;i++,k++){
		A[i] = temp[k];
	}
	return sum-tempo;
}

long long merge_sort(int A[],int left,int right){

	long long count = 0;
	if(right > left){
		int mid = (left + right)/2;

		long long countLeft = merge_sort(A,left,mid);
		long long countRight = merge_sort(A,mid+1,right);
		long long myCount = merge(A,left,mid+1,right);

		return myCount + countLeft + countRight;
	}
	return count;

}
long long solve(int A[], int n)
{
	long long ans = merge_sort(A,0,n-1);
	return ans;
}

int main(){
int t;
  cin>>t;
  while(t>=0){
  	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	long long ans=solve(arr, n);
	cout<<ans<<"\n";

  
    t--;
  }
}
