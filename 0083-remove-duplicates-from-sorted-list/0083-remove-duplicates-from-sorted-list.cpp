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
    ListNode* deleteDuplicates(ListNode* first) {
        
        struct ListNode* head = new struct ListNode;
        head->next = first;

        int previousValue = INT_MIN;
        struct ListNode* previous = head;
        while (previous->next) {

            struct ListNode* current = previous->next;
            if (current->val != previousValue) {

                previousValue = current->val;
                previous = current;
                continue;
            }

            previous->next = current->next;
            delete current;
        }

        struct ListNode* answer = head->next;
        delete head;

        return answer;
    }
};