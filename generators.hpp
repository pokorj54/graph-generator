#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
#include <random>

#include "graph.hpp" 

graph random_graph(size_t n, size_t m){
    assert(m <= n*(n-1)/2);
    std::vector<std::pair<size_t, size_t>> edges;
    for(size_t i = 0; i < n; ++i){
        for(size_t j = 0; j < i; ++j){
            edges.emplace_back(i, j);
        }
    }
    assert(edges.size() == n*(n-1)/2);
    std::random_device rd;
    std::mt19937 gen(rd());
    shuffle(edges.begin(), edges.end(), gen);
    graph g(n);
    for(size_t i = 0; i<m;++i){
        g.add_edge(edges[i].first, edges[i].second);
    }
    return g;
}
