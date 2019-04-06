/*
Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ? 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

void seive(int lowPrimes[]){
  for(int i=0;i<2000001;i++){
    if(lowPrimes[i]==i){
      for(int j=2*i;j<=2000001;j+=i){
        lowPrimes[j]=i;
      }
    }
  }
  return;
}

int lowPrimeRet(int arr[], int ele, int mainarr[], int n){
	
}

int main() {
	
  int *lowPrimes=new int[2000001];
  for(int i=0;i<2000001;i++){
    lowPrimes[i]=i;
  }
  seive(lowPrimes);
  int n;
  cin>>n;
  int k=0;
  
  bool *marked=new bool[n];
  int *finalAns=new int[n+1];
  
  for(int i=0;i<n;i++){
  	marked[i]=false;
  }
  
  for(int i=n;i>0;i--){
  	if(marked[i]==1){
  		continue;
	  }else{
		marked[i]=true;
		int lpd=lowPrimes[i];	  	
		int x=i;
		vector<int> solArr;
		solArr.push_back(i);
		while(x!=1){
		
			for(int j=i-lpd;j>=1;j=j-lpd){
				if(!marked[j]){
					marked[j]=true;
					solArr.push_back(j);
				}
			}
			while(x%lpd==0){	
			 x=x/lpd;
			}
			lpd=lowPrimes[x];					
		}
		sort(solArr.begin(), solArr.end(), greater<int>());
		for(int i=0;i<solArr.size();i++){
			finalAns[k]=solArr[i];
			k++;
		}
				
	  }
	  
	  finalAns[n-1]=1;
	  for(int i=0;i<n;i++){
	  	cout<<finalAns[i]<<"\t";
	  }
	  cout<<endl;
  }
  
}
