#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
 int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
  
}

void Qsort(int arr[], int low, int high){
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        Qsort(arr, low, pi - 1);
        Qsort(arr, pi + 1, high);
    }
  
}


void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
Qsort(input, 0, size-1);
}

int main(){
	int n;
	cin>>n;
	int i;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	quickSort(a, n);
		for(i=0;i<n;i++){
		cout>>a[i];
	}
}

