class Solution {
public:
    bool isNumber(string source) {

        if (source.empty()) return false;
        
        source = toLower(source);
        
        if (!hasInvalidLetters(source)) return false;
        
        if (!validateECount(source)) return false;
        
        if (!hasAtMostOneDot(source)) return false;
        
        if (!isValidAfterE(source)) return false;
        
        if (!hasValidSigns(source)) return false;
        
        int ePos = -1;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] == 'e') {
                ePos = i;
                break;
            }
        }
        
        if (ePos != -1) {

            string beforeE = source.substr(0, ePos);
            string afterE = source.substr(ePos + 1);
            
            if (beforeE.empty() || afterE.empty()) return false;
            
            return isValidDecimal(beforeE) && isValidInteger(afterE);
        } 
        else {

            return isValidDecimal(source);
        }
    }

private:
    bool isValidDecimal(string s) {

        if (!s.empty() && (s[0] == '+' || s[0] == '-')) {
            s = s.substr(1);
        }
        
        if (s.empty()) return false;
        
        int dotPos = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') {
                dotPos = i;
                break;
            }
        }
        
        if (dotPos != -1) {
            string beforeDot = s.substr(0, dotPos);
            string afterDot = s.substr(dotPos + 1);
            
            bool hasBeforeDigit = !beforeDot.empty() && isAllDigits(beforeDot);
            bool hasAfterDigit = !afterDot.empty() && isAllDigits(afterDot);
            
            if (beforeDot.empty() && afterDot.empty()) return false;
            
            if (!beforeDot.empty() && !hasBeforeDigit) return false;
            if (!afterDot.empty() && !hasAfterDigit) return false;
            
            return hasBeforeDigit || hasAfterDigit;
        }
        else {
            return !s.empty() && isAllDigits(s);
        }
    }
    
    bool isValidInteger(string s) {

        if (!s.empty() && (s[0] == '+' || s[0] == '-')) {
            s = s.substr(1);
        }
        
        return !s.empty() && isAllDigits(s);
    }
    
    bool isAllDigits(string s) {
        if (s.empty()) return false;
        for (const auto& c : s) {
            if (!isDigit(c)) return false;
        }
        return true;
    }

    bool isValidAfterE (string source) {
        bool flag = false;
        for (const auto& element : source) {
            if (element == 'e') flag = true;
            else if (flag && element == '.') return false;
        }
        return true;
    }

    bool hasAtMostOneDot (string source) {

        int count = 0;
        for (const auto& element : source) {
            count += element == '.';
        }
        return count < 2;
    }

    bool hasValidSigns (string source) {

        char character = source[0];
        if (!isDigit(character) && character != '+' && character != '-' && character != '.') {
            return false;
        }

        for (int index = 1; index < source.length(); index++) {
            char element = source[index];
            if (source[index - 1] == 'e' && (element == '+' || element == '-')) continue;
            else if (element == '+' || element == '-') return false;
        }
        return true;
    }

    bool validateECount (string source) {

        int count = 0;
        for (const auto& element : source) {
            count += element == 'e';
        }
        return count < 2;
    }

    bool hasInvalidLetters (string source) {

        for (const auto& element : source) {
            if (element != 'e' && isLower(element)) return false;
        }
        return true;
    }

    string toLower (string source) {

        string result = "";
        for (const auto& element : source) {
            if (!isUpper(element)) result += element;
            else result += element + 32;
        }
        return result;
    }

    bool isUpper (char character) {

        return character >= 'A' && character <= 'Z';
    }

    bool isLower (char character) {

        return character >= 'a' && character <= 'z';
    }

    bool isAlphabet (char character) {

        return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z');
    }

    bool isDigit (char character) {

        return character >= '0' && character <= '9';
    }
};