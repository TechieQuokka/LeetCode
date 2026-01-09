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
    ListNode* reverseBetween(ListNode* first, int left, int right) {
        
        struct ListNode* head = new struct ListNode;
        head->next = first;

        queue<struct ListNode*> buffer;
        int count = right - left + 1;

        struct ListNode* previous = head;
        while (--left) previous = previous->next;

        while (count--) {

            struct ListNode* current = previous->next;
            buffer.push (current);

            previous->next = current->next;
            current->next = NULL;
        }

        while (!buffer.empty()) {

            struct ListNode* current = buffer.front(); buffer.pop();
            current->next = previous->next;
            previous->next = current;
        }

        struct ListNode* answer = head->next;
        delete head;

        return answer;
    }
};