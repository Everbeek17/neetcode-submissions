#include <algorithm> // for std::max()

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int left_idx = 0;
        int right_idx = n - 1;
        int left_height = heights[left_idx];
        int right_height = heights[right_idx];

        int curr_vol = std::min(left_height, right_height) * (right_idx - left_idx);
        int potential_vol;
        
        while (left_idx < right_idx)
        {            
            if (left_height > right_height)
            {
                right_idx--;
                right_height = heights[right_idx];
                potential_vol = std::min(left_height, right_height) * (right_idx - left_idx);
                if (potential_vol > curr_vol)
                {
                    curr_vol = potential_vol;
                }
            }
            else
            {
                left_idx++;
                left_height = heights[left_idx];
                potential_vol = std::min(left_height, right_height) * (right_idx - left_idx);
                if (potential_vol > curr_vol)
                {
                    curr_vol = potential_vol;
                }
            }
        }
        
        return curr_vol;
    }
};