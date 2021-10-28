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

void print(int maze[][20],int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<maze[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void ratInMazeTotalWays(char maze[][20],int sol[][20],int n, int m,int i,int j){
if(i==n-1 && j==m-1){
    sol[i][j]=1;
    print(sol,n,m);
    sol[i][j]=0;
    return;
}
if(maze[i][j]=='X' || i == n || j==m) return;

sol[i][j]=1;
ratInMazeTotalWays(maze,sol,n,m,i,j+1);
ratInMazeTotalWays(maze,sol,n,m,i+1,j);
sol[i][j]=0;
return;

}


void solve()
{
    int i, j, n, m;
    // cin>>n;
    // int a[n];
    // for(i=0;i<n;i++){
    //     cin>>a[i];
    // }

    char maze[20][20] ={ "0000",
                         "00X0",
                         "000X",
                         "0X00"};
    int sol[20][20] = {0};

    ratInMazeTotalWays(maze,sol,4,4,0,0);

    // int maze[20][20];
    // cin>>n>>m;
    // srand(time(NULL));

    


    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         int random =rand()%5;
    //         if(random==1){
    //             maze[i][j]=2;
    //         }
    //         else maze[i][j]=0;

    //         cout<<maze[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

   
    
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
    cin >> t;
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
