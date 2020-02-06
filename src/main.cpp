#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "graph.hpp"

using namespace std;

void tokenize_line( const string &line, string *tokenized_line, char sep=' ') {
    stringstream ss(line);
    getline(ss, *tokenized_line, sep);
    getline(ss, *(tokenized_line+1), sep);
    getline(ss, *(tokenized_line+2), sep);
}

int main() {
    Graph<string> g;
    ifstream f ("data/co-occurrences50.csv");
    if (!f.is_open()) {
        cerr << "Error: Unable to open file" << endl;
        return -1;
    }
    string tokenized_line[3];
    string line;
    // Preload
    while (getline(f, line)) {
        tokenize_line(line, tokenized_line, ',');
        g.add_vertex(tokenized_line[0]);
        g.add_vertex(tokenized_line[1]);
        g.add_edge(tokenized_line[0], tokenized_line[1], stoi(tokenized_line[2]));

    }
    cerr << "Num vertices: " << g.get_num_vertices() << endl;
    cerr << "Num edges: " << g.get_num_edges() << endl;
    g.teste();
    return 0;
}