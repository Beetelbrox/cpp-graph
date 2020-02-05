#ifndef _GRAPH_GUARD
#define _GRAPH_GUARD

#include <unordered_map>
#include <string>
#include <vector>
#include <tuple>
#include <iterator>
#include "adjlist.hpp"

// Template declaration

template <typename T>
class Graph: public Adjlist {
    std::unordered_map<T, size_t> vertex_map;

    size_t get_vertex_ix(const T &val);

public:
    Graph(bool dir=0);
    int add_vertex(const T &val);
    int add_edge(const T &src, const T &dst, int weight=1);
    bool vertex_exists(const T &val) const;
    bool edge_exists(const T &src, const T &dst) const;

};

// Template Definition
// Private Methods

template <typename T>
size_t Graph<T>::get_vertex_ix(const T &val) {
    typename std::unordered_map<T, size_t>::const_iterator map_it = vertex_map.find(val);
    return (map_it == vertex_map.end()) ? num_vertices : map_it->second;
}

// Public Methods

template <typename T>
Graph<T>::Graph(bool dir): Adjlist(dir) {
}

template <typename T>
int Graph<T>::add_vertex(const T &val) {
    if( vertex_map.emplace(val, num_vertices).second ) return Adjlist::add_vertex();
    //std::cerr << "Error [Graph - Add vertex] Vertex '" << val << "' already exists" << std::endl;
    return -1;
}

template <typename T>
int Graph<T>::add_edge(const T &src, const T &dst, int weight) {
    size_t src_ix = get_vertex_ix(src);
    size_t dst_ix = get_vertex_ix(dst);
    /*
    if (src_ix >= num_vertices || dst_ix >= num_vertices) {
        std::cerr << "Error [Graph] - One or both of the edge's ends doesn't exist." << std::endl;
        return -1;
    }
    */
    return Adjlist::add_edge(src_ix, dst_ix, weight);
}

template <typename T>
bool Graph<T>::vertex_exists(const T &val) const {
    return get_vertex_ix < num_vertices;
}

template <typename T>
bool Graph<T>::edge_exists (const T &src, const T &dst) const{
    return edge_exists(get_vertex_ix(src), get_vertex_ix(src));
}

#endif