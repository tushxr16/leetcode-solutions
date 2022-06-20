// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      set<int> s;
      for(int i=0;i<N;i++)
        s.insert(arr[i]);
      int ans = 1, tmp = 1, prev = *s.begin();
      bool flag = true;
      for(auto x:s){
          if(flag){
              prev = x;
              flag = false;
          }else{
              if(x-prev==1){
                    tmp++;
              }else{
                    ans = max(ans,tmp);
                    tmp = 1;
              }
              prev = x;
          }
      }
      ans=max(ans,tmp);
      return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends