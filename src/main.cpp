#include <iostream>
#include <string>
#include <fstream>
#include "graph.hpp"

using namespace std;

int main() {
    Graph<string> g;
    ifstream f ("data/quijote.txt");
    if (!f.is_open()) {
        cerr << "Error: Unable to open file" << endl;
        return -1;
    }
    return 0;
}