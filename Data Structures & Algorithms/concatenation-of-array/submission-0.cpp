class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ret_vec = vector<int>(nums);
        ret_vec.insert(ret_vec.end(), nums.begin(), nums.end());
        return ret_vec;
    }
};