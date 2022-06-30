// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int lo, int mid, int hi)
    {
        int merged[hi-lo+1] = {0};
        int idx1 = lo, idx2 = mid+1, k = 0;
        
        while(idx1<=mid && idx2<=hi){
            if(arr[idx1]<=arr[idx2]){
                merged[k++] = arr[idx1++];
            }else{
                merged[k++] = arr[idx2++];
            }
        }
        
        while(idx1<=mid){
            merged[k++] = arr[idx1++];
        }
        while(idx2<=hi){
            merged[k++] = arr[idx2++];
        }
        for(int i=0;i<(hi-lo+1);i++){
            arr[i+lo] = merged[i];
        }
        return;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r){
            int m = (l+r)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
        return;
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends