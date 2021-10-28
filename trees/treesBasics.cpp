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

class node{
    public:
    int value;
    node* left;
    node* right;

    node(int data){
       left=NULL;
       right= NULL;
       value= data;
    }
};

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;

}

void preOrder(node* root){

    if(root==NULL){
        return;
    }
    cout<<root->value<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void levelOrder(node* root){
    if(root==NULL)
        return;
    queue<node* > q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL)
            {
                cout<<endl;
               if(!q.empty())
                 q.push(NULL);
                continue;
            }
        cout<<temp->value<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);

    }
}

node* buildTreeLevelWise(){
    int d1,d2;
    cin>>d1;
    node* root= new node(d1);

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cin>>d1>>d2;

        if(d1!=-1){
            temp->left = new node(d1);
            q.push(temp->left);
        }

        if(d2!=-1){
            temp->right = new node(d2);
            q.push(temp->right);
        }
    }

    return root;

}

int height(node* root){
    if(root==NULL) return 0;

    return max(height(root->left),height(root->right)) + 1;
}

int diameter(node* root){
    if(root==NULL)
        return 0;

    return max(height(root->left) + height(root->right),max(diameter(root->left),diameter(root->right)));
}


// Diameter Optimized
class HDPair{
    public:
    int height;
    int diameter;

    HDPair(){
        height=0;
        diameter=0;
    }
};

HDPair diameterOp(node* root){
    if(root==NULL)
    {
        return HDPair();
    }

    HDPair p;
    p.height = max(diameterOp(root->left).height,diameterOp(root->right).height) + 1;
    int d1=diameterOp(root->left).height + diameterOp(root->right).height;
    int d2 = max(diameterOp(root->left).diameter,diameterOp(root->right).diameter);
    p.diameter = max(d1,d2);

    return p;
}

int descendantSum(node* root){
    if(root==NULL)
        return 0;
    
    int sum = descendantSum(root->left) + descendantSum(root->right);
    int temp = root->value;
    if(root->left!=NULL || root->right!=NULL)
        root->value = sum;
    return sum + temp;
}

class sumPair{
    public:
        int includingSum;
        int excludingSum;

        sumPair(){
            includingSum=0;
            excludingSum=0;
        }
};

sumPair maxSubsetSum(node* root){
    if(root==NULL) {
        sumPair s = sumPair();
        return s;
    }

    sumPair s;
    sumPair right = maxSubsetSum(root->right);
    sumPair left = maxSubsetSum(root->left);
    s.includingSum = right.excludingSum + left.excludingSum + root->value;
    s.excludingSum = max(left.includingSum,left.excludingSum) + max(right.includingSum,right.excludingSum);
    return s;

}

void printAtDistanceK(node* root,int k){
    if(root==NULL)
        return;
    
    if(k==0) {
        cout<<root->value<<" ";
        return;
    }

    printAtDistanceK(root->left,k-1);
    printAtDistanceK(root->right,k-1);

    return;

}

vector<int> nodesAtDistanceK(node* root,node* target, int k){

    if(root==NULL) {
        return {};
    }

    
}




void solve()
{
    int i, j, m;
    // cin>>n;
    // int a[n];
    // for(i=0;i<n;i++){
    //     cin>>a[i];
    // }

  node* n = buildTree();
  preOrder(n);
  cout<<endl;
  levelOrder(n);


  node* root = buildTreeLevelWise();
  levelOrder(root);
//   cout<<diameter(root);
//   cout<<endl<<diameterOp(root).height<<" "<<diameterOp(root).diameter;
    // int sum = descendantSum(root);
    // levelOrder(root);
    sumPair ans = maxSubsetSum(root);
    cout<<max(ans.includingSum,ans.excludingSum);
    cout<<endl;
    printAtDistanceK(root,1);
  
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
