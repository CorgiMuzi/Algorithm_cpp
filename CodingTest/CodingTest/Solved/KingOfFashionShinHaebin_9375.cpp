#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::string;
using std::map;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int numOfClothes;
        cin >> numOfClothes;

        map<string, int> clothes;
        for (int i = 0; i < numOfClothes; ++i) {
            string clothName, clothType;
            cin >> clothName >> clothType;

            if (clothes.find(clothType) == clothes.end()) {
                clothes[clothType] = 1;
            }
            else {
                clothes[clothType]++;
            }
        }

        int combination = 1;
        for (const auto& cloth : clothes) {
            combination *= (cloth.second + 1);
        }
        cout << (combination - 1) << "\n";
    }
}