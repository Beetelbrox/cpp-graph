#include <iostream>
#include <vector>
#include <tuple>
#include "adjlist.hpp"

using namespace std;


Adjlist::Adjlist(bool dir):
    num_vertices{0},
    num_edges{0},
    is_directed{dir}
{
}

int Adjlist::add_vertex() {
    in_edges.push_back(vector<edge_type>());
    out_edges.push_back(vector<edge_type>());
    vertex_alive.push_back(1);
    ++num_vertices;
    return 0;
}

int Adjlist::add_edge(size_t src, size_t dst, int weight) {
    if (!edge_exists(src, dst)) {
        out_edges[src].push_back(make_tuple(dst, weight, 1));
        if ( !is_directed ) in_edges[dst].push_back(make_tuple(src, weight, 1));
        ++num_edges;
        return 0;
    }
    return -1;
}

bool Adjlist::vertex_exists(size_t v) const {
    if (v >= num_vertices) return false;
    else if (!vertex_alive[v]) return false;
    return true;
}

bool Adjlist::edge_exists(size_t src, size_t dst) const {
    if ( src >= num_vertices || dst >= num_vertices ) {
        cerr << "Error [Adjlist] - One or both of the edge's ends doesn't exist." << endl;
        return false;
    } else if (!vertex_alive[src] || !vertex_alive[dst]) {
        cerr << "Error [Adjlist] - One or both of the edge's ends was deleted." << endl;
        return false;
    }

    for (size_t i=0; i < out_edges[src].size(); ++i) {
        if (get<0>(out_edges[src][i]) == dst) return true;
    }
    return false;
}