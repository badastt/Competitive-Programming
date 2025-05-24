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

/* DEBUG */
#define debug(x) cout << #x << ": " << (x) << "\n";
template <class T>
void debug_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ", "; cout << "\b\b}\n"; }

/* UTILS */
#define MOD 1000000007
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
	
	ll n;
	vi bin;
	
	cin >> n;
	
	ll n_copia = n;
	
	while (n_copia > 0) {
		bin.pb(n_copia % 2);
		n_copia >>= 1;
	}
	reverse(bin.begin(), bin.end());
	
	ll zeros = count(bin.begin(), bin.end(), 0);
	ll ones = count(bin.begin(), bin.end(), 1);
	
	if (ones == 1 && sz(bin) != 1) {
		bin.ppb();
		for (int i = 0; i < sz(bin); i++)
			bin[i] = 1;
	} else {
		
		for (int i = 0, j = sz(bin)-1; i <= j; i++, j--) {
			if (bin[i] == 1 && ones > 0 && sz(bin) % 2 == 1 || bin[i] == 1 && ones > 1 && sz(bin) % 2 == 0) {
				bin[j] = 1;
				ones -= 2;
			} else {
				bin[i] = 0;
				bin[j] = 0;
			}
		}
		
		if (sz(bin) % 2 == 1) {
			
			bin[sz(bin)/2] = 1;
			
			reverse(bin.begin(), bin.end());
			
			ll with = 0;
			ll multiplier = 1;
			for (int i = 0; i < sz(bin); i++) {
				with += bin[i] * multiplier;
				multiplier *= 2;
			}
			
			reverse(bin.begin(), bin.end());
			
			if (with > n)
				bin[sz(bin)/2] = 0;

		}
	}
	
	reverse(bin.begin(), bin.end());
	
	ll total = 0;
	ll multiplier = 1;
	for (int i = 0; i < sz(bin); i++) {
		total += bin[i] * multiplier;
		multiplier *= 2;
	}
	cout << total << endl;
	
	
	
	
	/*
	bool finish = false;
	
	
	
	for (ll i = 0; i < sz(bin); i++) {
		
		if (bin[i] == 0)
			continue;
		
		if (finish)
			break;
		
		for (ll j = sz(bin)-1; j >= 0; j--) {
			
			if (finish)
				break;

			for (ll k = i, l = j; k > l; k++, l--) {
				if (k <= l) {
					start = i;
					end = j;
					finish = true;
				}
				
				if (bin[k] != bin[l])
					break;
			}
		}
	}
	*/
	
	//cout << start << " " << end << endl;

}
