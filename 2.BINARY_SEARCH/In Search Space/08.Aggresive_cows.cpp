/*QUESTION:
An array arr[] of size n, where arr[i] represents the position of the i-th stall.
An integer k representing the number of aggressive cows.
Your task is to place all k cows in the stalls such that the minimum distance between any two cows is as large as possible.
Return the maximum possible minimum distance.

EXAMPLE:
Input
arr = [0, 3, 4, 7, 10, 9]
k = 4
Output: 3

explanation:It is not possible to keep every pair at a minimum distance of 4, so the answer is: 3

Approach:
Sort the array of stall positions because cows must be placed from left to right.
The smallest possible minimum distance is: low = 1;
The largest possible minimum distance is: high = arr[n-1] - arr[0];
which is the distance between the first and last stall.
Apply Binary Search on the answer.
For every middle distance mid, check whether it is possible to place all k cows while keeping at least mid distance between every pair.
If it is possible, store the answer and try a larger distance: low = mid + 1;
Otherwise, try a smaller distance: high = mid - 1;
Continue until the binary search ends.
Return high (or the stored answer), which represents the maximum possible minimum distance.

CODE:
*/
// Function to check if we can place all cows
// such that the minimum distance between any two cows is at least 'dist'
bool canWePlace(vector<int> &stalls, int dist, int cows){
  int cntCows = 1,last = stalls[0];
  for(int i = 1;i<stalls.size();i++){
     // If the current stall is at least 'dist' away
    // from the last placed cow, place another cow
    if(stalls[i] - last >= dist){
       cntCows++;
       last = stalls[i];
    }
     if(cntCows >= cows) return true;
  }
  return false;
}
int aggressiveCows(vector<int> &stalls, int k ){
  sort(stalls.begin(),stalls.end()); // Sort the stall positions because cows should be placed from left to righ
  int n = stalls.size();
  int low = 1, high = stalls[n-1] - stalls[0];
  while(low<= high){
       int mid = ( low + high)/2;
       if(canWePlace(stalls,mid,k)==true){
            low = mid + 1;
       }
       else{
            high = mid - 1;
       }
  }
  return high;
}
//Time Complexity = O(NlogN+Nlog(maxDistance))
//space complexity = O(1)
	​


  
