#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<int> cargo;
vector<vector<int>> ans;
int N = 0, M = 0;

void Recursion(int last) {
    if (cargo.size() == M) {
        ans.push_back(cargo);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < last) continue;
        cargo.push_back(nums[i]);
        Recursion(nums[i]);
        cargo.pop_back();
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        int num = 0;
        cin >> num;
        if (find(nums.begin(), nums.end(), num) == nums.end()) {
            nums.push_back(num);
        }
    }

    sort(nums.begin(), nums.end(), std::less<int>());

    Recursion(nums[0]);
    for (const vector<int>& elem : ans) {
        for (const int& elem2 : elem) {
            cout << elem2 << " ";
        }
        cout << "\n";
    }
}