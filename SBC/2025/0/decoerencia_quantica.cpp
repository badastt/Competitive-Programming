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
	
	int size = 0;
    string s1, s2;

    cin >> size >> s1 >> s2;

    double total = 0;
    double nColapso = 0;
	
    for (int i = 0; i < size; i++)
    {
        if (s1[i] == '*')
            total += 1;
        if (s2[i] == '*')
            nColapso += 1;
    }

    double colapso = total - nColapso;

    double taxa = colapso / total;
	
	printf ("%.2f\n", taxa);

    return 0;
}
