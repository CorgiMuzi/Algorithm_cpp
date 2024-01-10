#include <iostream>
#include <deque>
#include <string>

using std::cin, std::cout, std::deque, std::string;

int main() {
    cin.tie(NULL); std::ios_base::sync_with_stdio(false);
    int T;
    cin >> T;

    while (T--) {
        string cmd;
        cin >> cmd;

        int length;
        cin >> length;

        string str_arr;
        cin >> str_arr;
        string::iterator arr_beg = str_arr.begin() + 1, arr_end = arr_beg + 1;
        deque<int> vec_arr;
        while (arr_end != str_arr.end()) {
            if (*arr_end == ']' || *arr_end == ',') {
                vec_arr.push_back(stoi(str_arr.substr(arr_beg - str_arr.begin(), arr_end - arr_beg)));
                arr_end++;
                arr_beg = arr_end;
            }
            else {
                arr_end++;
            }
        }

        bool isReversed = false;
        bool isError = false;
        for (string::iterator iter_cmd = cmd.begin(); iter_cmd != cmd.end(); ++iter_cmd) {
            if (*iter_cmd == 'R') {
                isReversed = !isReversed;
            }
            else if (*iter_cmd == 'D') {
                if (vec_arr.empty()) {
                    isError = true;
                    break;
                }
                else {
                    if (isReversed) {
                        vec_arr.pop_back();
                    }
                    else {
                        vec_arr.pop_front();
                    }
                }
            }
        }

        if (isError) {
            cout << "error\n";
        }
        else if (vec_arr.empty()) {
            cout << "[]\n";
        }
        else {
            if (!isReversed) {
                cout << "[" << vec_arr.front();
                for (deque<int>::iterator iter = vec_arr.begin() + 1; iter != vec_arr.end(); ++iter) {
                    cout << "," << *iter;
                }
            }
            else {
                cout << "[" << vec_arr.back();
                for (deque<int>::reverse_iterator iter = vec_arr.rbegin() + 1; iter != vec_arr.rend(); ++iter) {
                    cout << "," << *iter;
                }
            }
            cout << "]\n";
        }
    }
}