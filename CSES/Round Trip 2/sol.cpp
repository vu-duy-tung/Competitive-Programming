#include<bits/stdc++.h>
#define mino "sol"

#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define DEC(i, a, b) for(int i = a; i >= b; i--)

#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e6 + 5;
const int oo = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<ll,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

bool ok = false;
int n, m;
int check[N], path[N], trace[N];
vi a[N];

void dfs(int u)
{
    path[u] = 1;
    check[u] = 1;
    for(int v : a[u])
    {
        if(ok) return;
        if(check[v])
        {
            if(path[v])
            {
                ok = true;
                vi ans;
                ans.pb(v);
                int tmp = u;
                while(tmp != v)
                {
                    ans.pb(tmp);
                    tmp = trace[tmp];
                }
                ans.pb(v);
                cout << ans.size() << endl;
                reverse(ans.begin(), ans.end());
                for(int x : ans) cout << x << ' ';
                return;
            }
        }
        else
        {
            trace[v] = u;
            dfs(v);
        }
    }
    path[u] = 0;
}

int main()
{
    freopen(mino".inp", "r", stdin);
    freopen(mino".out", "w", stdout);

    cin >> n >> m;

    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
    }

    FOR(i, 1, n) if(!ok && !check[i]) dfs(i);

    if(!ok) cout << "IMPOSSIBLE";


}
