// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool Sudoku(int grid[9][9]){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(grid[i][j]==0){
                    for(int v=1;v<10;v++){
                        if(isSafe(grid,i,j,v)){
                            grid[i][j] = v;
                            if(Sudoku(grid)){
                                return true;
                            }else{
                                grid[i][j] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isSafe(int grid[9][9], int r, int c, int v){
        for(int i=0;i<9;i++){
            if(grid[i][c]==v)
                return false;
            if(grid[r][i]==v)
                return false;
            if(grid[3*(r/3) + i/3][3*(c/3) + i%3]==v)
                return false;
        }
        return true;
    }
    bool SolveSudoku(int grid[9][9])  
    {
        return Sudoku(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[9][9]) 
    {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                cout<<grid[i][j]<<" ";
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends