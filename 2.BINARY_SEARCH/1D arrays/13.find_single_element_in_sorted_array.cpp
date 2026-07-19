/*
QUESTION:
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

APPROACH:
Since the array is sorted and every element appears exactly twice except for one element, we can use binary search to find the single element.
1. Initialize left = 0 and right = nums.size()-1, where nums is the input array.
2. While left < right, calculate  mid = left + (right - left) / 2.
While left < right:
Find the middle index.
If mid is odd, make it even by doing mid--.
Compare nums[mid] and nums[mid + 1].
If they are equal, the unique element lies in the right half.
Otherwise, it lies in the left half (including mid).
Return nums[left]
CODE:
*/
int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Make mid even
        if (mid % 2 == 1)
            mid--;

        if (nums[mid] == nums[mid + 1]) {
            left = mid + 2;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

//Time: O(log n)
//Space: O(1)
