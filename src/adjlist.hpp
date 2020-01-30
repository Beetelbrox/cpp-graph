#ifndef _ADJLIST_GUARD
#define _ADJLIST_GUARD

#include <vector>
#include <utility>

class Adjlist {
    typedef std::pair<size_t, int> edge_type;
    std::vector<std::vector<edge_type>> in_edges;
    std::vector<std::vector<edge_type>> out_edges;
    std::vector<bool> vertex_alive;

protected:
    size_t num_vertices;
    size_t num_edges;
    bool is_directed;

    Adjlist(bool dir=0);
    int add_vertex();
    int add_edge(size_t src, size_t dst, int weight=1);
    bool vertex_exists(size_t v) const;
    bool edge_exists(size_t src, size_t dst) const;

public:
    size_t get_num_vertices() const;
    size_t get_num_edges() const;
};

#endif