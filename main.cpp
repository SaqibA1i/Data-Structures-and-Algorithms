#include <iostream>
#include "./data_structures/Graph.hpp"
#include <vector>

int main(){
    std::vector<std::vector<int>> adjacency_list = {{2,3,4},{1,3,5}};
    Graph new_g = Graph(adjacency_list);
    new_g.print();
    return 0;
}