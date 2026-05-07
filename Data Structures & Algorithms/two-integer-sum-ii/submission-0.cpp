class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // well we're already sorted so we don't have to worry about that.
        
        int n = numbers.size();
        int left_idx = 0;
        int right_idx = n - 1;

        int sum;
        while (left_idx < right_idx)
        {
            sum = numbers[left_idx] + numbers[right_idx];
            if (sum < target)
            {
                left_idx++;
            }
            else if (sum > target)
            {
                right_idx--;
            }
            else
            {
                return {left_idx + 1, right_idx + 1};
            }
        }

        return {-1, -1};
    }
};
