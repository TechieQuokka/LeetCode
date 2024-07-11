/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    char* ConvertToString (struct ListNode* list) {

        char* buffer = (char*) calloc (32, sizeof (int));
        if (buffer == NULL) throw;

        if (list == NULL) return buffer;

        int index = 0;
        for (struct ListNode* current = list; current != NULL; current = current->next) {

            buffer[index++] = current->val + '0';
        }
        buffer[index] = '\0';

        return buffer;
    }

    void Insert (struct ListNode* head, int value) {

        if (head == NULL) return;

        struct ListNode* newNode = new struct ListNode;
        if (newNode == NULL) throw;

        newNode->val = value;
        newNode->next = head->next;
        head->next = newNode;
        return;
    }

    struct ListNode* ConvertToList (char* number) {

        struct ListNode* list = new struct ListNode;
        if (list == NULL) throw;

        while (*number) {

            Insert (list, *number++ - '0');
        }

        return list;
    }

    bool IsDigit (char character) {
    
        return character >= '0' && character <= '9';
    }

    unsigned char ToNumber (char character) {
        
        if (!IsDigit (character)) return (unsigned char)255;
        return (unsigned char) (character - '0');
    }

    char ToCharacter (unsigned char number) {
    
        if (number > 9) return (char) (-128);
        return (char)number + '0';
    }

    void Swap (const void* argument1, const void* argument2, size_t type) {
        
        unsigned char* element1 = (unsigned char*) argument1, * element2 = (unsigned char*) argument2;
        
        size_t byte = 0LL;
        for (byte = 0LL; byte < type; byte++) {
            
            unsigned char temporary = element1[byte];
            element1[byte] = element2[byte];
            element2[byte] = temporary;
        }
        return;
    }

    void Reverse (char* source, int length) {
        
        if (source == NULL) return;
        
        int left = 0, right = 0;
        for (left = 0, right = length - 1; left < right; left++, right--) {
            
            Swap ((char*)source + left, (char*)source + right, sizeof (char));
        }
        return;
    }

    void Sum (char lvalue[], char rvalue[], char result[]) {
        
        if (lvalue == NULL || rvalue == NULL) return;
        
        unsigned char buffer = 0U;
        const unsigned char ten = (unsigned char) 10;
        
        int lpivot = strlen (lvalue) - 1, rpivot = strlen (rvalue) - 1;
        int repeat = 0, index = 0;
        for (repeat = lpivot < rpivot ? lpivot + 1 : rpivot + 1; repeat; repeat--, lpivot--, rpivot--, index++) {
            
            unsigned char leftNumber = ToNumber(lvalue[lpivot]), rightNumber = ToNumber(rvalue[rpivot]);
            unsigned char calculate = leftNumber + rightNumber + buffer;
            result[index] = ToCharacter (calculate % ten);
            buffer = calculate / ten;
        }
        
        int pivot = 0; char* biggest = NULL;
        if (strlen (lvalue) < strlen (rvalue)) biggest = rvalue, pivot = rpivot;
        else biggest = lvalue, pivot = lpivot;
        
        while (pivot >= 0) {
            
            unsigned char number = ToNumber (biggest[pivot--]);
            unsigned char calculate = number + buffer;
            result[index++] = ToCharacter (calculate % ten);
            buffer = calculate / ten;
        }
        if (buffer) result[index++] = '1';
        result[index] = '\0';
        
        Reverse (result, index);
        return;
    }

    void Palindrome (char* source, int length) {

        if (source == NULL) return;

        for (int left = 0, right = length - 1; left < right; left++, right--) {

            Swap (source + left, source + right, sizeof (char));
        }
        return;
    }

public:
    ListNode* addTwoNumbers(struct ListNode* list1, struct ListNode* list2) {
        
        char* left = this->ConvertToString (list1), * right = this->ConvertToString (list2);
        char sum[128] = { 0, };

        Palindrome (left, strlen (left));
        Palindrome (right, strlen (right));
        Sum (left, right, sum);
        
        auto result = this->ConvertToList (sum);
        return result->next;
    }
};