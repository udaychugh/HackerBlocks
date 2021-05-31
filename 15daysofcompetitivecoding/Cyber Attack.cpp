#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<pair<ll, pair<ll, ll> > > vlll;
vlll g;
set<pair<ll, pair<ll,ll> > > mstedges;
class UnionFind{
    private: vl p, rank;
    public:
        UnionFind(ll n){
            p.assign(n, 0); rank.assign(n, 0);
            for(int i = 0; i  < n ; i++) p[i] = i;
        }

        int findSet(int i){
            if(p[i] == i)
                return i;
            p[i] = findSet(p[i]);
            return p[i];
        }

        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j){
            if(!isSameSet(i,j)){

                int pi = findSet(i), pj = findSet(j);
                if(rank[pi] > rank[pj]) p[pj] = pi;
                else{
                    p[pi] = pj;
                    if(rank[pi] == rank[pj])    rank[pj]++;
                }

            }
        }
};

bool cmp(pair<ll, pair<ll, ll> > a, pair<ll, pair<ll, ll> > b){
    ll x = a.first;
    ll y = b.first;
    return x>=y;
}

int main(){
    ll n,m,s;
    cin>>n>>m>>s;
    if(n == 1){
        cout<<0<<" "<<0;
        return 0;
    }
    // Create EdgeList...
    for(ll i = 0 ; i < m ; i++){
        ll u,v,c;
        cin>>u>>v>>c;
        u--, v--;
        g.push_back(make_pair(c, make_pair(u,v)));
    }
    sort(g.rbegin(), g.rend());
    UnionFind UF(n);
    // Find maximum Cost MST
    
    for(int i = 0; i  < g.size() ; i++){
        pair<ll, pair<ll,ll> > front = g[i];
        if(!UF.isSameSet(front.second.first, front.second.second)){
            mstedges.insert(front);
            UF.unionSet(front.second.first, front.second.second);
        }
    }
    ll ans=0, cnt=0;
    // Block smaller edges which are not a part of the MST.
    for(int i = g.size()-1 ; i >= 0; i--){
        pair<ll, pair<ll,ll> > front = g[i];
        if(mstedges.find(front) == mstedges.end() && (s-front.first) > 0){
            ans += front.first;
            s -= front.first;
            cnt++;
        }
    }
    cout<<cnt<<" "<<ans;
    return 0;
}