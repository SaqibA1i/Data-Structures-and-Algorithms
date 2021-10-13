#include <iostream>
#include <vector>
/* Represented by nested vectors,
    the vector pointed to by the
    index represents its neighbours
    Example: {{2,3,4},{1,2},{},{}}
             The neighbours of 
             1 -> {2,3,4}
             2 -> {1,2}
             3 -> {}
             4 -> {}
    Space = O(number of edges + vertices)
*/  
class AdjacencyList {
    public:
    // member variables
    std::vector<std::vector<int>> adjacency_list;
    
    // member functions
    AdjacencyList(){
        adjacency_list = {};
    };
    AdjacencyList(std::vector<std::vector<int>> list){
        adjacency_list = list;
    }

    void print() {
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
    unsigned int size(){
        return adjacency_list.size();
    }

    std::vector<int> operator[](int index){
        return adjacency_list[index];
    }
};