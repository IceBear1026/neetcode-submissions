class Deque {
private:
    struct Node {
        int val = 0;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    int size;
    Node* head;
    Node* tail;

public:
    Deque() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    bool isEmpty() {
        if(this->head == nullptr){
            return true;
        } else {
            return false;
        }
    }

    void append(int value) {
        Node* new_node = new Node();
        new_node->val = value;

        if(size == 0) {
            this->head = new_node;
            this->tail = new_node;

            this->size++;
            return;
        }

        Node* current = this->tail;

        current->next = new_node;
        new_node->prev = current;

        new_node->next = nullptr;
        this->tail = new_node;

        this->size++;
    }

    void appendleft(int value) {
        Node* new_node = new Node();
        new_node->val = value;

        if(size == 0) {
            this->head = new_node;
            this->tail = new_node;

            this->size++;
            return;
        }

        new_node->next = this->head;
        this->head->prev = new_node;

        this->head = new_node;
        this->size++;
    }

    int pop() {
        if(size == 0){
            return -1;
        }
        int return_value = this->tail->val;

        Node* node_to_delete = this->tail;

        if (this->size == 1) {
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            this->tail = this->tail->prev;

            this->tail->next = nullptr;
        }

        delete node_to_delete;
        this->size--;
        return return_value;
    }

    int popleft() {
        if(size == 0){
            return -1;
        }

        int return_value = this->head->val;
        Node* node_to_delete = this->head;
        if (this->size == 1){
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            this->head = this->head->next;

            this->head->prev = nullptr;
        }
        delete node_to_delete;
        this->size--;
        return return_value;
    }
};
