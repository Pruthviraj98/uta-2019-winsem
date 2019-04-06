/*
DevG likes too much fun to do with numbers. Once his friend Arya came and gave him a challenge, 
he gave DevG an array of digits which is forming a number currently (will be called as given number). 
DevG was challanged to find the just next greater number which can be formed using digits of given number. 
Now DevG needs your help to find that just next greater number and win the challenge.
*/
#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define llt long long int
using namespace std;

int main(){
	llt t;
	cin>>t;
	
	while(t--){
	llt n;
	cin>>n;
	vector<llt> s;
	llt temp;
	llt flag=1;
	
	for(llt i=0;i<n;i++){
		cin>>temp;
		s.push_back(temp);
	}
	
	llt pivot;
	llt pivotPollt;
	//vector <llt> :: iterator itr;
	for(llt i=n-1;i>=0;i--){
		if(i==0){
			cout<<"invalid";
			flag=0;
			break;
		}
		
		
//		cout<<(*itr)<<"ele";
		if(s[i]>s[i-1]){
			pivot=s[i-1];
			pivotPollt=i-1;
//			cout<<"PIVOT="<<pivot<<"povit pollt="<<pivotPollt<<"\n";
			break;
		}
	}
	
	if(flag!=0){
		llt smallestDifference=1000000;
		llt swapPosition;
		for(llt i=pivotPollt+1;i<n;i++){
			if((s[i]-pivot) >0 && (s[i]-pivot)<smallestDifference){
				smallestDifference=(s[i]-pivot);
				swapPosition=i;
			}
		}

//					cout<<"swap item="<<s[swapPosition]<<"\n";		
		llt temp;
		temp=s[pivotPollt];
		s[pivotPollt]=s[swapPosition];
		s[swapPosition]=temp;
		


//		sort(s[pivotPollt+1], s[n-1]);
	llt key, j; 
	for (llt i = pivotPollt+2; i < n; i++){ 
       key = s[i]; 
       j = i-1; 
  	
       while (j >= pivotPollt+1 && s[j] > key) 
       { 
           s[j+1] = s[j]; 
           j = j-1; 
       } 
       s[j+1] = key; 
   } 
		
		for(llt i=0;i<n;i++){
			cout<<s[i]<<" ";
		}cout<<"\n";
	}else{
		flag=1;
	}
}
}

