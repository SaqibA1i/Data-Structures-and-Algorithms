#include <iostream>
#include <vector>
#include "./helper structures/AdjacencyList.hpp"

class Graph {
    private:
        AdjacencyList list = AdjacencyList();
    public:
        Graph(std::vector<std::vector<int>> given_list){
            list = AdjacencyList(given_list);
        }

        bool exists(unsigned int index1, unsigned int index2){
            if (index1 < list.size()) {
                for(int i = 0; i <= index1; i++){
                    if(i == index1){
                        if (index2 < list[i].size()) {
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

        void print() {
            for (int i = 0; i < list.size(); i++){
                char vertex = (char) i + 65;
                std::cout << vertex << " : ";
                for (int j = 0; j < list[i].size(); j++){
                    char neighbour = (char) list[i][j] + 65;
                    std::cout<< neighbour;
                    if (j + 1 != list[i].size()) {
                        std::cout << " , ";
                    }
                }
                std::cout<<"\n";
            }
        }
};