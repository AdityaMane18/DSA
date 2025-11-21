//Brute Force Approach
//Time Complexity: O(n log n) - Sorting the array takes O(n log n) time complexity
//Space Complexity: O(1) or O(log n) - Depends on sorting algorithm (in-place sort like quicksort uses O(log n) for recursion stack, otherwise O(1) for iterative sort)
class Solution {
    public:
        int secondLargestElement(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            return nums[nums.size() - 2];
        }
    };

//Better Solution
//Time Complexity: O(n) + O(n) = O(n) - Two separate passes through the array: first pass finds the largest element, second pass finds the second largest
//Space Complexity: O(1) - We only use a constant amount of extra space (variables: largest, slargest, n, i)
class Solution {
    public:
        int secondLargestElement(vector<int>& nums) {
            //your code goes here
            int largest = INT_MIN;
            int slargest = INT_MIN;
            int n = nums.size();
            for(int i = 0; i< n; i++)
            {
                if (nums[i] > largest)
                {
                    largest = nums[i];
                }
            }
            for(int i=0; i<n; i++)
            {
                if(nums[i] > slargest && nums[i] != largest )
                {
                    slargest = nums[i];
                }
            }
            if(slargest == INT_MIN) return -1;
            return slargest;
          
        }
    };


//Optimal Solution
//Time Complexity: O(n) - Single pass through the array, visiting each element exactly once
//Space Complexity: O(1) - We only use a constant amount of extra space (variables: largest, slargest, n, i)
class Solution {
    public:
        int secondLargestElement(vector<int>& nums) {
            int largest = nums[0];
            int slargest = -1;
            int n = nums.size();
            for(int i=1; i<n; i++)
            {
                if(nums[i] > largest)
                {
                    slargest = largest;
                    largest = nums[i];
                }
                else if(nums[i] > slargest && nums[i] != largest)
                {
                    slargest = nums[i];
                }
            }
            return slargest;
        }
    };