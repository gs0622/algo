#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) return 0;
    string fn((const char *)argv[1]);
    ifstream ifs(fn, std::ifstream::in);
    // ifstream ifs;
    // ifs.open(fn, std::ifstream::in);

    map<string, string> dict;
    while (ifs.good()) {
        char name[224], ip[32];
        ifs.getline(name, 224, ',');
        ifs.getline(ip, 32);
        if (ifs.eof()) break;
        //cout << name << ": " << ip << endl;
        //dict[name] = ip;
        if (dict.find(ip) != dict.end()) cout << "dup: " << ip << ": " << name << endl;
        else dict[ip] = name;
    }
    return 0;
}
