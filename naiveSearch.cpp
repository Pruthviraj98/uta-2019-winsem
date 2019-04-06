#include<iostream>
#include<string.h>
using namespace std;

void printPos(char* txt, char* pat){
	int n=strlen(txt);
	int m=strlen(pat);
	n=n-1;//cuz /0 is included in the length so less one here
	m=m-1;//same 

	for (int i = 0; i <= n - m; i++) { 
        int j; 
  
        /* For current index i, check for pattern match */
        for (j = 0; j < m; j+s+) 
            if (txt[i + j] != pat[j]) 
                break; 
  
        if (j == m) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            cout << "Pattern found at index "
                 << i << endl; 
    }
	return;
}

int main(){
	int n, m;
	cin>>n>>m;
	char txt[n];
	char pat[m];
	for(int i=0;i<n;i++)	
		cin>>txt[i];
		
	for(int j=0;j<m;j++)
		cin>>pat[j];
	printPos(txt, pat);
}
//
//#include<bits/stdc++.h> 
//using namespace std; 
//  
//void search(char* pat, char* txt) 
//{ 
//    int M = strlen(pat); 
//    int N = strlen(txt); 
//  
//    /* A loop to slide pat[] one by one */
//    for (int i = 0; i <= n - m; i++) { 
//        int j; 
//  
//        /* For current index i, check for pattern match */
//        for (j = 0; j < m; j++) 
//            if (txt[i + j] != pat[j]) 
//                break; 
//  
//        if (j == m) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
//            cout << "Pattern found at index "
//                 << i << endl; 
//    } 
//} 
//  
//// Driver Code 
//int main() 
//{ 
//    char txt[] = "AABAACAADAABAAABAA"; 
//    char pat[] = "AABA"; 
//    search(pat, txt); 
//    return 0; 
//} 
