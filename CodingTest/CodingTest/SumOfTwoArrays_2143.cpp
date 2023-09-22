#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T = 0, n = 0, m = 0;
int A[1000], B[1000];
vector<int> sumA, sumB;


int main() {
   cin >> T;
   cin >> n;

   for (int i = 0; i < n; ++i) {
      cin >> A[i];
   }

   cin >> m;
   for (int i = 0; i < m; ++i) {
      cin >> B[i];
   }

   int sum = 0;
   for (int i = 0; i < n; ++i) {
      sum = A[i];
      sumA.push_back(sum);
      for (int j = i + 1; j < n; ++j) {
         sum += A[j];
         sumA.push_back(sum);
      }
   }

   for (int i = 0; i < m; ++i) {
      sum = B[i];
      sumB.push_back(sum);
      for (int j = i + 1; j < m; ++j) {
         sum += B[j];
         sumB.push_back(sum);
      }
   }

   sort(sumB.begin(), sumB.end());

   long long answer = 0;
   for (vector<int>::iterator a = sumA.begin(); a != sumA.end(); ++a) {
      int diff = T - *a;
      vector<int>::iterator ub = upper_bound(sumB.begin(), sumB.end(), diff);
      vector<int>::iterator lb = lower_bound(sumB.begin(), sumB.end(), diff);
      answer += (ub - lb);
   }

   cout << answer;
}