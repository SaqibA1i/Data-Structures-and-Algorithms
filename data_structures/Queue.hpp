template <typename T>

// Stacks follow LIFO Last in First out
class Queue : public LinkedList<T>{
    public:
        Queue(){
        }

        void enqueue(T value){
            LinkedList::insert(value,0);
        }
        // O(1) constant
        void dequeue(){
            LinkedList::remove(0);
        }
};