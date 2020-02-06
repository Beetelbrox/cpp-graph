#include "adjlist.hpp"
#include <iostream>

using namespace std;

// PUBLIC METHODS

size_t AdjList::get_num_vertices() const { return num_vertices_; }
size_t AdjList::get_num_edges() const { return num_edges_; }
bool AdjList::is_directed() const { return directed_; }

// PROTECTED METHODS

AdjList::AdjList(bool directed):
    num_vertices_{0},
    num_edges_{0},
    directed_{directed}
{}

void AdjList::add_vertex() {
    in_edges_.push_back(vector<EdgeEndpoint>());
    out_edges_.push_back(vector<EdgeEndpoint>());
    vertex_liveness_.push_back(1);
    ++num_vertices_;
    ++active_vertices_;
}

void AdjList::add_edge(size_t src, size_t dst, int weight) {
    out_edges_[src].push_back(make_pair(dst, weight));
    if ( !directed_ ) in_edges_[dst].push_back(make_pair(src, weight));
    ++num_edges_;
}

bool AdjList::is_valid_vertex(size_t v) const {
    if (v >= num_vertices_) return false;
    else if (!vertex_liveness_[v]) return false;
    return true;
}

bool AdjList::is_valid_edge(size_t src, size_t dst) const {
    if ( src >= num_vertices_ || dst >= num_vertices_ ) return false;
    else if (!vertex_liveness_[src] || !vertex_liveness_[dst]) return false;
    if ( !directed_ && in_edges_.size() < out_edges_.size() ) {
        for (size_t i=0; i < in_edges_[src].size(); ++i)
            if (in_edges_[src][i].first == dst) return true;
    } else {
        for (size_t i=0; i < out_edges_[src].size(); ++i)
            if (out_edges_[src][i].first == dst) return true;
    }
    return false;
}

// Assume no loops <TODO> add something to track loops
size_t AdjList::get_degree(size_t v) const {
    if (!directed_) return in_edges_[v].size();
    else return in_edges_[v].size() + out_edges_[v].size();
}

size_t AdjList::get_indegree(size_t v) const {
    return in_edges_[v].size();
}

size_t AdjList::get_outdegree(size_t v) const {
    return out_edges_[v].size(); 
}

// PRIVATE METHODS