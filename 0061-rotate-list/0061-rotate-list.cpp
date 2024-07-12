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
    void Display (struct ListNode* head) {

        if (head == NULL) return;

        for (auto& current = head->next; current != NULL; current = current->next) {

            cout << current->val << " -> ";
        }
        cout << "NULL\n";
        return;
    }

    void Rotate (struct ListNode* head, deque<struct ListNode*>& buffer) {

        if (head == NULL) return;

        struct ListNode* last = buffer.back(); buffer.pop_back();
        buffer.push_front(last);

        last->next = head->next;
        head->next = last;

        last = buffer.back();
        last->next = NULL;
        return;
    }

public:
    struct ListNode* rotateRight(struct ListNode* source, int k) {

        if (source == NULL) return NULL;
        
        struct ListNode* head = new struct ListNode;
        if (head == NULL) throw;

        deque<struct ListNode*> buffer;

        head->next = source;
        for (struct ListNode* current = source; current != NULL; current = current->next) {

            buffer.push_back (current);
        }

        k = k % buffer.size();
        
        for (int repeat = 0; repeat < k; repeat++) {

            Rotate (head, buffer);
        }
        return head->next;
    }
};