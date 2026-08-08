/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* current = head;
        unordered_map<Node*, Node*> mp;
        while(current){
            Node* tmp = new Node(current->val);
            mp[current] = tmp;
            current = current->next;
        }
        current = head;
        while(current){
            Node* tmp = mp[current];
            tmp->next = mp[current->next];
            tmp->random = mp[current->random];
            current = current->next;
        }
        return mp[head];
    }
};
