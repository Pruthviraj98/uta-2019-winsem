// C++ program to find number of subset containing
// consecutive numbers
#include <bits/stdc++.h>
#include<vector>
using namespace std;
 
 
int selectmx(int arr[], int n){
	int max=arr[0];
	int maxind=0;
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			maxind=i;
		}
	}
	return maxind;
} 

int searchInd(int arr[], int n, int max){
	for(int i=0;i<n;i++){
		if(arr[i]==max){
			return(i);
		}
	}
}

void inss(int arr[], int n){
int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
   
   return;
}


// Returns count of subsets with consecutive numbers
vector<int> numofsubset(int *arr, int n)
{
    inss(arr, n);
	
 	
	vector<int>a;
 	int i;
	int last[n];
	int counter[n];

 	for(i=0;i<n;i++){
 		last[i]=0;
 		counter[i]=0;
 	}
 	
    int count=1;
    
    int arraycount=0;
    
    for ( i = 0; i < n - 1; i++) {
        if (arr[i] + 1 == arr[i + 1]){
            count++;
        }else{
        	last[arraycount]=i;
        	counter[arraycount++]=count;
        	count=1;
		}
		
		if(i==n-2 && (arr[i] + 1 == arr[i + 1])){
			last[arraycount]=n-1;
			counter[arraycount++]=count;
			count=1;
		}
    }
    
  /*  for(i=0;i<n;i++){
    	cout<<"\n\t"<<counter[i]<<"\t";
	}
	
	cout<<"\n\n";
	
	for(i=0;i<n;i++){
    	cout<<"\n\t"<<last[i]<<"\t";
	}
	*/
	
    int index=selectmx(counter, arraycount);
    int terms=counter[index];
    int lastIndex=last[index];
    vector<int>sol;
	while(terms>0){
		sol.push_back(arr[lastIndex]);
    //	cout<<arr[lastIndex]<<"\t";
    	terms--;
    	lastIndex--;
	}
	
	return sol;
}
 
// Driven Program
int main()
{
	int i, n, p;
	cin>>n;
	int arr[i];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
    for(i=0;i<n-1;i++){
    	if(arr[i]==arr[i+1]){
    		for(p=i;p<n;p++){
    			arr[p]=arr[p+1];
    			n--;
			}
		}
	}
    vector<int>a=numofsubset(arr, n);
    for(i=a.size()-1;i>=0;i--){
    	cout<<a[i]<<"\t";
	}
    return 0;
}
