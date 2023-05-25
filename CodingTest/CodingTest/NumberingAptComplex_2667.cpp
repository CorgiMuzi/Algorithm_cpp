#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using std::cin, std::cout;
using std::queue, std::vector;
using std::pair, std::make_pair;
using std::sort;

int map_sz, estateStack = 1;
char** map;
int hDir[4] = { 0, 0, 1, -1 };
int wDir[4] = { 1, -1, 0, 0 };

int numberingEstate(int i, int j) {
    int numberPerEstate = 1;
    queue<pair<int, int>> estate;
    estate.push(make_pair(i, j));
    map[i][j] = ++estateStack + '0';

    while (!estate.empty()) {
        pair<int, int> front = estate.front();
        int h = front.first, w = front.second;
        estate.pop();

        int mh, mw;
        for (int i = 0; i < 4; ++i) {
            mh = h + hDir[i];
            mw = w + wDir[i];

            if (mh >= map_sz || mw >= map_sz || mh < 0 || mw < 0 || map[mh][mw] != '1') continue;

            estate.push(make_pair(mh, mw));
            map[mh][mw] = estateStack + '0';
            numberPerEstate++;
        }
    }

    return numberPerEstate;
}

void findingEstate() {
    vector<int> estates;
    for (int i = 0; i < map_sz; ++i) {
        for (int j = 0; j < map_sz; ++j) {
            if (map[i][j] == '1') {
                estates.push_back(numberingEstate(i, j));
            }
        }
    }

    cout << estates.size() << "\n";
    sort(estates.begin(), estates.end());
    for (const auto& elem : estates) {
        cout << elem << "\n";
    }
}

int main() {
    cin >> map_sz;
    map = new char* [map_sz];

    for (int i = 0; i < map_sz; ++i) {
        map[i] = new char[map_sz];
        for (int j = 0; j < map_sz; ++j) {
            cin >> map[i][j];
        }
    }

    findingEstate();
}