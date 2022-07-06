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
    let input1 = readLine().split(" ").map((x)=>parseInt(x));
    let N = input1[0];
    let X = input1[1];
    let Arr = new Array(N);
    let input2 = readLine().split(" ").map((x)=>parseInt(x));
    for(let j = 0;j<N;j++) Arr[j] = input2[j];
    let obj = new Solution();
    let res = obj.hasArrayTwoCandidates(Arr,N,X);
    if(res){
      console.log("Yes");
    } else {
      console.log("No");
    }
  }
}// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number[]} arr
 * @param {number} n
 * @param {number} x
 * @return {boolean}
 */

class Solution {
    hasArrayTwoCandidates(arr,n,x){
        let st = new Set();
        for(let i=0;i<n;i++){
            if(st.has(x-arr[i]))
                return true;
            st.add(arr[i]);
        }
        return false;
    }
}