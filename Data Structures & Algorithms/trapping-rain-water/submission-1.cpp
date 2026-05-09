#include <algorithm>

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;

        int left_idx = 0;
        int right_idx = n - 1;
        int left_height = height[left_idx];
        int right_height = height[right_idx];

        int water_level = std::min(left_height, right_height);

        // take the total rectangular volume, and remove the two columns of volume at the ends
        int working_volume = water_level * ((right_idx - left_idx + 1) - 2);

        while (left_idx < right_idx - 1)
        {
            // if left column is shorter or equal
            if (left_height <= right_height)
            {                
                left_height = height[++left_idx];
                // remove the water taken up by the new, current column
                working_volume -= std::min(left_height, water_level);
                // if the new height is greater than the current water level
                if (left_height > water_level)
                { 
                    int new_water_level = std::min(left_height, right_height);
                    // add the new water created by the new height to the working total
                    working_volume += (new_water_level - water_level) * ((right_idx - left_idx + 1) - 2);
                    // update water level
                    water_level = new_water_level;
                }
            }
            else    // if right column is shorter
            {                
                right_height = height[--right_idx];
                // remove the water taken up by the new, current column
                working_volume -= std::min(right_height, water_level);
                // if the new height is greater than the current water level
                if (right_height > water_level)
                { 
                    int new_water_level = std::min(left_height, right_height);
                    // add the new water rectangle created by the new height to the working total
                    working_volume += (new_water_level - water_level) * ((right_idx - left_idx + 1) - 2);
                    // update water level
                    water_level = new_water_level;
                }
            }
        }
        return working_volume;
    }
};