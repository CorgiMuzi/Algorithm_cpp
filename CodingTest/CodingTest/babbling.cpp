#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    const vector<string> pronounces = { "aya", "ye", "woo", "ma" };
    int result = 0;

    for (string str : babbling) {
        int idx = 0;
        bool flag = false;
        for(int i = 0; i < str.size(); i++) {
            
        }
    }

    return answer;
}

int main() {
    vector<string> babbling = { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" };
 
    cout << solution(babbling);
}