#include <vector>
#include <unordered_set>
#include <cassert>

#include "graph.hpp"

graph::graph(size_t n):alist(n){}
void graph::add_edge(size_t u, size_t v){
    assert(u != v);
    alist[u].insert(v);
    alist[v].insert(u);
}
size_t graph::num_vertices() const{
    return alist.size();
}
size_t graph::num_edges() const{
    size_t s = 0;
    for(const auto & v: alist){
        s += v.size();
    }
    return s/2;
}
std::vector<size_t> graph::vertices() const{
    std::vector<size_t> res;
    for(size_t i = 0; i < alist.size(); ++i){
        res.push_back(i);
    }
    return res;
}
const std::unordered_set<size_t> & graph::neighbours(size_t v) const{
    return alist[v];
}

graph graph_union(const std::vector<graph> & gs){
    size_t N = 0;
    for(const auto & g: gs){
        N += g.num_vertices();
    }
    graph res(N);
    size_t o = 0;
    for(const auto & g: gs){
        for(auto u: g.vertices()){
            for(auto v: g.neighbours(u)){
                res.add_edge(u+o, v+o);
            }
        }
        o += g.num_vertices();
    }
    return res;
}
