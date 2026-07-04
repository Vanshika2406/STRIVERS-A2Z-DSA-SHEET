/*QUESTION:
You are given an integer array prices, where prices[i] represents the price of a stock on the i-th day.
Your goal is to maximize the profit by:
  ->Buying one stock on a single day.
  ->Selling that stock on a future day.
Return the maximum profit you can earn from this transaction.
  ->If no profit can be made, return 0.

EXAMPLE:
Input prices = [7,1,5,3,6,4]
Output: 5
Explanation:
Buy on Day 2 at price 1
Sell on Day 5 at price 6

Profit = 6 - 1 = 5

APPROACH:
Initialize: minPrice = prices[0] & maxProfit = 0
Traverse the array from left to right.
For each price:
->Update the minimum price seen so far.
->Calculate the current profit:

currentProfit = currentPrice - minPrice

Update the maximum profit if the current profit is greater.
Return maxProfit.
*/

//CODE:
int maxprofit(vector<int> &prices){
  int mini=prices[0];
  int maxProfit=0;
  int n=prizes.size();
  for(int i=0;i<n;i++){
      int cost = prices[i]-mini;
      maxProfit=max(maxProfit,cost);
      mini=min(mini,prices[i]);
  }
  return maxProfit;
}

//timecomplexity = O(n)
//spacecomplexity = O(1)
