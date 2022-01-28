#include<bits/stdc++.h>
#define mino "sol"

#define ll long long
#define fi first
#define se second
#define pb push_back

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b, step) for(int i = a; i <= b; i += step)
#define DEC(i, a, b) for(int i = a; i <= b; i--)

#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

typedef vector<int> vi;
typedef pair<long long,long long> pii;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 1;

int n, t;
ll a[N];

bool check(ll time)
{
    ll product = 0;
    FOR(i, 1, n)
    {
        product += time / a[i];
        if(product >= t) return true;
    }
    return false;
}

int main()
{
//    freopen(mino".inp","r",stdin);
//    freopen(mino".out","w",stdout);

    turbo

    cin >> n >> t;

    FOR(i, 1, n) cin >> a[i];

    ll l = 0, r = 1ll*1e18, ans = -1;
    while(l <= r)
    {
        ll mid = (l + r)/2;
        if(check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans;
}
