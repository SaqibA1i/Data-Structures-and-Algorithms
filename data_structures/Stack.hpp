#include <iostream>
#include <vector>
template <typename T>

// Stacks follow LIFO Last in First out
class Stack : public LinkedList<T>{
    public:
        Stack(){
        }
        void pop(){
            if(LinkedList<T>::is_empty()){
                std::cout<<"Stack Empty\n";
            }
            else {
                LinkedList<T>::pop();
            }
        }

};