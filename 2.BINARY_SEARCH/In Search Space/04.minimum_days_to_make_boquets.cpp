/*Problem Statement:
An integer N representing the number of roses.
An array arr[] where arr[i] represents the day on which the i-th rose blooms.
An integer m representing the number of bouquets required.
An integer k representing the number of adjacent bloomed roses needed to make one bouquet.
A bouquet can only be made using exactly k adjacent roses that have already bloomed.
Return the minimum number of days required to make at least m bouquets.
If it is impossible to make m bouquets, return -1.

Example:
Input:
bloomDay = [1,10,3,10,2]
m = 3
k = 1

Output: 3

Explanation:
Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3

Approach:
- Use binary search to find the minimum number of days required to make m bouquets.
- The search space will be between the minimum and maximum bloom day.
- For each mid value, simulate the process of making bouquets.
- Count the number of bouquets that can be made using k adjacent flowers on or after the current day.
- If the count is equal to or greater than m, update the answer and search in the lower half of the search space.
- If the count is less than m, search in the upper half of the search space.
*/
bool possible(vector<int> &arr, int day, int m, int k){
  int cnt = 0;
  int noOfb=0;
  for(int i = 0;i<arr.size();i++){
      if(arr[i]<= day){
        cnt++;
      }
      else{
          noOfB += (cnt/k); //Count how many bouquets can be made from the previous consecutive flowers.
          cnt = 0; //Reset the counter.
      }
  } //Suppose the array ends with bloomed roses than No unbloomed flower appears to trigger the else block.
  noOfB += (cnt / k);
  return noOfB >= m;
}
int roseGarden(vector<int> arr, int r, int b){
  long long val = r *1LL * b * 1LL; //1LL To avoid integer overflow
  if(val > arr.size()) return -1;
  int mini = INT_MAX, maxi = INT_MIN; //We need the minimum and maximum bloom days.
  for(int i = 0;i<arr.size();i++){
      mini = min(mini,arr[i]);
      maxi = max(maxi,arr[i]);
  }
  int low = mini, high = maxi;
  while(low <= high){
       int mid = (low+high)/2;
       if(possible(arr, mid, r, b)){
          high = mid - 1;
       }
       else low = mid + 1;
  }
  return low; //low is the minimum day on which bouquets can be made.
}
// Time Complexity: The binary search approach takes O(log n), where n is the number of elements in the `bloomDay` array.
// Space Complexity: The space complexity is O(1) since we are using a constant amount of extra space.
