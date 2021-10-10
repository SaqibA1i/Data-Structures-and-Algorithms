#include <iostream>
#include <vector>
template <typename T>

class Graph{
    private:
        std::vector<std::vector<T>> adjacency_list;
    public:
        Graph(std::vector<std::vector<T>> list){
            adjacency_list = list;
        }

        bool exists(unsigned int index1, unsigned int index2){
            if (index1 < adjacency_list.size()) {
                for(int i = 0; i <= index1; i++){
                    if(i == index1){
                        if (index2 < adjacency_list[i].size()) {
                            for(int j = 0; j <= index2; j++){
                                if (j == index2){
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            return false;
        }

        void print(){
            for(int i = 0; i < adjacency_list.size(); i++){
                char vertex = (char) i + 65;
                std::cout << vertex << " : ";
                for(int j = 0; j < adjacency_list[i].size(); j++){
                    char neighbour = (char) adjacency_list[i][j] + 65;
                    std::cout<< neighbour;
                    if(j + 1 != adjacency_list[i].size()){
                        std::cout << " , ";
                    }
                }
                std::cout<<"\n";
            }
        }
};