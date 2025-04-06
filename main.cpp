#include "graph.hpp"
#include "io.hpp"


int main(void){
    graph a(3);
    a.add_edge(0,1);
    a.add_edge(0,2);
    output_graph(a,std::cout);
}