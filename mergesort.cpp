#include<iostream>
using namespace std;

void merge(int input[], int si, int mid, int ei){
  int i, j, k;
  int n1=mid-si+1;
  int n2=ei-mid;
  
  int L[n1]; 
  int R[n2];
  
  for(i=0;i<n1;i++)
    L[i]=input[si+i];
  for(j=0;j<n2;j++){
 	R[j]=input[mid+1+j];   
  }
  
  i=0;
  j=0;
  k=si;
  
  while(i<n1 && j<n2){
    if(L[i]<=R[j]){
      input[k]=L[i];
      i++;
    }else{
      input[k]=R[j];
      j++;
    }
    k++;
  }
  
  while(i<n1){
    input[k]=L[i];
    i++;
    k++;
  }
  
  while(j<n2){
    input[k]=R[j];
    j++;
    k++;
  }
}

void mergeSep(int input[], int si, int ei){
  if(ei<si){
    return;
  }else{
    int mid=(si+ei)/2;
   	mergeSep(input, si, mid);
    mergeSep(input, mid+1, ei);
    merge(input, si, mid, ei);
  }
}

void mergeSort(int input[], int size){
	// Write your code here
        mergeSep(input, 0, size-1);
        return;
}

int main(){
	int n;
	int i;
	 cin>>n;
	int a[i];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	mergeSort(a, n);
	for(i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
}
