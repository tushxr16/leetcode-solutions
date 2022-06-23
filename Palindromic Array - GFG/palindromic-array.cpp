// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


 // } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int PalinArray(int a[], int n)
    {
        for(int i=0;i<n;i++){
    	    int reverse = 0, temp = a[i];
    	    while(temp){
    	        reverse = reverse*10 + temp%10;
    	        temp/=10;
    	    }
    	    if(reverse!=a[i])
    	        return false;
        }
        return true;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}  // } Driver Code Ends