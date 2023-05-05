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
			if (*iter < '0') {
				if (iter == channel.begin()) {
					channel = channel.substr(1, channel.size()-1);
				}
				else {
					*(iter - 1) -= 1;
					*iter = '9';
				}
			}
		}

		cout << "lower_channel: " << channel << "\n";
		if (channel < "0") break;
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
				*iter = '0';
				if (iter == channel.begin()) {
					channel = '1' + channel;
				}
				else {
					*(iter - 1) += 1;
				}
			}
		}

		cout << "upper_channel: " << channel << "\n";
		if (channel > "1000000") break;
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

	string upper = getUpperBound(channel), lower = getLowerBound(channel);
	
	int upperDiff = stoi(upper) - stoi(channel) + upper.size(), lowerDiff = stoi(channel) - stoi(lower) + lower.size();
	int defaultDiff = abs(DEFAULT_CHANNEL - stoi(channel));

	if (upperDiff < lowerDiff) {
		cout << ((upperDiff < defaultDiff) ? upperDiff : defaultDiff);
	}
	else {
		cout << ((lowerDiff < defaultDiff) ? lowerDiff : defaultDiff);
	}
}