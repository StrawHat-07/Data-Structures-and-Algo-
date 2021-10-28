#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

void solve()
{
    int i, k, j, n, m;
    string s;
    cin >> s;
    cin >> n;
    int arr[10];
    vector<int> keep;
    fo(i, 10)
    {
        if (s[i] == '1')
        {
            arr[i] = 1;
            // cout << i + 1 << " ";
            keep.pb(i + 1);
        }
        else
            arr[i] = 0;
    }
    if (keep.size() == 0)
    {
        cout << "NO";
        return;
    }
    sort(keep.begin(), keep.end());
    int lastPush = keep[0];
    arr[keep[0] - 1] = 0;
    ll sumEarly = keep[0];
    ll sumNow = 0;
    if (n == 1)
    {
        cout << "YES" << endl;
        cout << keep[0];
        return;
    }

    n = n - 1;
    vi ans;
    ans.pb(lastPush);
    while (n)
    {
        fo(i, keep.size())
        {
            if ((sumNow + keep[i] > sumEarly) && arr[keep[i] - 1])
            {
                // cout << keep.size() << " ";
                // cout << keep[i] << " ";
                // cout << "SumNow:" << sumNow << " SumEarly:" << sumEarly << endl;
                ll temp = sumEarly;
                sumEarly = sumNow + keep[i];
                sumNow = sumEarly;
                arr[lastPush - 1] = 1;
                lastPush = keep[i];
                ans.pb(lastPush);
                arr[lastPush - 1] = 0;
                n--;
                i = -1;

                if (n == 0)
                {
                    cout << "YES" << endl;
                    fo(k, ans.size())
                    {
                        cout << ans[k] << " ";
                    }
                    return;
                }
            }
        }
        cout << "NO";
        return;
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(int n, int m)
{
    int i, u, v;
    while (m--)
    {
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int u, int par)
{
    for (int v : g[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
    }
}
