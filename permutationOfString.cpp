#include <bits/stdc++.h>
#include <string>
using namespace std;

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char a[], int l, int r)
{
   int i;
   if (l == r)
     cout<<a<<endl;
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i));
       }
   }
}

void printPermutations(string input){
    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  int n=input.length();
  
  char inputa[n+1];
  strcpy(inputa, input.c_str()); 
  permute(inputa, 0, n-1);
}
int main(){
	string a;
	cin>>a;
	printPermutations(a);
}
