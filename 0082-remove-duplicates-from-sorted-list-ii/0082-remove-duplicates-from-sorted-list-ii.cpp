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
        
        struct ListNode* headNode = new struct ListNode;
        headNode->next = first;
        headNode->val = INT_MIN;

        set<int> buffer;
        
        int previousValue = INT_MIN;
        struct ListNode* previous = headNode;
        while (previous->next) {

            struct ListNode* current = previous->next;
            if (current->val == previousValue) {

                buffer.insert (current->val);
            }

            previousValue = current->val;
            previous = current;
        }

        previous = headNode;
        while (previous->next) {

            struct ListNode* current = previous->next;
            if (buffer.find(current->val) != buffer.end()) {

                previous->next = current->next;
                delete current;
                continue;
            }

            previous = previous->next;
            if (previous == NULL) break;
        }

        struct ListNode* answer = headNode->next;
        delete headNode;

        return answer;
    }
};