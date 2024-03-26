#include <iostream>
#include <string>
#include <map>

using namespace std;

constexpr int MULTIPLIER = 65536;

void Simplify(string& str) {
    for (char& c : str) {
        if (isalpha(c) && c < 97) c += 32;
    }
}

int solution(string a, string b) {
    int answer = 0;

    Simplify(a);
    Simplify(b);

    map<string, int> a_map, b_map;

    for (int i = 0; i < a.length() - 1; ++i) {
        if (!isalpha(a[i]) || !isalpha(a[i + 1])) continue;
        string part = "";
        part += a[i];
        part += a[i + 1];

        a_map[part]++;
    }

    for (int i = 0; i < b.length() - 1; ++i) {
        if (!isalpha(b[i]) || !isalpha(b[i + 1])) continue;
        string part = "";
        part += b[i];
        part += b[i + 1];
        
        b_map[part]++;
    }

    if (a_map.empty() && b_map.empty()) return MULTIPLIER;

    float intersection = 0, unionsection = 0;

    cout << "a_map\n";

    for (map<string, int>::iterator elem = a_map.begin(); elem != a_map.end(); ++elem) {
        cout << elem->first << "->" << elem->second << "\n";
        intersection += min(elem->second, b_map[elem->first]);
        unionsection += max(elem->second, b_map[elem->first]);
    }

    for (map<string, int>::iterator elem = b_map.begin(); elem != b_map.end(); ++elem) {
        if (a_map[elem->first] != 0) continue;
        unionsection += max(elem->second, a_map[elem->first]);
    }

    answer = (intersection / unionsection) * MULTIPLIER;
    return answer;
}

int main() {
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);
    cout << solution(a, b);
}

