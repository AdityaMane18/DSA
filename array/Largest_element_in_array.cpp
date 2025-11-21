//Brute Force Approach
//Time Complexity: O(n log n) - Sorting the array takes O(n log n) time complexity
//Space Complexity: O(1) or O(log n) - Depends on sorting algorithm (in-place sort like quicksort uses O(log n) for recursion stack, otherwise O(1) for iterative sort)
class Solution {
    public:
        int largestElement(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            return nums[nums.size() - 1];
        }
    };
//Optimal Solution
//Time Complexity: O(n) - We iterate through the array once, visiting each element exactly once
//Space Complexity: O(1) - We only use a constant amount of extra space (variables: largest, n, i)
class Solution {
    public:
        int largestElement(vector<int>& nums) {
            int largest = nums[0];
            int n = nums.size();
            for(int i=1; i<n; i++)
            {
                if(nums[i] > largest)
                {
                    largest = nums[i];
                }
            }
            return largest;
        }
    };