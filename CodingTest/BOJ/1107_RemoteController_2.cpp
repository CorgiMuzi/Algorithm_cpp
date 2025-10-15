#include <iostream>
#include <string>
#include <map>
#include <algorithm>

#define DEFAULT_CHANNEL 100

using namespace std;

map<int, bool> isBroken;

bool isNonValidNumber(char c) {
	int num = c - '0';
	return isBroken[num];
}

string getLowerBound(string channel) {
	string::iterator iter = find_if(channel.begin(), channel.end(), isNonValidNumber);
	while (iter != channel.end()) {
		while (isNonValidNumber(*iter)) {
			*iter = *iter - 1;
			if (*iter <= '0') {
				if (channel.size() == 1) {
					if (isBroken[0]) {
						channel = "1000001";
						return channel;
					}
					
					channel = "0";
					iter = channel.end();
					break;
				}

				if (iter == channel.begin()) {
					channel = channel.substr(1, channel.size());
					iter = channel.begin();
					*iter = '9';
				}
				else {
					*(iter - 1) = *(iter - 1) - 1;
				}
			}

			for (string::iterator tempIt = iter + 1; tempIt != channel.end(); ++tempIt) {
				*tempIt = '9';
			}

		}

		if (stoi(channel) == 0) break;
		iter = find_if(channel.begin(), channel.end(), isNonValidNumber);
	}

	return channel;
}

string getUpperBound(string channel) {
	string::iterator iter = find_if(channel.begin(), channel.end(), isNonValidNumber);
	while (iter != channel.end()) {
		while (isNonValidNumber(*iter)) {
			*iter = *iter + 1;
			if (*iter > '9') {
				if (iter == channel.begin()) {
					channel = "1" + channel;
					iter = channel.begin() + 1;
					*iter = '0';
				}
				else {
					*(iter - 1) = *(iter - 1) + 1;
				}
			}

			for (string::iterator tempIt = iter + 1; tempIt != channel.end(); ++tempIt) {
				*tempIt = '0';
			}
		}
		if (stoi(channel) > 1000000) break;

		iter = find_if(channel.begin(), channel.end(), isNonValidNumber);
	}

	return channel;
}

int main() {
	string channel;
	cin >> channel;

	int numOfBrokens;
	cin >> numOfBrokens;

	for (int i = 0; i < numOfBrokens; ++i) {
		int n;
		cin >> n;

		isBroken[n] = true;
	}

	int defaultDiff = abs(DEFAULT_CHANNEL - stoi(channel));
	if (numOfBrokens == 10) {
		cout << defaultDiff;
		return 0;
	}

	string upper = getUpperBound(channel), lower = getLowerBound(channel);

	int upperDiff = stoi(upper) - stoi(channel) + upper.size(), lowerDiff = stoi(channel) - stoi(lower) + lower.size();

	cout << "upper: " << upper << ", lower: " << lower << "\n";

	if (upperDiff < lowerDiff || lower == "1000001") {
		cout << ((upperDiff < defaultDiff) ? upperDiff : defaultDiff);
	}
	else {
		cout << ((lowerDiff < defaultDiff) ? lowerDiff : defaultDiff);
	}

	return 0;
}