// { Driver Code Starts
//Initial Template for C#

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DriverCode
{

    class GFG
    {
        static void Main(string[] args)
        {
            int testcases;// Taking testcase as input
            testcases = Convert.ToInt32(Console.ReadLine());
            while (testcases-- > 0)// Looping through all testcases
            {
                
                int n = Convert.ToInt32(Console.ReadLine());// Input for size of array
                int[] arr = new int[n];
                string elements = Console.ReadLine().Trim();
                elements = elements + " " + "0";
                int[] arr1 = Array.ConvertAll(elements.Split(), int.Parse);
                for (int i = 0; i < n; i++)
                {
                    arr[i] = arr1[i];
                }
                int x = Convert.ToInt32(Console.ReadLine());
                Solution obj = new Solution();
                int res = obj.search(arr,n,x);
                Console.WriteLine(res);
            }

        }
    }

    
 // } Driver Code Ends
//User function Template for C#

    class Solution
    {
        
        
        // Function to search x in arr
        // arr: input array
        // X: element to be searched for
        public int search(int[] arr, int n,int x) 
        { 
            for(int i=0;i<n;i++){
                if(arr[i]==x)
                    return i;
            }
            return -1;
        } 

    }

}

// { Driver Code Starts.  // } Driver Code Ends