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

vector<vpi> adj(MAX_N, vpi());
vi dist(MAX_N, INF);

const int SPECIFIC_MAX_N = 1e4;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n, m;
	cin >> n >> m;
	
	fo(i, 0, m) {
		int c1, c2, p;
		cin >> c1 >> c2 >> p;
		
		adj[c1].eb(c2 + SPECIFIC_MAX_N, p);
		adj[c1+SPECIFIC_MAX_N].eb(c2, p);
		
		adj[c2].eb(c1 + SPECIFIC_MAX_N, p);
		adj[c2+SPECIFIC_MAX_N].eb(c1, p);
	}
	
	priority_queue<pii, vpi, greater<pii>> pq;
	pq.push({0, 1}); //{0, start node}
	dist[1] = 0; //IMPORTANT
	
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		for (auto &[v, w] : adj[u]) {
			if (dist[u]+w >= dist[v]) continue;
			dist[v] = dist[u]+w;
			pq.push({dist[v], v});
		}
	}
	
	if (dist[n] == INF)
		cout << -1 << endl;
	else
		cout << dist[n] << endl;
}