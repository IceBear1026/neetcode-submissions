// A hash table (Unordered Map) is a vector of buckets, and each bucket is the head of a small singly linked list.
#include <vector>
using namespace std;
class HashTable {

private:
    struct Node {
        int key;
        int value;
        Node* next;
    };
    int capacity;
    int size; 
    vector<Node*> buckets;

public:
    HashTable(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        // create a vector with capacity elements, and initialize every element to nullptr.
        // this->buckets.assign(capacity, nullptr); also works. 
        // so if the capacity is 4 when creating this class type object, it will create 4 empty nullptr buckets. 
        this->buckets = vector<Node*>(capacity, nullptr);

        /*
        Conceptually:

        this->buckets[0] = nullptr
        this->buckets[1] = nullptr
        this->buckets[2] = nullptr
        this->buckets[3] = nullptr
        */
    }
    /*
    1. Key already exists
    → update its value
    → size does not change

    2. Key does not exist
    → create a new node
    → add it to that bucket
    → size increases
    → possibly resize
    */
    void insert(int key, int value) {
        // find the correct bucket.
        int bucket_index = key % this->capacity;
        Node* current = this->buckets[bucket_index];

        // loop through and non-empty linkedlist and replace the value with given insert value.
        while (current != nullptr) {
            if(current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        // If the execution reaches here, the key was not found.
        // the next step will create and insert a new node. 

        Node* new_node = new Node();
        new_node->key = key;
        new_node->value = value;

        // new_node->next = current;
        // current = new_node;
        // This copies the address stored in the bucket into a separate local pointer.
        // Node* current = this->buckets[bucket_index];

        new_node->next = this->buckets[bucket_index];
        this->buckets[bucket_index] = new_node;

        this->size++;

        // after the size + 1 increases, we should check if we need to resize the hash table. If the size is greater than or equal to half of the capacity, we will resize the hash table.
        if (this->size * 2 >= this->capacity) {
            this->resize();
        }
    }

    int get(int key) {
        // we are using key % capacity to determine which bucket this key will be in. 
        /*
        key 1: 1 % 4 = bucket 1
        key 5: 5 % 4 = bucket 1
        key 9: 9 % 4 = bucket 1

        Those keys collide, so they might be stored like:

        buckets[1]
            |
            v
        [key=1,value=10] -> [key=5,value=50] -> [key=9,value=90]
        */
        int bucket_index = key % this->capacity;

        Node* current = this->buckets[bucket_index];

        // if the current bucket isn't empty
        while (current != nullptr) {
            // check if the key of the current node == the key we are trying to find.
            if (current->key == key){
                return current->value;
            } 
            current = current->next;
        }
        return -1;
    }
    // bool remove(int key) will remove the key-value pair with the given key. If the key is not present, return false, otherwise return true
    bool remove(int key) {
        int bucket_index = key % this->capacity;

        // current is a pointer to the head of the linked list in the bucket.
        // This is copying the address stored in the bucket into a separate local pointer called current.
        Node* current = this->buckets[bucket_index];
        // previous is a pointer to the node before current in the linked list.
        Node* previous = nullptr;
        while (current != nullptr) {
            // we found the node
            if (current->key == key) {
                // since we instantiated the previous pointer to nullptr, if it stays nullptr during loop, it means that the node to remove is the head of the linked list.
                if (previous == nullptr) {
                    // the node to remove is the head of the linked list in the bucket.
                    this->buckets[bucket_index] = current->next;
                } else {
                    // the node to remove is not the head of the linked list in the bucket.
                    previous->next = current->next;
                }
                // free the memory of the removed node
                delete current;
                this->size--;
                return true;
            }

            // along with the while loop, this will traverse across the nodes.
            previous = current;
            current = current->next;
        }
        return false;
    }
    // the final "const" means that this function promises not to modify the HashTable object. 
    int getSize() const {
        return this->size;
    }

    int getCapacity() const {
        return this->capacity;
    }
    /*
    Doubling the bucket vector is not enough. Every existing key must be placed into a bucket again because its bucket index depends on capacity.

    For example:

    key = 5

    Old capacity = 4:
    5 % 4 = 1

    New capacity = 8:
    5 % 8 = 5

    */

    void resize() {
        // storing the doubled value of the capacity of the currently referenced HashTable object.
        int new_capacity = this->capacity * 2;

        // creating a new vector that contains node structs with the new amount (new_capacity) of buckets, and initializing every bucket to nullptr.
        vector<Node*> new_buckets(new_capacity, nullptr);

        // Visit every old bucket.
        for (int i = 0; i < this->capacity; ++i) {
            // visit every nodes in the old bucket's chain by starting at the head of an old bucket
            Node* current = this->buckets[i];

            // Example: (bucket i = 0)
            // current -> [key=9] -> [key=5] -> [key=1] -> nullptr

            // Visit every node in the old bucket's chain.
            while (current != nullptr) {
                // Save the next node before changing current->next.
                Node* next_node = current->next;

                // Find the node's bucket using the new capacity. This will determine where the node will be placed in the new bucket vector.
                // same way we did insert function where we used key % capacity to find the bucket index.
                int new_bucket_index =
                    current->key % new_capacity;

                // Insert the existing node at the front
                // of the new bucket's chain.
                current->next =
                    new_buckets[new_bucket_index];

                new_buckets[new_bucket_index] =
                    current;
                
                /*
                This line:

                current->next = new_buckets[new_bucket_index];

                does not create a new pointer. It changes the pointer already stored inside the current node.

                Remember:

                new_buckets[new_bucket_index]

                is a Node*. It represents the head pointer of that bucket’s linked list.

                So this line means:

                Make the current node’s next pointer point to whatever node is currently at the front of the new bucket.

                Case 1: The new bucket is empty

                Suppose:

                new_buckets[5] -> nullptr

                And:

                current -> [key=5]

                Then:

                current->next = new_buckets[5];

                is equivalent to:

                current->next = nullptr;

                Now:

                current
                |
                v
                [key=5] -> nullptr

                Then the second line:

                new_buckets[5] = current;

                makes the bucket’s head point to that node:

                new_buckets[5]
                    |
                    v
                [key=5] -> nullptr

                So yes: the first line connects the node’s next pointer to the current bucket head, which happens to be nullptr when the bucket is empty.

                Case 2: The new bucket already has a linked list

                Suppose:

                new_buckets[1] -> [key=9] -> nullptr

                And now:

                current -> [key=1]

                This line:

                current->next = new_buckets[1];

                copies the address of key 9 into current->next.

                Now:

                current
                |
                v
                [key=1] -> [key=9] -> nullptr

                new_buckets[1] still points to key 9

                Then:

                new_buckets[1] = current;

                updates the bucket’s head pointer:

                new_buckets[1]
                    |
                    v
                [key=1] -> [key=9] -> nullptr

                You are not attaching current to a mysterious “whole linked list object.” You are copying the address of the first node. But because that first node points to the next node, and so on, that one address gives access to the entire chain.
                */
                
                // Continue through the original old chain.
                current = next_node;
            }
        }

        this->buckets = new_buckets;
        this->capacity = new_capacity;
    }
};
