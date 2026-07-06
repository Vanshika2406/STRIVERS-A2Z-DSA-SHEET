/*
QUESTION:
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]
  
  
APPROACH:
To find all elements that appear more than ⌊ n/3 ⌋ times, we can use the Boyer-Moore Majority Vote algorithm. This algorithm helps us find potential candidates that could appear more than ⌊ n/3 ⌋ times in a single pass. After finding the candidates, we count their occurrences and return the elements that meet the criteria.

1. Initialize two candidate variables, c1 and c2, and their corresponding vote counters, vote1 and vote2.
2. Iterate through the array:
   - If the current element matches c1, increment vote1.
   - Else if the current element matches c2, increment vote2.
   - Else if vote1 is 0, assign the current element to c1 and set vote1 to 1.
   - Else if vote2 is 0, assign the current element to c2 and set vote2 to 1.
   - Else, decrement both vote1 and vote2.
3. After finding the potential candidates, count the occurrences of each candidate using cnt1 and cnt2.
4. If cnt1 is greater than ⌊ n/3 ⌋, add c1 to the result vector.
5. If cnt2 is greater than ⌊ n/3 ⌋ and c2 is different from c1, add c2 to the result vector.
6. Return the result vector containing the elements that appear more than ⌊ n/3 ⌋ times.

CODE:
*/
vector<int> majorityElement(vector<int> v){
  int cnt1=0,cnt2=0;
  int el1 = INT_MIN;  //INT_MIN is just a placeholder. It will be replaced as soon as we find actual candidates.
  int el2 = INT_MIN;
  for(int i =0;i<v.size();i++){
      if(cnt1 ==0 && el2!=v[i]){  //Candidate 1 currently has no support, so make the current number Candidate 1 whereas next  ensures both candidates are different
          cnt1 =1;
          el1 = v[i];
      }
      else if(cnt2 ==0 && el1 !=v[i]){
           cnt2 = 1;
           el2 = v[i];
      }
      else if(v[i]== el1) cnt1++;
      else if(v[i] == el2) cnt2++;
      else{
           cnt1--, cnt2--;
      }
  } //now We do NOT know whether they're actually majority elements.We only know they're the strongest candidates.
  vector<int>ls;
  cnt1 =0,cnt2=0;  //The old counts were just "votes." Now we want the actual frequencies.
  for(int i =0;i<v.size();i++){
      if(v[i]== el1) cnt1++;
      if(v[i] == el2) cnt2++;
  }
  int mini = (int)(v.size()/3) +1;
   if(cnt1>=mini) ls.push_back(el1);
   if(cnt2>=mini) ls.push_back(el2);
   sort(ls.begin(),ls.end());
   return ls;
}

//tc=O(2n)
//sc = O(1)
