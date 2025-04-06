#include <iostream>

#include "graph.hpp"

void output_graph(const graph & g, std::ostream & os){
    os << "p td " <<  g.num_vertices() << " " << g.num_edges() << std::endl;
    for(auto v: g.vertices()){
        for(auto u: g.neighbours(v)){
            if (u < v){
                os << v+1 << " " << u+1 << std::endl;
            }
        }
    }
}

