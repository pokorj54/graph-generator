#pragma once

#include<vector>
#include<unordered_set>

class graph{
private:
     std::vector<std::unordered_set<size_t>> alist;
public:
    graph(size_t n);
    void add_edge(size_t u, size_t v);
    size_t num_vertices() const;
    size_t num_edges() const;
    std::vector<size_t> vertices() const;
    const std::unordered_set<size_t> & neighbours(size_t v) const;
};


graph graph_union(const std::vector<graph> & gs);
