#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <utility>
#include <tuple>
#include <vector>
#include <sstream>
#include "graph.hpp"

using namespace std;

vector<string> tokenize_line( const string &line, char sep=' ') {
    
    stringstream ss(line);
    vector<string> tokens;
    string token;
    while(getline(ss, token, sep)) tokens.emplace_back(token);
    return tokens;
}

int main() {
    Graph<string> g;
    ifstream f ("data/co-occurrences50.csv");
    if (!f.is_open()) {
        cerr << "Error: Unable to open file" << endl;
        return -1;
    }

    vector<tuple<string, string, int>> coocurrences;
    vector<string> tokenized_line;
    set<string> words_set;
    string line;
    // Preload
    while (getline(f, line)) {
        tokenized_line = tokenize_line(line, ',');
        g.add_vertex(tokenized_line[0]);
        g.add_vertex(tokenized_line[1]);
        g.add_edge(tokenized_line[0], tokenized_line[1], stoi(tokenized_line[2]));

    }
    cerr << "Num vertices: " << g.get_num_vertices() << endl;
    cerr << "Num edges: " << g.get_num_edges() << endl;
    return 0;
}