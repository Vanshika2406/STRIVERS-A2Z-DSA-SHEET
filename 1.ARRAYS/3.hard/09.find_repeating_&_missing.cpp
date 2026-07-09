/*Problem Statement:
Given an integer array nums of size n containing numbers from 1 to n.
One number appears twice (Repeating Number).
One number is missing.
Return an array of size 2:

[Repeating Number, Missing Number]
Note: You are not allowed to modify the original array.

Example 1:
Input
nums = [3,1,2,5,3]
Output: [3,4]
Explanation:
3 appears twice.
4 is missing.

Approach:
Calculate expected sum.
Calculate expected square sum.
Calculate actual sum.
Calculate actual square sum.
Find X-Y and X+Y
Solve the two equations. Return [X,Y]

code:
*/
vector<int>missingrepeating(vector<int> a){
  long long n = a.size();
  long long SN = (n*(n+1))/2;
  long long S2N = (n*(n+1) * (2*n+1)) / 6;
  long long S=0, S2 = 0;
  for(int i=0,i<n;i++){
     S+= a[i];
     S2 += (long long)a[i] * (long long)a[i];
  }
  long long val1 = S-SN;
  long long val2 = S2-S2N;
  val2 = val2 / val1;
  long long x = (val1 + val2) / 2;
  long long y = x - val1;
  return {(int)x, (int)y};

//tc = O(n)
//sc = O(1)
