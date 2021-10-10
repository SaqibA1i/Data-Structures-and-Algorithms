#include <iostream>
#include <vector>

class DoublyLinkedList{
    struct Node{
        int value;
        Node* next;
        Node* prev;
    };
    private:
        Node* head;
        Node* tail;
        unsigned int size;

    public:
        DoublyLinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
        ~DoublyLinkedList(){
            clear();
        }

        void insert(int value,unsigned int index){
            if(size == 0){
                Node* newNode = new Node();
                newNode->value = value;
                newNode->prev=nullptr;
                newNode->next = nullptr;
                head = newNode;
                tail = head;
            }
            else if (index > size){
                std::cout<<"Error Invalid index\n";
            }
            else {
                Node* p_traverse = head;
                // get to just before the index
                unsigned int counter = 1;
                while (p_traverse != nullptr) {
                    if(counter == index){
                        Node* newNode = new Node();
                        newNode->value = value;
                        newNode->next = p_traverse->next;
                        newNode->prev = p_traverse;

                        if (p_traverse->next != nullptr){
                            p_traverse->next->prev = newNode;
                        }

                        p_traverse->next = newNode;
                        
                        if (size  == index ){
                            tail = newNode;
                        }
                        break;
                    }
                    p_traverse=p_traverse->next;
                    ++counter;
                }
                
            }
          ++size;   
        };

        void remove(unsigned int index){
            if(size == 1){
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else if (index + 1 > size) {
                std::cout<<"Wrong Index Value\n";
            }
            else {
                Node* p_traverse = head;    
                // get to the index
                unsigned int counter = 0;
                while (p_traverse != nullptr) {
                    if(counter == index){
                        if(index == 0){
                            head = p_traverse->next;
                        }
                        if(p_traverse->prev!=nullptr){
                            p_traverse->prev->next = p_traverse->next;
                        }
                        if (p_traverse->next != nullptr){
                            p_traverse->next->prev = p_traverse->prev;
                        }

                        if (size  == index + 1){
                            tail = p_traverse->prev;
                        }

                        delete p_traverse;
                        p_traverse = nullptr;

                        break;
                    }
                    p_traverse=p_traverse->next;
                    ++counter;
                }
            }
            --size;
        }

        void clear(){
            while(size!=0){
                remove(0);
            }
        }

        void print(){
            Node* p_traversal = head;
            while(p_traversal!=nullptr){
                std::cout<<p_traversal->value<<"<->";
                p_traversal = p_traversal->next;
            }
            std::cout<<"\n";
        }

        void print_reverse(){
            Node* p_traversal = tail;
            while(p_traversal!=nullptr){
                std::cout<<p_traversal->value<<"<->";
                p_traversal = p_traversal->prev;
            }
            std::cout<<"\n";
        }

        unsigned int get_size(){
            return size;
        }

        bool is_empty(){
            return size == 0;
        }
};