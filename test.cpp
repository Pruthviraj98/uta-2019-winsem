#include<iostream>
#include <string.h>
using namespace std;
string hashTable[10]= {"", "", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};


void  printWordsUtil(int number[], int curr_digit, char output[], int n, string out[], int &count)
{
    int i;
    if (curr_digit == n)
    {
		out[count++]=output;
        return;
    }
    int x;
    for (i=0; i<hashTable[number[curr_digit]].length(); i++)
    {
        output[curr_digit] = hashTable[number[curr_digit]][i];
        printWordsUtil(number, curr_digit+1, output, n, out, count);
        if (number[curr_digit] == 0 || number[curr_digit] == 1)
            return;
    }
}
int printWords(int number[], int n, string out[])
{
	int count=0;
    char result[n+1];
    result[n] ='\0';
    printWordsUtil(number, 0, result, n, out, count);
    
//    cout<<"\n\n\n"<<count<<"\n\n\n";
    return(count);
}
int main(void)
{
	string out[1000];
    int number[] = {1, 3, 4};
    int n = sizeof(number)/sizeof(number[0]);
    int c=printWords(number, n, out);
    int cc= sizeof(out)/sizeof(out[0]);
    for (int i=0;i<c;i++){
    	if(out[i]==""){
    		exit(0);
		}
    	cout<<out[i]<<"\t";
	}
    return 0;
}
