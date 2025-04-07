#include "graph.hpp"
#include "generators.hpp"
#include "io.hpp"


int main(int argc, char ** argv){
    if(argc != 3){
        std::cout << "Run this program as " << argv[0] << " vertices edges" << std::endl;
        return 1;
    }
    size_t n = atoi(argv[1]);
    size_t m = atoi(argv[2]);
    graph g = random_graph(n,m);
    output_graph(g,std::cout);
}