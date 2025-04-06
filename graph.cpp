#include<vector>
#include<unordered_set>

#include "graph.hpp"

graph::graph(size_t n):alist(n){}
void graph::add_edge(size_t u, size_t v){
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
    return s;
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
