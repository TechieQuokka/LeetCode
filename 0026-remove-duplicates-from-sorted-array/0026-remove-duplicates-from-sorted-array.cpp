class Solution {
public:
    int removeDuplicates(vector<int>& source) {
        
        set<int> buffer (source.begin(), source.end());
        source = vector<int>(source.size());

        int index = 0;
        for (const auto& element : buffer) {

            source[index++] = element;
        }
        return buffer.size();
    }
};