class LRUCache {
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
    };
    unordered_map<int, Node*> mp;
    Node* head = NULL;
    Node* tail = NULL;
    int length = 0;
    int capacity = 0;
public:
    void updateImportance(Node* temp){
        // do it if it's head ( if it's head it's sorted)
        if(temp == head) return;
        //do it if it's tail
        if(temp == tail){
            tail = temp->prev;
            temp->prev->next = NULL;
            temp->next = head;
            temp->prev = NULL;
            head->prev = temp;
            head = temp;
            
        }
        //do it if it's middle
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = head;
            temp->prev = NULL;
            head->prev = temp;
            head = temp;
        }
        
    }
    LRUCache(int capacity) {
       this->capacity = capacity;
    }
    
    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* temp = mp[key];
        updateImportance(temp);
        return mp[key]->value;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* ptr = mp[key];
            updateImportance(ptr);
            ptr->value = value;

        }
        else{
            if(length < this->capacity){
                Node* temp = new Node();
                temp->key = key;
                temp->value = value;
                temp->next = head;
                temp->prev = NULL;
                mp[key] = temp;
                if(head!= NULL){

                head->prev = temp;
                }
                head = temp;
                if(length == 0){
                    tail = temp;
                }
                length++;
            }
            else{
                Node* temp = tail;
                if(head == tail){
                    
                    mp.erase(temp->key);
                    head = NULL;
                    tail = NULL;
                }
                else{
                    tail->prev->next = NULL;
                    tail = tail->prev;
                    mp.erase(temp->key);
                }
                delete temp;
                length--;
                Node* temp1 = new Node();
                temp1->key = key;
                temp1->value = value;
                temp1->next = head;
                temp1->prev = NULL;
                mp[key] = temp1;
                if(head!= NULL){
                    head->prev = temp1;
                }
                head = temp1;
                if(length ==0) tail = temp1;
                length++;
            }
        }
        
    }
};
