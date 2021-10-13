#include <iostream>
#include <vector>
template <typename T>

class LinkedList{
    struct Node {
        T value;
        Node* next;
    };
    private:
        Node* head;
        Node* tail;
        unsigned int size;
    public:
    LinkedList(){
        head = nullptr;
        size = 0;
    }
    ~LinkedList(){
       clear();
    }
    void push(T value){
        if(size == 0){
            Node* newNode = new Node();
            newNode->value = value;
            newNode->next = nullptr;
            head = newNode;
            tail = head;
        }
        else {
            Node* newNode = new Node();
            newNode->value = value;
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
        }
       
        ++size;
    }
    void insert(T value, unsigned int index){
        if(size == 0){
            push(value);
        }
        else if (index > size) {
            std::cout<<"Error: invalid index\n";
        }
        else {
            // loop till just before the index
            Node* p_traverse = head;
            unsigned int counter = 1;
            while(p_traverse!=nullptr){
                if(counter == index){
                    Node *newNode = new Node();
                    newNode->value = value;
                    newNode->next = p_traverse->next;
                    p_traverse->next = newNode;
                    ++size;
                    break;
                }
                p_traverse = p_traverse->next;
                ++counter;
            }
    }
    }
    void remove(unsigned int index){
        if(index >= size){
            std::cout<<"Error With Index Provided\n";
        }
        else{
            if(index == 0){
                Node* p_temp = head;
                head = p_temp->next;
                delete p_temp;
                p_temp = nullptr;
            }
            else{
                Node* p_traversal = head;
                Node* prev = nullptr; 
                while(index!=0){
                    prev = p_traversal;
                    p_traversal = p_traversal->next;
                    --index;
                }
                prev->next = p_traversal->next;
                delete p_traversal;
                p_traversal = nullptr;
            }
            --size;
        }
    }

    void pop(){
        remove(size - 1);
    }

    void clear(){
        while(size!=0){
            remove(0);
        }
    }
    void print(){
        Node* p_traversal = head;
        while(p_traversal!=nullptr){
            std::cout<<p_traversal->value<<" -> ";
            p_traversal=p_traversal->next;
        }
        std::cout<<std::endl;
    }
    void reverse(){
        // iterate through the linked list via for loop
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = head->next;
        while(next!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    unsigned int get_size(){
        return size;
    }

    bool is_empty(){
        return size == 0;
    }
};