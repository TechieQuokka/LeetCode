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
    stack<struct ListNode*> ToEnd (struct ListNode* head) {

        stack<struct ListNode*> buffer;
        for (auto& current = head; current != NULL; current = current->next) {

            buffer.push (current);
        }

        return buffer;
    }

public:
    struct ListNode* removeNthFromEnd(struct ListNode* list, int number) {
        
        if (list == NULL) return NULL;

        struct ListNode* head = new struct ListNode;
        if (head == NULL) throw;

        head->next = list;

        stack<struct ListNode*> buffer = ToEnd (head);
        for (int index = 0; index < number; index++) {

            buffer.pop();
        }

        auto previous = buffer.top();
        auto deleteNode = previous->next;
        previous->next = deleteNode->next;

        return head->next;
    }
};