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

bool column[10];
bool d2[10];
bool d1[10];



bool isSafe2(int board[][10],int n,int i, int j){
    if(column[j] || d1[j-i+n] || d2[i+j]) return false;
    return true;
}

bool isSafe(int board[][10],int n,int i,int j){

    // cout<<"yipee";
    for(int temp=0;temp<i;temp++){
        if(board[temp][j])
            return false;
    }
    for(int temp=0;temp<j;temp++){
        if(board[i][temp])
            return false;
    }
    int x=i,y=j;
    while(x>=0 && y>=0){
        if(board[x][y]) return false;
        x--; 
        y--;
    }
    x=i,y=j;
    while(x>=0 && y<n){
        if(board[x][y]) return false;
        x--;
        y++;
    }

    return true;

}

void print(int board[][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool nQueen(int board[][10],int n,int i){
    // cout<<"hello";
    if(i==n){
        print(board,n);
        cout<<endl;
        return false;
    }
    for(int j=0;j<n;j++){
        // cout<<i<<" "<<j<<endl;
        if(isSafe2(board,n,i,j)){
        //  cout<<i<<" "<<j<<endl;
         board[i][j]=1;
         column[j]=true;
         d1[j-i + n]=true;
         d2[j+i]=true; 
         bool possibleSol = nQueen(board,n,i+1);
         if(possibleSol) return true;
         board[i][j]=0;
         column[j]=false;
         d1[j-i + n]=false;
         d2[j+i]=false; 
        }
    }
   
   return false;

}

void solve()
{
    int i, j, n, m;
    // cin>>n;
    // int a[n];
    // for(i=0;i<n;i++){
    //     cin>>a[i];
    // }

    int board[10][10];

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            board[i][j]=0;
        }
    }

    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //        cout<< board[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"hello";s

    for(int i=0;i<10;i++){
    column[i]=false;
    d2[i]=false;
    d1[i]=false;
}

    bool ans = nQueen(board,4,0);
    cout<<endl;

    
   
    
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
