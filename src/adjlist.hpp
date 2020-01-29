#ifndef _ADJLIST_GUARD
#define _ADJLIST_GUARD

#include <vector>
#include <tuple>

class Adjlist {
    typedef std::tuple<size_t, int, int> edge_type;

    size_t num_vertices;
    size_t num_edges;
    std::vector<std::vector<edge_type>> in_edges;
    std::vector<std::vector<edge_type>> out_edges;
    std::vector<bool> vertex_alive;
    bool is_directed;

public:
    Adjlist(bool dir=0);
    int add_vertex();
    int add_edge(size_t src, size_t dst, int weight=1);
    bool vertex_exists(size_t v) const;
    int edge_exists(size_t src, size_t dst) const;

};

#endif