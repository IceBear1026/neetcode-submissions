// each node needs a value and a pointer to the next node
class LinkedList {
    private:
        struct Node {
            int val;
            // pointer to the next node
            Node* next;
        };

        Node* head;
        Node* tail;
        int size;

    public:
        LinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
            this->size = 0;
        }

        int get(int index) {
            if (index < 0 || index >= this->size) {
                return -1;
            }

            Node* current = this->head;

            for (int i = 0; i < index; i++) {
                // this is just a way to go to the next node in the linked list.
                current = current->next;
            }
            return current->val;
        }

        // create the heap node, connect its "next" pointer, and update head. 
        void insertHead(int val) {
            Node* new_node = new Node();
            // set the value of the new node
            new_node->val = val;
            // set the next pointer of the new node to the current head
            new_node->next = this->head;
            // update the head to point to the new node
            this->head = new_node;

            // basically if the list was empty, we are setting both head and tail to the new node. 
            if (this->tail == nullptr) {
                this->tail = new_node;
            }
            this->size++;
        } 
                                        
        void insertTail(int val) {
            Node* new_node = new Node();
            new_node->val = val;
            new_node->next = nullptr;

            // checking if the list is empty.
            if (this->tail == nullptr) {
                this->head = new_node;
            } else {
                this->tail->next = new_node;
            }
            this->tail = new_node;
            this->size++;
        }

        // remove the i-th node (0-indexed). If the index is out of bounds, return false, otherwise return true.
        bool remove(int index) {
            if (index < 0 || index >= this->size) {
                return false;
            }
            // reason why we are making edge case when index == 0 is because the head node has no previous node.
            if (index == 0) {
                Node* node_to_delete = this->head;

                this->head = this->head->next;

                delete node_to_delete;
                this->size--;

                // if the node we just deleted was the only node in the list, we need to update the tail to be nullptr as well. 
                if (this->size == 0) {
                    this->tail = nullptr;
                }
                return true;
            }
            // now we are in the case where index > 0, so we need to find the node before the one we want to delete. 
            // for index > 0, find the node immediately before the one we want to delete. 

            Node* previous = this->head;
            // we are looping through the linked list one right before the node we want to delete. The reason we are doing index - 1 is because we want to stop at the node before the one we want to delete. 
            for (int i = 0; i < index - 1; i++) {
                previous = previous->next;
            }

            // now we are at the node before the one we want to delete. 
            Node* node_to_delete = previous->next;
            
            // we are setting the same next pointer of the node we are deleting to the next pointer of the previous. 
            previous->next = node_to_delete->next;

            // If the removed node was the last node, previous is not the new last node. 
            if (node_to_delete == this->tail) {
                this->tail = previous;
            }

            delete node_to_delete;
            this->size--;
 
            return true;
        }

        vector<int> getValues() {
            // create the vector we will return
            vector<int> values;
            // find the current node starting from (first node == this->head)
            Node* current = this->head;
            // for loop through the current linked list with its size. 
            // values.push_back add the values of our current node current->val.
            // move on to next node current = current->next.
            for (int i = 0; i < this->size; i++) {
                values.push_back(current->val);
                current = current->next;
            }
            return values;
        }
};