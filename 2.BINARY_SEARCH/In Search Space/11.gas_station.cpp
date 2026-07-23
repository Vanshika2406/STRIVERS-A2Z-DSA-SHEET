/*
Questions:-
We have an horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = size of the stations array. Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of D. Find the answer exactly to 2 decimal places.

Example 1:

Input:
N = 10
stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
K = 9
Output: 0.50
Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
Example 2:

Input:
N = 10
stations = [3,6,12,19,33,44,67,72,89,95]
K = 2
Output: 14.00
Explanation: Construction of gas stations at 86 locations

Approach:
- To minimize the maximum distance between adjacent gas stations, we can perform binary search on the possible range of distances.
- Initialize `low` to 0 and `high` to the maximum distance between adjacent existing gas stations.
- While `high - low` is greater than a small threshold (e.g., 1e-6), calculate the mid-point `mid` between `low` and `high`.
- Check if it is possible to add `K` additional gas stations such that the maximum distance between adjacent gas stations is less than or equal to `mid`.
  - Iterate over the existing gas stations and check the distance between adjacent stations.
  - If the total number of additional stations required is less than or equal to `K`, it is possible to achieve the maximum distance `mid`.
- If it is possible, update `high` to `mid`, as we are looking for smaller distances.
- Otherwise, update `low` to `mid`.
- Finally, return the value of `low` plus a small value (e.g., 0.000001) to represent the answer to 2 decimal places.

Time Complexity: O(N log M), where N is the number of existing gas stations and M is the range of distances between adjacent gas stations.
Space Complexity: O(1), as we are using constant extra space.
*/

//CODE
int numberOfGasStationsRequired(long double dist,vector<int> &arr){
  int cnt = 0;
  for(int i = 1;i<arr.size();i++){
      int numberInBetween = ((arr[i] - arr[i-1]) / dist); //Number of stations required
      if((arr[i] - arr[i-1]) / dist == numberInBetween * dist){ //Exact division case
         numberInBetween--;
      }
      cnt += numberInBetween; //Adds stations needed for every gap.
  }
  return cnt;
}
long double minimiseMaxDistance(vector<int> &arr, int k){
  int n = arr.size();
  long double low = 0;
  long double high = 0;
  for(int i=0;i<n-1;i++){
     high = max(high,(long double)(arr[i+1] - arr[i]));
  }
  long double diff = 1e-6; //Because answer is decimal.
  while(high - low > diff){
      long double mid = (low + high)/(2.0);
      int cnt = numberOfGasStationRequired(mid,arr);
      if(cnt>k){
        low =mid;
      }
      else{
         high = mid;
      }
  }
  return high;
}
