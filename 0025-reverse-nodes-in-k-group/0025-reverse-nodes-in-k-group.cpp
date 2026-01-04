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
public:
    struct ListNode* reverseKGroup(struct ListNode* current, int k) {
        
        struct ListNode* head = new struct ListNode;
        head->next = current;

        struct ListNode* previous = head;
        while (checkNode (previous, k)) {

            previous = reverseNode (previous, k);
        }

        struct ListNode* answer = head->next;
        delete head;
        return answer;
    }

private:
    struct ListNode* reverseNode (struct ListNode* previous, int k) {

        struct ListNode* head = previous;
        struct ListNode* current = previous->next;
        for (int loop = 0; loop < k; loop++) {

            struct ListNode* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        struct ListNode* last = head->next;
        head->next = previous;
        last->next = current;
        return last;
    }

    bool checkNode (struct ListNode* previous, int k) {

        for (int loop = 0; loop < k; loop++, previous = previous->next) {

            if (previous->next == NULL) return false;
        }

        return true;
    }
};