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
    ListNode* partition(ListNode* first, int x) {
        
        struct ListNode* left = new struct ListNode;
        struct ListNode* right = new struct ListNode;

        struct ListNode* previous = new struct ListNode;
        previous->next = first;

        while (previous->next) {

            struct ListNode* current = previous->next;
            int value = current->val;

            previous->next = current->next;
            current->next = NULL;
            if (value < x) {

                current->next = left->next;
                left->next = current;
            }
            else {

                current->next = right->next;
                right->next = current;
            }
        }

        while (right->next) {

            struct ListNode* current = right->next;
            right->next = current->next;
            current->next = previous->next;
            previous->next = current;
        }

        while (left->next) {

            struct ListNode* current = left->next;
            left->next = current->next;
            current->next = previous->next;
            previous->next = current;
        }

        struct ListNode* answer = previous->next;
        delete previous, left, right;
        return answer;
    }
};