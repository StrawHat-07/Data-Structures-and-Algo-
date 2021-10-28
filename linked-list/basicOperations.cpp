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
    node * next;

    node(){}

    node(int value,node * next){
        this->value = value;
        this->next = next;
    }
};

class linkedList{
    node* head;
    node* tail;

    public:
    linkedList(){
        head = NULL;
        tail = NULL;
    }

};

void insertAtHead(node* &head,int data){
    node* n = new ::node(data,head);
    head = n;
}

int length(node* head){
    int length =0;
    while(head!=NULL){
        head = head->next;
        length++;
    }
    return length;
}

void insertAtTail(node* &head, int data){
    if(head == NULL) {
        insertAtHead(head,data);
        return;
    }
    node* tail = head;
    while(tail->next!=NULL)
        tail=tail->next;
    node* n = new node(data,NULL);
    tail->next = n;
}

void insertInMiddle(node* &head,int data,int p){
    if(head==NULL||p==0) insertAtHead(head,data);
    else if(p>length(head)) insertAtTail(head,data);
    else{
        node* middle = head;
        while(p-1){
            middle=middle->next;
            p--;
        }
        node* n = new node(data,NULL);
        n->next = middle->next;
        middle->next=n;
    }
}

int searchRecursive(node* head,int data){
    if(head==NULL) 
        return -1;
    if(head->value == data) 
        return 0;
    int index = searchRecursive(head->next,data);
    return  index>=0 ? 1+index : index;
}

int search(node* head, int data){
    int index=0;
    while(head!=NULL){
        if(head->value == data)
            break;
        index++;
        head=head->next;
    }
    if(head==NULL) return -1;
    return index;
}

void deleteAtHead(node* &head){
    node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd(node* head){
    node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    node* del = temp->next;
    temp->next = NULL;
    delete del;
}

void deleteInMiddle(node* &head, int p){
    if(p==0){
        deleteAtHead(head);
        return;
    } 
    if(p>length(head)){
        deleteAtEnd(head);
        return;
    }
    int jump=0;
    node* temp = head;
    while(jump<p-1){
        temp = temp->next;
        jump++;
    }
    node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

void buildList(node* &head){
    int data;
    cin>>data;
    while(data!=-1){
        insertAtTail(head,data);
        cin>>data;
    }
}

node* kReverse(node* head,int k){
    if(head==NULL || head->next==NULL)
        return head;

    node* prev = NULL;
    node* current =head;
    node* next = head;

    int i=1;
    while(i<=k && current!=NULL){
        next = current->next;
        current->next = prev;
        prev =current;
        current=next;
        i++;
    }
    head->next = kReverse(current,k);

    return prev;
}

void reverseLinkedList(node* &head){
    node* next=head;
    node* current=head;
    node* prev=NULL;

    while(next!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

node* reverseRecursive(node* &head){
    if(head->next == NULL || head==NULL){
        return head;
    }
    node* temp = reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return temp;
}

node* findMid(node* head){
    node* mid = head;
    while(head->next!=NULL && head->next->next!=NULL){
        head=head->next->next;
        mid=mid->next; 
    }
    return mid;
}

node* findKthFromLast(node* head,int k){
    if(k>length(head))
         return NULL;
    node* slow = head;
    node* fast = head;
    k--;
    while(k--) fast= fast->next;
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

node* merge(node* head1, node* head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    node* head ;
    node* iterator;

    if(head1->value<=head2->value){
        head = head1;
        iterator = head1;
        head1 = head1->next;
    }
    else{
        head=head2;
        iterator=head2;
        head2=head2->next;
    }
    
    while(head1!=NULL && head2!=NULL){
        if(head1->value <= head2->value){
            iterator->next = head1;
            head1 = head1->next;
            iterator = iterator->next;
            }
        else {
            iterator->next = head2;
            head2=head2->next;
            iterator = iterator->next;
        }

    }

    while(head1!=NULL){
        iterator->next = head1;
        head1 = head1->next;
        iterator=iterator->next;
    }

    while(head2!=NULL){
        iterator->next = head2;
        head2 = head2->next;
        iterator=iterator->next;
    }

    return head;
   
}

node* mergeRecursive(node* head1, node* head2){
    if(head1== NULL) return head2;
    if(head2== NULL) return head1;
    node* c = (head1->value<=head2->value)?head1:head2;
    node* smallHead = (head1->value<=head2->value)?mergeRecursive(head1->next,head2):mergeRecursive(head1,head2->next);
    c->next = smallHead;
    return c;
}

void print(node* head){
    while(head!=NULL){
        cout<<head->value<<" ";
        head=head->next;
    }
}

istream& operator>>(istream &is, node* &head){
    buildList(head);
    return is;
}

ostream& operator<<(ostream &os, node* head){
    print(head);
    return os;
}

node* mergeSort(node* head){
    if(head==NULL || head->next == NULL) return head;
    node* mid = findMid(head);
    node* head1 = head;
    node* head2 = mid->next;
    mid->next = NULL;

    cout<<mid->value<<endl;

    cout<<head1<<endl<<head2<<endl;

    head1 = mergeSort(head1);
    head2 = mergeSort(head2);

    return mergeRecursive(head1,head2);
}

bool detectCycle(node* head){
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) {
            return true;
        }
    }
    return false;
}


void solve()
{
   node *head =NULL;

   int n= 10;
   for(int i=0;i<n;i++){
       insertAtHead(head,n-i);
   }

   print(head);
   cout<<endl;
   head = kReverse(head,4);
   print(head);
//     cout<<endl;
//    insertInMiddle(head,10,3);

//     node* a = NULL;
//    insertAtTail(head,-1);

//    cout<<"Index : "<<searchRecursive(head,9)<<endl;
//    cout<<"Index : "<<search(head,-2)<<endl;

//    deleteAtHead(head);
//    print(head);
//    cout<<endl;
//    deleteAtEnd(head);
//    print(head);
//    cout<<endl;
//    deleteInMiddle(head,2);

//    print(head);
//    cout<<endl;


//     node* head2=NULL;
//     node* head1=NULL;
//     cin>>head1;
//     cout<<head1<<endl;
//     // cin>>head2;
//     // cout<<head2<<endl;
//     // head1->next = head2;

    // node* merged = merge(head1,head2);
    // node* merged = mergeRecursive(head1,head2);
    // node* merged = mergeSort(head1);
    // cout<<merged;
    // reverseLinkedList(head2);
    // head2= reverseRecursive(head2);
    // cout<<head2<<endl;

    // node* mid = findMid(head2);
    // cout<<mid->value;
    // node* kth = findKthFromLast(head,7);
    // cout<<endl<<kth->value;
//    buildList(head);
//    print(head);

//    for(node* n = head;n!=NULL;n=n->next){
//        cout<<n->value<<"->";
//    }

   
    
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
