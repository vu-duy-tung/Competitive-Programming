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

int n;
int a[N];

int main()
{
//    freopen(mino".inp","r",stdin);
//    freopen(mino".out","w",stdout);

    turbo

    cin >> n;

    FOR(i, 1, n) cin >> a[i];

    sort(a+1,a+n+1);

    ll sum = 0;
    FOR(i, 1, n-1) sum += a[i];

    if( sum >= a[n] ) cout << sum + a[n];
    else cout << 2ll * a[n];
}
