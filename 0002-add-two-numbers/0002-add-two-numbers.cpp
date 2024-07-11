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
    int ConvertToInteger (struct ListNode* list) {

        if (list == NULL) return 0;

        int result = 0, pivot = 1;
        for (struct ListNode* current = list; current != NULL; current = current->next) {

            result += current->val * pivot;
            pivot *= 10;
        }

        return result;
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

    struct ListNode* ConvertToList (int number) {

        struct ListNode* list = new struct ListNode;
        if (list == NULL) throw;

        if (number == 0) {

            Insert (list, 0);
            return list;
        }

        int length = (int) log10 (number);
        int pivot = pow (10, length);
        for (int index = 0; index < length + 1; index++) {

            int element = number / pivot;
            number -= element * pivot;
            pivot /= 10;
            Insert (list, element);
        }

        return list;
    }

public:
    ListNode* addTwoNumbers(struct ListNode* list1, struct ListNode* list2) {
        
        int left = this->ConvertToInteger (list1), right = this->ConvertToInteger (list2);
        int sum = left + right;
        
        auto result = this->ConvertToList (sum);
        return result->next;
    }
};