class DynamicArray {
private:
    int* data;
    int size;
    int capacity;
public:

    // what is this? It's a constructor that initializes the dynamic array with a given capacity. 
    DynamicArray(int capacity) {
        // This may seem confusing because both names are the same, but they refer to two different variables. 
        // "this" points to the current object whose method is running. 
        this->capacity = capacity;
        // equivalent: (*this).capacity = capacity;

        this->size = 0;
        this->data = new int[capacity];
    }

    int get(int i) {
        // This means: get the member variable named data from the current object. Think about it. When we run this function, it will be used like this. AFTER creating an object of "DynamicArray" named "arr", we would call: arr.get(5). We need to point towards this newly created DynamicArray class object and so we will have to use "this->" because that will reference the CURRENTLY POINTED object the "arr".

        // And THAT's why we have "this->data[i]" because this function is within the same code as when the class gets created and we can directly reference the constructor values like this in our helper functions. 

        // Access the data member belonging to the current object, and return the integer at index i

        /*
        If we call arr.get(i), C++ automatically makes "this"
        point to arr while this method runs.

        this->data gets arr's data pointer.
        data[i] accesses the integer stored at index i.
        */
        return this->data[i];
        // (*this).data
    }

    void set(int i, int n) {
        // Set the value at index i to n for the current object.
        this->data[i] = n;
    }

    // pushback adds a new element to the end of the dynamic array. If the array is full, it resizes the array first. 
    void pushback(int n) {
        if (this->size == this->capacity) {
            this->resize();
        }
        int current_last_index = this->size;
        // we will first create the logic of adding to the end of array. 
        this->data[current_last_index] = n;
        this->size++;

    }

    // popback removes the last element from the dynamic array and returns it. It also decreases the size.
    int popback() {
        int current_last_index = this->size - 1;
        int value_to_return = this->data[current_last_index];

        // we don't need to explicitly delete the last element because decreasing the size effectively removes it from the dynamic array. The memory is still allocated, but the element is no longer considered part of the array.
        this->size--;
        return value_to_return;
    }

    void resize() {
        int new_capacity_size = this->capacity * 2;
        int current_capacity_size = this->size;
        int* new_larger_array= new int[new_capacity_size];
        for (int i = 0; i < current_capacity_size; i++) {
            new_larger_array[i] = this->data[i];
        }
        // So now we just finished creating double the capacity array and copied over the old elements from the original array using "this->data[i]"
        // Now we need to update the data pointer and capacity to point to the new array and reflect the new capacity. 
        delete[] this->data;

        // delete[] frees the memory previously allocated for the old data array, so we don't have a memory leak. 

        this->data = new_larger_array;
        this->capacity = new_capacity_size;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }
};