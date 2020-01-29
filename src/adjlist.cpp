#include <iostream>
#include <vector>
#include <utility>
#include "adjlist.hpp"

using namespace std;


Adjlist::Adjlist(): directed{0} {
    cout << num_vertices << endl;
}

int Adjlist::add_vertex() {
    in_edges.push_back(vector<pair<std::size_t, int>>());
    out_edges.push_back(vector<pair<std::size_t, int>>());
    vertex_alive.push_back(1);
    ++num_vertices;
}

int Adjlist::add_edge(std::size_t src, std::size_t dst, int weight) {
    if ( src < 0 || src > num_vertices || dst < 0 || dst > num_vertices ) {
        std::cerr << "Error [Adjlist] - Unable to add edge: Vertex index out of bounds." << endl;
        return -1;
    } else if (!vertex_alive[src] || !vertex_alive[dst]) {
        std::cerr << "Error [Adjlist] - Unable to add edge: One or more vertices no longer exist." << endl;
        return -1;
    }
    in_edges[src].push_back(make_pair(dst, weight));
    if (!directed) out_edges[dst].push_back(make_pair(src, weight));
    ++num_vertices;
    return 0;
}

bool Adjlist::contains_vertex(size_t v){

}