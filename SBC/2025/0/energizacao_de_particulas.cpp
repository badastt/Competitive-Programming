#include <bits/stdc++.h>
using namespace std;

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pii>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define sz(x) (int)x.size()
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define clr(x) memset(x, 0, sizeof(x))
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

/* DEBUG */
#define debug(x) cout << #x << ": " << (x) << "\n";
template <class T>
void debug_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ", "; cout << "\b\b}\n"; }

/* UTILS */
#define MOD 1000000007
const int MAX_N = 1e5 + 5;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define eb emplace_back
#define ff first
#define ss second
#define PI acos(-1)
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
constexpr ll LINF = 1LL << 62;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long x = 1, y, k;

    cin >> y >> k;
	
	vll div;
	for (ll i = 1; i <= sqrt(y); i++) {
		if (y % i == 0) {
			div.pb(i);
			div.pb(y / i);
		}
	}
	
	sort(div.rbegin(), div.rend());
	ll last = sz(div)-1;
	
	while (k--) {
		for (ll i = 0; i <= last; i++) {
			if (x % div[i] == 0) {
				last = i;
				
				if (last == 0) {
					x += y*(k+1);
					k = 0;
					break;
				}
				
				ll min = INF;
				ll min_idx = 0;
				
				for (ll j = 0; j < last; j++) {
					
					if (div[j] % div[last] == 0) {
						if (((div[j]-x) / div[last]) < min) {
							min = ((div[j]-x) / div[last]);
							min_idx = j;
						}
					}
				}
				
				if (min <= k) {
					x += (min * div[last]);
					k -= (min-1);
				} else {
					x += (k+1) * div[last];
					k = 0;
				}
				
				last = min_idx;
			}
		}
	}
	
    cout << x << endl;
}
