#include <cctype>       // for std::tolower

class Solution {
public:
    bool isPalindrome(string s) {
        // first we clean the string (remove spaces and set everything to undercase)
        string clean_string;
        for (int i = 0; i < s.size(); i++)
        {
            unsigned char c = s[i];
            if (std::isalnum(c)) 
            {
                clean_string += std::tolower(c);
            }
        }
        
        // Now, we set one pointer to the beginning, and one to the end
        int left = 0;
        int right = clean_string.size() - 1;

        while (left < right)
        {
            if (clean_string[left] == clean_string[right])
            {
                left++;
                right--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
