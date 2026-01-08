class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> components = split(path, '/');

        vector<string> buffer;
        for (const auto& component : components) {

            if (component == "" || component == ".") continue;
            if (component == ".."){
                if (buffer.empty() == false) {

                    buffer.pop_back();
                }
            }
            else buffer.push_back (component);
        }

        if (buffer.empty()) return "/";

        string answer = "";
        for (const auto& directory : buffer) {

            answer += "/" + directory;
        }

        return answer;
    }

private:
    vector<string> split(string source, char separator) {
        vector<string> result;
        string token = "";
        
        for (char ch : source) {
            if (ch == separator) {
                result.push_back(token);
                token = "";
            }
            else {
                token += ch;
            }
        }
        result.push_back(token);
        
        return result;
    }
};