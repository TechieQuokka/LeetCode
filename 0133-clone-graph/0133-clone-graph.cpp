/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void BreadthFirstSearch (struct Node* node) {

        bool check[128] = { 0, };

        queue<struct Node*> buffer;
        buffer.push (node);

        while (!buffer.empty()) {

            auto current = buffer.front(); buffer.pop();

            if (check[current->val] == true) continue;
            else check[current->val] = true;

            cout << current->val << " : ";

            for (const auto& element : current->neighbors) {

                buffer.push (element);
                cout << element->val << " ";
            }
            cout << endl;
        }
        return;
    }

public:
    struct Node* cloneGraph(struct Node* node) {
        
        if (node == NULL) return NULL;

        bool check[128] = { 0, };
        struct Node* copies[128] = { NULL, };

        queue<struct Node*> buffer, copyBuffer;
        buffer.push (node);

        struct Node* clone = new struct Node;
        if (clone == NULL) throw;

        clone->val = node->val;
        copyBuffer.push(copies[node->val] = clone);
        
        while (!buffer.empty()) {

            auto current = buffer.front(); buffer.pop();
            auto destination = copyBuffer.front(); copyBuffer.pop();

            if (check[current->val] == true) continue;
            else check[current->val] = true;

            for (const auto& element : current->neighbors) {
                if (copies[element->val]) {
                    destination->neighbors.push_back(copies[element->val]);
                    continue;
                }

                buffer.push (element);

                struct Node* newNode = new struct Node;
                if (newNode == NULL) throw;

                newNode->val = element->val;
                destination->neighbors.push_back (newNode);

                copyBuffer.push(copies[element->val] = newNode);
            }
        }

        return clone;
    }
};