#include <iostream>
using namespace std;

int main() {
	long long edge[100] = { 1, 1, 1, };
	int testTry = 0;
	cin >> testTry;

	for (int i = 0; i < testTry; i++) {
		int N;
		cin >> N;

		if (N < 4) {
			cout << edge[N - 1] << '\n';
		}
		else {
			for (int i = 3; i < N; i++) {
				edge[i] = edge[i - 2] + edge[i - 3];
			}

			cout << edge[N - 1] << '\n';
		}
	}

}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin, std::cout, std::vector;

int main(){
    int T;
    cin >> T;

    vector<int> inputs(T);

    for(int i=0; i<T; ++i){
        cin >> inputs[i];
    }

    int max = *max_element(inputs.begin(), inputs.end());

    vector<long long> seq;
    seq.push_back(1);
    seq.push_back(1);
    seq.push_back(1);
    seq.push_back(2);
    seq.push_back(2);

    vector<long long>::size_type first = 0, second = 4;

    for(second; second < max; ++second){
        seq.push_back(seq[first] + seq[second]);
        first++;
    }

    for(vector<int>::size_type i=0; i < inputs.size(); ++i){
        cout << seq[inputs[i] - 1] << "\n";
    }
}
*/