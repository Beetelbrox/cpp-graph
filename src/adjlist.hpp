#ifndef _ADJLIST_GUARD
#define _ADJLIST_GUARD

#include <vector>
#include <utility>

class Adjlist {
    std::size_t num_vertices;
    std::size_t num_edges;
    std::vector<std::vector<std::pair<std::size_t, int>>> in_edges;
    std::vector<std::vector<std::pair<std::size_t, int>>> out_edges;
    std::vector<bool> vertex_alive;
    bool directed;

public:
    Adjlist();
    int add_vertex();
    int add_edge(std::size_t src, std::size_t dst, int weight=1);
    bool contains_vertex(size_t v);

};

#endif