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

int power(int n,int p){
   if(p==1) return n;
   if(p%2==0){
       return power(n,p/2)*power(n,p/2);
   }
   else return n*power(n,p-1);
}   

string arr[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printWords(int n){
    if(n/10 == 0) {
        cout<<arr[n]<<" ";
        return;
    }
    printWords(n/10);
    cout<<arr[n%10]<<" ";
}

int product(int a, int b)  //function definition
{
    if(a<b)
    {
        return product(b,a);
    }
    else if(b!=0){
            return (a+product(a,b-1));
    }
    else{
        return 0;
    }
}

int convertToInt(string s){
    if(s.length()==1){
        return s[0]-'0';
    }
    int value =convertToInt(s.substr(1));
    return (s[0]-'0') * pow(10,s.length()-1) +  value;

}

int returnProduct(int x,int y){
    if(x==0 || y==0) return 0;
    // if(x>y) return returnProduct(y,x);
    return y + returnProduct(x-1,y);
}


int tileTotalWays(int n){
    // if(n==0) return 1;
    if(n<4) return 1;
    return tileTotalWays(n-1) + tileTotalWays(n-4);

}

void solve()
{
    int i, j, n, m;
    cin>>n;
    // int a[n];
    // for(i=0;i<n;i++){
    //     cin>>a[i];
    // }
    // cout<<power(n,j)<<endl;
    // printWords(n);
    // string s;
    // cin>>s;
    // cout<<convertToInt(s)+69;
    // cout<<returnProduct(n,j);
    cout<<tileTotalWays(n);

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
