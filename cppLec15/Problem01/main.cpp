#include <iostream>
#include <set>
#include <string>
#include <fstream>
using namespace std;

int main() {
    set<string> list;
    ifstream input("name.txt");
    string tmp;

    while (getline(input, tmp)) {
        list.insert(tmp);
    }

    input.close();

    decltype(list)::iterator it = list.begin();
    while (it != list.end()) {
        cout << *it << endl;
        it++;
    }

    return 0;
}
