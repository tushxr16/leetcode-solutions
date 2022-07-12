// { Driver Code Starts
//Initial Template for javascript
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function main() {
    let t = parseInt(readLine());
    for(let i=0;i<t;i++)
    {
        let input_line = readLine().split(' ');
        let n = parseInt(input_line[0]);
        let m = parseInt(input_line[1]);
        
        input_line = readLine().split(' ');
        let matrix = new Array(n);
        for(let i=0;i<n;i++)
        {
            let a = new Array(m);
            for(let j=0;j<m;j++)
            {
                a[j] =parseInt(input_line[i*m+j]);
            }
            matrix[i] = a;
        }
        
        let obj = new Solution();
        let ans = obj.spirallyTraverse(matrix, n, m);
        let s = "";
        for(let i = 0 ; i < ans.length ;i++)
        {
            s+=ans[i];
            s+=" ";   
        }
        console.log(s);
    }
}
// } Driver Code Ends


//User function Template for javascript


/**
 * @param {number[][]} matrix
 * @param {number} r
 * @param {number} c
 * @returns {number[]}
*/
class Solution 
{
    //Function to return a list of integers denoting spiral traversal of matrix.
    spirallyTraverse(matrix, r, c)
    {
        let top = 0, bottom = r, left = 0, right = c;
        let dir = 0;
        let ans = [];
        while(top<bottom && left<right){
            if(dir===0){
                for(let i=left;i<right;i++)
                    ans.push(matrix[top][i]);
                top++;
            }else if(dir===1){
                for(let i=top;i<bottom;i++)
                    ans.push(matrix[i][right-1]);
                right--;
            }else if(dir===2){
                for(let i=right-1;i>=left;i--)
                    ans.push(matrix[bottom-1][i]);
                bottom--;
            }else{
                for(let i=bottom-1;i>=top;i--)
                    ans.push(matrix[i][left]);
                left++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
}