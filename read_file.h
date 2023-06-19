#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> line_read(const string filename) {
    ifstream fileContent(filename);
    vector<string> lines;

    if(!fileContent.is_open()) {
        cerr << "cannot open file" << endl;
        exit(1);
    }
    string line;
    while (getline(fileContent, line)) {
        lines.push_back(line);
    }
    
    // fileContent.close();
    return lines;
}