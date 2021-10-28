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


class Node{
    public:
    string name;
    list<string> nbrs;

    Node(string s){
        this->name =s;

    }
};
//Weighted Graph

class weightedGraph{
    int V;
    list<pair<int,int>> *l;

public:
    weightedGraph(int v){
        this->V=v;
        l= new list<pair<int,int>>[V];
    }


    void addEdge(int u, int v,int w, bool undir=true){
        l[u].push_back({v,w});
        if(undir){
            l[v].push_back({u,w});
        }
    }

};
class Graph2{

    unordered_map<string,Node*> m;
    public:
    Graph2(vector<string> cities){
        for(auto city:cities){
            m[city] = new Node(city);
        }
    }

    void addEdge(string a, string b, bool undir=false){
        m[a]->nbrs.push_back(b);
        if(undir){
            m[b]->nbrs.push_back(a);
        }
    }

    void printAdjencyList(){
        for(auto i: m){
            cout<<"For "<<i.first<<" : ";
            for(auto j:m[i.first]->nbrs){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    //
};

class graph{
    int V;
    list<int> *l;

    public:

    graph(int v){
        V=v;
        l= new list<int>[V];
    }
 
    void addEdge(int i,int j,bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printAdjencyList(){
        for(int i=0;i<V;i++){
            cout<<"For "<<i<<" : ";
            for(int j:l[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(int source){
        queue<int> q;
        bool visited[V]={0};

        
        q.push(source);
        visited[source]=true;

        while(!q.empty()){
            int temp = q.front();
            for(auto i : l[temp]){
                if(visited[i]) continue;
                q.push(i);
                visited[i]=true;
            }
            q.pop();
            cout<<temp<<" ";
        }
        
    }

    int* findShortestPath(int source){
        
        int shortestPaths[V];
        int parents[V];
        bool visited[V] = {0};

        queue<int> q;

        q.push(source);
        visited[source]=true;
        parents[source]=-1;
        shortestPaths[source]=0;

        int distance =0;

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for(auto i:l[temp]){
                q.push(i);
                parents[i] = temp;
                shortestPaths[i] = shortestPaths[temp] + 1;
                visited[i]=true;
            }

        }

        

    }

};


void solve()
{
    int i, j, n, m;
    // cin>>n;
    // int a[n];
    // for(i=0;i<n;i++){
    //     cin>>a[i];
    // }



    graph g(6);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(4,2);
    g.printAdjencyList();
    g.bfs(0);
    // g.addEdge(0,6);


    // g.addEdge(0,1);
    // g.addEdge(0,4);
    // g.addEdge(2,1);
    // g.addEdge(3,4);
    // g.addEdge(4,5);
    // g.addEdge(2,3);
    // g.addEdge(3,5);


    vector<string> cities = {"Delhi","Paris","New York","Mumbai","Lords"};

    Graph2 g2 = Graph2(cities);
    g2.addEdge("Delhi","Mumbai");
    g2.addEdge("New York","Mumbai");
    g2.addEdge("Delhi","Paris");
    g2.addEdge("Paris","New York");


//    g2.printAdjencyList();
    
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
