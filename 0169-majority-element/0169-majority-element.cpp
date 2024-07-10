class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        map<int, int> buffer;
        for (const auto& element : nums) {

            if (buffer.find(element) == buffer.end()) buffer[element] = 1;
            else buffer[element]++;
        }

        int maximum = 0, maxKey = 0;
        for (const auto& element : buffer) {

            int key = element.first, value = element.second;
            if (maximum < value) {

                maximum = value;
                maxKey = key;
            }  
        }

        return maxKey;
    }
};