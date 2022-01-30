#include<bits/stdc++.h>
#define mino "sol"

#define ll long long
#define fi first
#define se second
#define pb push_back

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b, step) for(int i = a; i <= b; i += step)
#define DEC(i, a, b) for(int i = a; i >= b; i--)

#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 1;

int n, m, q;
int a[N], b[N];
int parent[2*N], degree[2*N], Max[2*N];
ll Sum[2*N], ans;
pii k[N], c[2*N];

struct edge{
    int pos, dis;
};
edge E[2*N];

void init()
{
    cin >> n >> m >> q;

    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];
    FOR(i, 1, q)
    {
        cin >> k[i].fi;
        k[i].se = i;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    sort(k+1,k+q+1);
}

bool cmp(edge A, edge B)
{
    return A.dis < B.dis;
}

void Merge()
{
    FOR(i, 1, n) c[i].fi = a[i], c[i].se = 1;
    FOR(i, 1, m) c[i+n].fi = b[i];
    sort(c+1,c+m+n+1);

    FOR(i, 1, m + n - 1) E[i] = {i, c[i+1].fi - c[i].fi};
    sort(E+1,E+m+n,cmp);
}

int root(int u)
{
    if(parent[u] != u) parent[u] = root(parent[u]);
    return parent[u];
}

void hop(int u, int v)
{
    u = root(u);
    v = root(v);
    if(u == v) return;
    if(degree[u] < degree[v]) swap(u, v);
    parent[v] = u;
    ans -= Sum[Max[v]-degree[v]+1] - Sum[Max[v]+1];
    ans -= Sum[Max[u]-degree[u]+1] - Sum[Max[u]+1];
    degree[u] += degree[v];
    Max[u] = max(Max[u], Max[v]);
    ans += Sum[Max[u]-degree[u]+1] - Sum[Max[u]+1];
}

void Solve()
{
    /// GENERATE GRAPH
    FOR(i, 1, m+n)
    {
        parent[i] = i;
        Max[i] = i;
        if(c[i].se == 1)
        {
            ans += c[i].fi;
            degree[i] = 1;
        }
    }

    DEC(i, m+n, 1)
    {
        Sum[i] = Sum[i+1] + c[i].fi;
    }

    int j = 1;
    long long Output[q+5];
    FOR(i, 1, q)
    {
        while(j <= m+n-1 && E[j].dis <= k[i].fi)
        {
            hop(E[j].pos, E[j].pos + 1);
            j++;
        }
        Output[k[i].se] = ans;
    }

    FOR(i, 1, q) cout << Output[i] << ' ';
}

int main()
{
    freopen(mino".inp","r",stdin);
    freopen(mino".out","w",stdout);
    turbo
    init();
    Merge();
    Solve();
}
