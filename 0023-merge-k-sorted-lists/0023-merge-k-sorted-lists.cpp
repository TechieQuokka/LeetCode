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
    void Traversal (struct ListNode* head, priority_queue<int>& heap) {

        if (head == NULL) return;

        for (auto current = head; current != NULL; current = current->next) {

            heap.push (current->val);
        }
        return;
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

public:
    struct ListNode* mergeKLists(vector<struct ListNode*>& lists) {
        
        priority_queue<int> heap;
        for (const auto& head : lists) {

            Traversal (head, heap);
        }

        struct ListNode* head = new struct ListNode;
        if (head == NULL) throw;

        while (!heap.empty()) {

            Insert (head, heap.top());
            heap.pop();
        }

        return head->next;
    }
};