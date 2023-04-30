#include <iostream>
#include <vector>

int savePoint = 0;

void Merge(std::vector<int>& vec, int p, int q, int r) {
	int i = p, j = q + 1;
	std::vector<int> tempVec;
	while (i <= q && j <= r) {
		if (vec[i] <= vec[j]) {
			tempVec.push_back(vec[i++]);
			savePoint++;
		}
		else {
			tempVec.push_back(vec[j++]);
			savePoint++;
		}
	}

	while (i <= q) {
		tempVec.push_back(vec[i++]);
		savePoint++;
	}

	while (j <= r) {
		tempVec.push_back(vec[j++]);
		savePoint++;
	}

	vec = tempVec;
}

void MergeSort(std::vector<int>& vec, int p, int r) {
	int q;
	if (p < r) {
		q = (p + r) / 2;
		MergeSort(vec, p, q);
		MergeSort(vec, q+1, r);
		Merge(vec, p, q, r);
	}
	
}

int main() {

	int vecSize, targetPoint;
	std::cin >> vecSize >> targetPoint;

	std::vector<int> sampleVec;
	int inputValue;
	for (std::vector<int>::size_type i = 0; i < vecSize; ++i) {
		std::cin >> inputValue;
		sampleVec.push_back(inputValue);
	}

	MergeSort(sampleVec, 0, vecSize - 1);

	for (std::vector<int>::iterator iter = sampleVec.begin(); iter != sampleVec.end(); ++iter) {
		std::cout << *iter << " ";
	}

	return 0;
}