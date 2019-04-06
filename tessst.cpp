#include<iostream>
#include<string.h>
using namespace std;

int main(){

int noPrimes[100000];



memset(noPrimes, 0, 100000);

for(int i=0;i<100000;i++){
	cout<<noPrimes[i];
}
/*int subArr[100001];
subArr[0]=0;

for(int i=1;i<11;i++){
	seive(subArr, i);
	for(int k=1;k<100001;k++){
		if(subArr[k]==i){
			noPrimes[i][k]=noPrimes[i][k-1]+1;
		}else{
			noPrimes[i][k]=noPrimes[i][k-1];
		}
	}
}

for(int i=0;i<11;i++){
	for(int j=0;j<100001;j++){
		cout<<noPrimes[i][j]<<"\t";
	}
	cout<<endl;
}

  int t;
  cin>>t;
  while (t>0){    
    int a, b, n;
    cin>>a>>b>>n;
	int counter=noPrimes[n][b]-noPrimes[n][a-1];
    cout<<counter<<endl;
    t--;
  }
	// Write your code here
	return 0;*/
}
