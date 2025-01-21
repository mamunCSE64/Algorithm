#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#define ll long long int
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define gcd __gcd
#define int_string to_string
#define string_int stoi
#define mn(v) *min_element(v.begin(), v.end())
#define mx(v) *max_element(v.begin(), v.end())
#define index_character s.find('character')
#define countxchar count(s.begin(), s.end(), 'x')
#define index_ofX_vector find(v.begin(), v.end(), x) - v.begin()
#define point cout << fixed << setprecision(10)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define n1 cout << "-1" << endl
#define ok cout << "ok" nl
#define sorted is_sorted(v.begin(), v.end())
#define nl << endl
#define sp << " "
#define mp make_pair
#define fi first
#define se second
#define inf LLONG_MAX
#define mod %1000000007
// ordered_set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// bitsize-> ll size=log2(n)+1 (last set bit=size-1;/ /Last bit->__lg(value); )
// first bit-> name._Find_First()
// next bit after x-> name._Find_next()
// freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
// BesidesDuplicateCharacterEraseInString s.erase(unique(s.begin(), s.end()), s.end());
// Upper/lower-> transform(s.begin(), s.end(), s.begin(), ::toupper/tolower);

ll i, j, k, n, m;
const ll N = 2e7+5;
const ll e=1e9;
const double pi=acos(-1);
float d;
class st{
    public:
    int a,b,ind;
};
bool cmp(st aa,st bb){
    int a1,a2;
    a1=ceil(aa.a/(d));
    a2=ceil(bb.a/(d));
    if(a1==a2){
        return (aa.b<bb.b);
    }
    return (aa.a<bb.a);
}

//
// Don't get stuck on a single approach for long, think of multiple ways
// You will destroy your dream if you stay in your comfort zone
// **********************|| Main Code ||********************************
//
// vector<int> parent(10);
// int find(int node){
//     int p=parent[node];
//     if(node!=p){
//         parent[node]=find(parent[node]);
//     }
//     return parent[node];
// }
//  g++ test.cpp -o a && ./a
//  g++ -o a test.cpp && ./a
//  g++ -o a test.cpp && a.e


 
int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    // point;
    ll test = 1; 
    // cin >> test;    
    again: 
    while (test--)
    {   
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<st> v(q);
        d=sqrt(n);
        for(i=0;i<q;i++){
            cin>>v[i].a>>v[i].b;            // frequency count within a range
            v[i].ind=i;                     // Problem link: https://codeforces.com/contest/220/problem/B
        }                                                            
        sort(v.begin(),v.end(),cmp);
        vector<int> ans(q),freq(n+5);
        int count=0;
        int i=j=0;
        if(a[0]<=n){
            freq[a[0]]++;
            if(freq[a[0]]==a[0]) count++;
        }
        for(auto x: v){
            x.a--,x.b--;
            while(i>x.a){
                i--;
                if(a[i]<=n and freq[a[i]]==a[i]) count--;
                if(a[i]<=n) freq[a[i]]++;
                if(a[i]<=n and freq[a[i]]==a[i]) count++;
            }
            while(i<x.a){
                if(a[i]<=n and freq[a[i]]==a[i]) count--;
                if(a[i]<=n and freq[a[i]]==a[i]+1) count++;
                if(a[i]<=n) freq[a[i]]--;
                i++;
            }
            while(j>x.b){
                if(a[j]<=n and freq[a[j]]==a[j]) count--;
                if(a[j]<=n and freq[a[j]]==a[j]+1) count++;
                if(a[j]<=n) freq[a[j]]--;
                j--;
            }
            while(j<x.b){
                j++;
                if(a[j]<=n and freq[a[j]]==a[j]) count--;
                if(a[j]<=n) freq[a[j]]++;
                if(a[j]<=n and freq[a[j]]==a[j]) count++;
            }
            ans[x.ind]=count;
        }
        for(auto x: ans){
            cout << x nl;
        }
        cout nl;
    }
}
