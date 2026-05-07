class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // first we need to sort the array
        std::sort(nums.begin(), nums.end());

        // initialize return array
        vector<vector<int>> ret_array;
        int n = nums.size();

        int first_idx, second_idx, third_idx;
        int target_val, sum;
        for (first_idx = 0; first_idx < n - 2; first_idx++)
        {
            // Skip to the last occurance of a repeated first value.
            if (first_idx > 0 && nums[first_idx] == nums[first_idx - 1]) 
            {
                continue;
            }

            // now we set the second and third indices to be the ends of the remaining array
            second_idx = first_idx + 1;
            third_idx = n - 1;

            // now we do the normal two pointers scan to find the pairs that sum to the target value
            target_val = -nums[first_idx];
            while (second_idx < third_idx)
            {
                sum = nums[second_idx] + nums[third_idx];
                if (sum < target_val)
                {
                    second_idx++;
                }
                else if (sum > target_val)
                {
                    third_idx--;
                }
                else    // else the target value is reached
                {
                    // push_back is required when passing an initializer list
                    ret_array.push_back({nums[first_idx], nums[second_idx], nums[third_idx]});
                    
                    // Skip duplicate values for second and third elements
                    while (second_idx < third_idx && nums[second_idx] == nums[second_idx + 1]) second_idx++;
                    while (second_idx < third_idx && nums[third_idx] == nums[third_idx - 1]) third_idx--;
                    
                    // because we are skipping duplicates, both second and third index must be iterated,
                    // For a match can only be made after a single one is iterated if the iterated value
                    // reaches a duplicate, but we have already skipped those above.
                    second_idx++;
                    third_idx--;
                }
            }
        }

        return ret_array;
    }
};
