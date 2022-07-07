// { Driver Code Starts
//Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((string) => {
      return string.trim();
    });

  main();
});

function readLine() {
  return inputString[currentLine++];
}

/* Function to print an array */
function printArray(arr, size) {
  let i;
  let s = "";
  for (i = 0; i < size; i++) {
    s += arr[i] + " ";
  }
  console.log(s);
}

function main() {
  let t = parseInt(readLine());
  let i = 0;
  for (; i < t; i++) {
    let n = parseInt(readLine());
    let arr = new Array(n);
    let input_ar1 = readLine().split(" ").map((x) => parseInt(x));
    for (let i = 0; i < n; i++) arr[i] = input_ar1[i];
    let obj = new Solution();
    let res = obj.nextPermutation(arr,n);
    printArray(res,res.length);
  }
}// } Driver Code Ends


//User function Template for javascript

/**
 * @param {Number[]} arr
 * @param {Number} n
 * @returns {Number[]}
 */

class Solution {
    nextPermutation(arr,n){
        if(n<=1)
            return arr;
        let lastInc = -1, i = 1;
        while(i<n){
            if(arr[i]>arr[i-1])
                lastInc = i;
            i++;
        }
        if(lastInc==-1){
            for(let j=0;j<n/2;j++){
                [arr[j],arr[n-j-1]] = [arr[n-j-1],arr[j]];
            }
            return arr;
        }
        let index = lastInc;
        for(let i=lastInc;i<n;i++){
            if(arr[i]<arr[index] && arr[i]>arr[lastInc-1])
                index = i;
        }
        [arr[index],arr[lastInc-1]] = [arr[lastInc-1],arr[index]];
        for(let i=lastInc;i<n-1;i++){
            for(let j=i+1;j<n;j++)
                if(arr[i]>arr[j])
                    [arr[i],arr[j]]=[arr[j],arr[i]];
        }
        return arr;
    }
}