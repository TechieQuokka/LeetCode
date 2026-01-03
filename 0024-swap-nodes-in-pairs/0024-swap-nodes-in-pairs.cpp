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
    ListNode* swapPairs(ListNode* head) {
        
        struct ListNode* headNode = new struct ListNode;
        headNode->next = head;

        struct ListNode* previous = headNode;
        while (previous->next != NULL) {

            if (previous->next->next == NULL) break;
            swapNode (previous, previous->next);
            previous = previous->next;
            if (previous->next == NULL) break;
            previous = previous->next;
        }

        struct ListNode* answer = headNode->next;
        delete headNode;

        return answer;
    }

private:
    void swapNode (struct ListNode* previous, struct ListNode* current) {

        previous->next = current->next;
        current->next = current->next->next;
        previous->next->next = current;
        return;
    }
};