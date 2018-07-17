#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    vector<string> argvs(argv, argv+argc);
    argvs.erase(argvs.begin()); // remove the 1st argv
    map<string, set<string> > index;
    for (auto f: argvs) {
        cout << "open: " << f << endl;
        ifstream ifs(f, std::ifstream::in);
        while (ifs.good()) {
            std::string line, word;
            std::getline(ifs, line);
            std::istringstream iss(line);
            while (iss >> word) {
                index[word].insert(f);
            }
        }
    }

    for (auto key: index) {
        cout << std::setw(10) << std::left << key.first << ": ";
        for (auto fn: key.second) cout << fn << " ";
        cout << endl;
    }
    return 0;
}
