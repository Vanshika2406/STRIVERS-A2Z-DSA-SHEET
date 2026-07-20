/*Problem Statement
An array weights[], where weights[i] represents the weight of the i-th package.
An integer d, representing the number of days within which all packages must be shipped.
Rules:
Packages must be shipped in the same order as given in the array.
A package cannot be split into multiple shipments.
The total weight loaded on the ship in one day cannot exceed the ship's capacity.
Return the minimum ship capacity required to ship all the packages within d days.

Example:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Algorithm:
Find the maximum weight.
Find the total sum of weights.
Binary search between these values.
For every capacity:
Count how many days are required.
If days ≤ d, search left.
Otherwise, search right.
Return the minimum valid capacity.

code*/
int findDays(vector<int> &weights, int cap){
  int days = 1, load=0;
  for(int i =0;i<weights.size();i++){
      if(weights[i] + load > cap){ //Load it onto the current day's shipment.
         days+= 1; //urrent package doesn't fit.So Start a new day and Put this package on the new day.
         load = weights[i];
      }
      else{
           load += weights[i];
      }
  }
  return days;
}
int leastWeightCapacity(vector<int> &weights, int d){
  int low = *max_element(weight.begin(),weight.end()); //max_element() finds the largest package weight.The * is used to dereference the iterator and get the actual value.
  int high = accumulate(weight.begin(),weight.end(),0); //accumulate() calculates the sum of all elements.Syntax: accumulate(start, end, initial_value)
  while(low<=high){
      int mid = (low + high)/2;
      int numberOfDays = finddays(weights,mid);
      if(numberOfDays <= d){
         high = mid - 1;
      }
      else{
           low = mid + 1;
      }
  }
  return low;
}
/*
- Time Complexity: O(N log M), where N is the size of the weights array and M is the sum of all the weights.
- Space Complexity: O(1) as we are using a constant amount of extra space.
*/
