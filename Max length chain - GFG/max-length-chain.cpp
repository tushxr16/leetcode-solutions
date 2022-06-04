// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].first>p[j].first){
                swap(p[i],p[j]);
            }
        }
    }
    int lis[n], res = 0;
    for(int i=0;i<n;i++){
        lis[i] = 1;
        for(int j=0;j<i;j++){
            if(p[i].first>p[j].second){
                lis[i] = max(lis[i],lis[j]+1);
            }
        }
        res = max(res,lis[i]);
    }
    return res;
}