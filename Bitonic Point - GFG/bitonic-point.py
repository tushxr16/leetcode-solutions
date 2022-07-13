#User function Template for python3
class Solution:

	def findMaximum(self,arr, n):
		for i in range(1,n-1):
		    if(arr[i]>arr[i-1] and arr[i]>arr[i+1]):
		        return arr[i]
		return arr[n-1]

#{ 
#  Driver Code Starts
#Initial Template for Python 3





if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findMaximum(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends