class Solution {
public:
    bool isScramble(string source1, string source2) {
        
        if (source1.length() != source2.length()) return false;

        this->table.clear();
        return isScrambleRecursive (source1, source2);
    }

private:
    bool isScrambleRecursive(string source1, string source2) {

        if (table.contains(source1) && table[source1].contains(source2)) return table[source1][source2];
        
        if (source1 == source2) return table[source1][source2] = true;
        if (source1.length() != source2.length()) return table[source1][source2] = false;

        string temp1 = source1, temp2 = source2;
        sort (temp1.begin(), temp1.end());
        sort (temp2.begin(), temp2.end());
        if (temp1 != temp2) return table[source1][source2] = false;

        int length = source1.size();
        for (int index = 1; index < length; index++) {
            if ((table[source1][source2] = isScrambleRecursive(substring (source1, 0, index - 1), substring (source2, 0, index - 1)))
             && (table[source1][source2] = isScrambleRecursive(substring (source1, index, length - 1), substring(source2, index, length - 1)))) return true;

            if ((table[source1][source2]= isScrambleRecursive(substring (source1, 0, index - 1), substring (source2, length - index, length - 1)))
             && (table[source1][source2]= isScrambleRecursive(substring (source1, index, length - 1), substring(source2, 0, length - index - 1)))) return true;
        }

        return table[source1][source2] = false;
    }

    string substring (string source, size_t start, size_t end) {

        return source.substr (start, end - start + 1);
    }

private:
    unordered_map<string, unordered_map<string, bool>> table;
};