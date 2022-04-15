#include<bits/stdc++.h>
#define LL long long
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

void debug() {
    cerr << endl;
}
 
template<typename Head, typename... Tail>
void debug(Head H, Tail... T) {
    cerr << " " << H;
    debug(T...);
}
 
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)

const int maxn = 10;
int m, u, v, c;
vector<int> edge[maxn];
string s = "999999999";
unordered_map<string, int> cnt;
queue<string> Q;

int main() {
	read(m);
	for (int i = 0; i < m; ++i) {
		read(u); read(v);
		edge[u-1].PB(v-1);
		edge[v-1].PB(u-1);
	}
	for (int i = 1; i <= 8; ++i) {
		read(c);
		s[c - 1] = i + '0';
	}
	cnt[s] = 0;
	Q.push(s);

	while (!Q.empty()) {
		string cur = Q.front(); Q.pop();
		string buf = cur;
		int Cnt = cnt[cur];
		for (int i = 0; i < 9; ++i) if (cur[i] == '9') { v = i; break; }

		for (auto it: edge[v]) {
			buf = cur;
			swap(buf[v], buf[it]);
			if (cnt.count(buf) == 0) {
				cnt[buf] = Cnt + 1;
				Q.push(buf);
				continue;
			}
			int cnt2 = cnt[buf];
			if (Cnt + 1 < cnt2) {
				cnt[buf] = Cnt + 1;
				Q.push(buf);
			}
		}
	}
	
	cout << ((cnt.count("123456789")==0)?-1:cnt["123456789"]) << '\n';
	return 0;
}