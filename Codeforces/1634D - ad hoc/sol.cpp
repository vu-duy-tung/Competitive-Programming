#include<bits/stdc++.h>
#define mino "sol"

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b, step) for(int i = a; i <= b; i += step)
#define DEC(i, a, b) for(int i = a; i >= b; i--)

#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 1;

int T, n;
int arr[N];

int ask(int a, int b, int c)
{
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    int ans; cin >> ans;
    return ans;
}

int main()
{
    freopen(mino".inp","r",stdin);
    freopen(mino".out","w",stdout);

    turbo

    cin >> T;

    while(T--)
    {
        cin >> n;

        int a = 1, b = 2, c = 3, d = 4, tmp, check = 0;
        while(true)
        {
            pair<int,string> x[6];
            x[1] = mp(ask(a, b, c), 'd');
            x[2] = mp(ask(a, c, d), 'b');
            x[3] = mp(ask(a, b, d), 'c');
            x[4] = mp(ask(b, c, d), 'a');
            sort(x+1, x+5);

            string S = x[4].se + x[3].se;

            if(S == "ab" || S == "ba") tmp = a, a = c, b = d;
            else if(S == "ac" || S == "ca") tmp = a, a = d;
            else if(S == "ad" || S == "da") tmp = a, a = c;
            else if(S == "bc" || S == "cb") tmp = b, b = d;
            else if(S == "bd" || S == "db") tmp = b, b = c;
            else tmp = c;

            if(check) break;
            if(d == n) break;

            c += 2;
            d += 2;

            if(d == n+1)
            {
                check = 1;
                d = tmp;
            }
        }

        cout << "! " << a << ' ' << b << endl;
    }
}
