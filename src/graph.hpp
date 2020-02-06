#ifndef _GRAPH_GUARD
#define _GRAPH_GUARD

#include "adjlist.hpp"
#include <unordered_map>
#include <string>
#include <tuple>
#include <utility>
#include <iterator>
#include <iostream>


// Let's assume for the moment that T is hashable for the unordered map
template <typename T = std::string>
class Graph: public AdjList {
 public:
  Graph(bool directed=0);
  int add_vertex(const T &label);
  int add_edge(const T &src_label, const T &dst_label, int weight=1);
  bool vertex_exists(const T &label) const;
  bool edge_exists(const T &src_label, const T &dst_label) const;
  void teste() const;
    
 private:
  size_t get_vertex_ix(const T &label);

  std::unordered_map<T, size_t> vertex_map_;
  
};

template <typename T>
void Graph<T>::teste() const {
    for(size_t i=0; i < num_vertices_;++i) {
        std::cout << get_degree(i) << std::endl;
    }
}

// Template Definition
// Private Methods

template <typename T>
size_t Graph<T>::get_vertex_ix(const T &label) {
    try {
        return vertex_map_.at(label);      // vector::at throws an out-of-range
    } catch (const std::out_of_range& oor) {
        return num_vertices_;
    }
}

// Public Methods

template <typename T>
Graph<T>::Graph(bool directed): AdjList(directed) {}

template <typename T>
int Graph<T>::add_vertex(const T &val) {
    if( vertex_map_.emplace(val, num_vertices_).second ) {
        AdjList::add_vertex();
        return 0;
    }
    return -1;
}

template <typename T>
int Graph<T>::add_edge(const T &src_label, const T &dst_label, int weight) {
    size_t src_ix = get_vertex_ix(src_label);
    size_t dst_ix = get_vertex_ix(dst_label);
    //if (src_ix >= num_vertices_ || dst_ix >= num_vertices_ || is_valid_edge(src_ix, dst_ix)) return -1;
    AdjList::add_edge(src_ix, dst_ix, weight);
    return 0;
}

template <typename T>
bool Graph<T>::vertex_exists(const T &label) const {
    return get_vertex_ix(label) < num_vertices_;
}

template <typename T>
bool Graph<T>::edge_exists (const T &src_label, const T &dst_label) const{
    return AdjList::is_valid_edge(get_vertex_ix(src_label), get_vertex_ix(src_label));
}

#endif