#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

vector<int> bulbs(10, 1023);
pii dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int ans = 101;

void ToggleLight(vector<int>& v, const pii pos) {
	int x = pos.first, y = pos.second;
	v[x] ^= (1 << y);
	for(int i = 0; i < 4; ++i) {
		int nx = x + dir[i].first, ny = y + dir[i].second;
		if(nx < 0 || ny < 0 || nx >= 10 || ny >= 10) continue;
		v[nx] ^= (1 << ny);
	}
}

int TurningOff(vector<int> v, int id) {
	int toggle = 0;
	for(int c = 0; c < 10; ++c) {
		if(id & (1 << c)) {
			toggle++;
			ToggleLight(v, make_pair(0, c));
		}
	}
	
	for(int r = 1; r < 10; ++r) {
		for(int c = 0; c < 10; ++c) {
			if((v[r - 1] & (1 << c)) == 0) continue;
			ToggleLight(v, make_pair(r, c));
			toggle++;
		}
	}

	if(v.back() != 0) return 101;
	
	return toggle;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	for(int r = 0; r < 10; ++r) {
		for(int c = 1; c <= 10; ++c) {
			char bulb; cin >> bulb;
			if(bulb == '#') {
				bulbs[r] &= ~(1 << (10 - c));
			}
		}
	}

	for(int i = 0; i < (1<<10); ++i) {
		ans = min(ans, TurningOff(bulbs, i));
	}
	
	cout << ans << endl;
}