# Left out candies
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given <strong>N</strong>&nbsp;students sitting in a circle, distribute <strong>M</strong> candies to these students. The&nbsp;<strong>i<sub>th</sub></strong>&nbsp;student can take only&nbsp;<strong>i</strong> candies. If <strong>i<sub>th</sub></strong> student does not get the required amount of&nbsp;candies&nbsp;he will not take it. Distribute the candies starting from the 1st student and moving along the circle of students till you reach&nbsp;a student you can not give candies to. You need to find the amount of&nbsp;candies left.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4, M = 11
<strong>Output:</strong> 0
<strong>Explanation:</strong> You&nbsp;first give 1 candy to 1st student, 
2 to 2nd , 3 to 3rd , 4 to 4th then again 1 to first.&nbsp;
All candies are finished with none left out.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4, M = 12
<strong>Output:</strong> 1
<strong>Explanation:</strong>&nbsp;You are left with only one candy.
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>leftCandies()</strong>&nbsp;which takes two integers <strong>n</strong>&nbsp;and&nbsp;<strong>m&nbsp;</strong>as input parameters and returns an integer&nbsp;denoting the amount of&nbsp;candies left.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(logN)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>9</sup><br>
1 ≤ M ≤ 10<sup>18</sup></span></p>
</div>