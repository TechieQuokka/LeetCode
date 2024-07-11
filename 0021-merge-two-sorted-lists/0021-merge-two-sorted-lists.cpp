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
    struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
        
        struct ListNode* head = new struct ListNode;
        if (head == NULL) throw;

        struct ListNode* pivot = new struct ListNode;
        if (pivot == NULL) throw;

        head->next = list1;
        pivot->next = list2;

        auto previous = head;
        for (auto current = previous->next; current != NULL; previous = current, current = current->next) {
            while (pivot->next) {

                int value = current->val;
                int target = pivot->next->val;
    
                if (value <= target) break;

                auto targetNode = pivot->next;
                pivot->next = targetNode->next;

                targetNode->next = previous->next;
                previous->next = targetNode;
                previous = targetNode;
            }
        }

        previous->next = pivot->next;

        return head->next;
    }
};