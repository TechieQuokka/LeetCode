class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> table;

        for (string& element : strs) {

            string data = element;
            sort(data.begin(), data.end());
            if (table.contains(data) == false) table[data] = vector<string>();

            table[data].push_back (element);
        }

        vector<vector<string>> answer;
        for (auto& element : table) {

            answer.push_back (element.second);
        }

        return answer;
    }
};