/*
For sure, the love mobiles will roll again on this summer's street parade. Each year, the organisers decide on a fixed order for the decorated trucks. Experience taught them to keep free a side street to be able to bring the trucks into order. 

The side street is so narrow that no two cars can pass each other. Thus, the love mobile that enters the side street last must necessarily leave the side street first. Because the trucks and the ravers move up closely, a truck cannot drive back and re-enter the side street or the approach street. 

You are given the order in which the love mobiles arrive. Write a program that decides if the love mobiles can be brought into the order that the organisers want them to be.

Input
There are several test cases. The first line of each test case contains a single number n, the number of love mobiles. The second line contains the numbers 1 to n in an arbitrary order. All the numbers are separated by single spaces. These numbers indicate the order in which the trucks arrive in the approach street. No more than 1000 love mobiles participate in the street parade. Input ends with number 0.

Output
For each test case your program has to output a line containing a single word "yes" if the love mobiles can be re-ordered with the help of the side street, and a single word "no" in the opposite case.
*/

#include<iostream>
#include<vector>
#include<stack>
#define llt long long int

using namespace std;

int main(){
	llt t;
	
	while(true){
		cin>>t;
		if(t==0){
			break;
		}else{
			int flag=1;
//			queue<llt> q;
			vector<llt>v;
			int temp;
			for(int i=0;i<t;i++){
				cin>>temp;
				v.push_back(temp);
			}
			
			stack<llt> temp1;
			stack<llt> temp2;
			
//			stack<llt> temp;
			
			for(int i=0;i<t;i++){
				if(i==t-1){
					temp2.push(v[i]);
					break;
				}
				if(v[i]>v[i+1]){
					temp1.push(v[i]);
				}else{
					temp2.push(v[i]);
				}	
			}
			
			while(temp1.size()!=0){
				temp2.push(temp1.top());
				temp1.pop();
			}
			
			while(temp2.size()>0){
				
//				cout<<temp2.top()<<"\t";
				llt tempp=temp2.top();
				temp2.pop();
				
				if(temp2.top()<tempp){
					continue;
				}else{
					flag=0;
					cout<<"no";
					flag=1;
					break;
				}
//				cout<<"hihi\n";
			}
			if(flag==1){
				cout<<"yes";
			}
		}
	}
	
	
}
