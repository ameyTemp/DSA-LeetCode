class Node{ //represents a memory block
public:
    int key; 
    int val;
    Node* prev;
    Node* next;
};

class LRUCache {
    int cap;
    Node* head;
    Node* tail; 
    unordered_map<int, Node*> hash; //{key: Node*} hash map
    
public:
    LRUCache(int capacity) {
        cap= capacity;
        head= new Node();
        tail= new Node();
        head->next= tail;
        tail->prev= head;
    }
    
    //add MRU (most recently used) node to head
    void addToHead(Node* &node){
        Node* headNext= head->next;
        head->next= node;
        node->prev= head;
        headNext->prev= node;
        node->next= headNext;
    }
    
    //remove node from its current location
    void remove(Node* &node){
        if(node->prev) node->prev->next= node->next;
        if(node->next) node->next->prev= node->prev;
        node->next= 0;
        node->prev= 0;
    }
    
    int get(int key) {
        
        int ans= -1;
        Node* node= hash[key];
        if(node!= 0){ //over-write the node val if the node corresponding to given key exists
            ans= node->val;
            remove(node);
            addToHead(node);
        }
        return ans;
    }
    
    void put(int key, int value) {
        Node* node= hash[key];
        if(node!= 0){ //if node corresponding to key is present, relocate it next to head (MRU)
            node->val= value;
            remove(node);
            addToHead(node);
            return;
        }
        
        //if the node doesnt exist, create it, set the members, add to hash map.
        Node* newNode= new Node();
        newNode->key= key;
        newNode->val= value;
        hash[key]= newNode;
        addToHead(newNode); //add to the list
        
        if(cap> 0){ //if we still have capacity to accomodate this node, reduce the cap
            cap--;
            return;
        }
        
        if(cap== 0){ //if we dont have remaining cap, we remove the LRU node, which lies dominant next to tail
            Node* tailNode= tail->prev; //LRU node at tail
            remove(tailNode);
            hash[tailNode->key]= 0;
            return;
        }
    }
};