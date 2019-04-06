#include<iostream>
#include<string.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
    int counter=0;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    for (int p=2; p<=n; p++){
       if (prime[p])
          counter++;
    }
  cout<<counter;
  
}
int main()
{
    int n;
  	cin>>n;
    SieveOfEratosthenes(n);
    return 0;
}
