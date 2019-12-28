/********************AUTHOR:THE CODER***********************/
/*                                                         */
/*                                                         */
/************************************************************/
#include<bits/stdc++.h>
#define MOD 1000000007
#define INF LLONG_MAX
#define f first
#define s second
#define LB lower_bound
#define UB upper_bound
#define vc vector
#define vll vector<long long>
#define pi pair<long long,long long>
#define pii pair<long long,pi>
#define pb push_back
#define all(v) v.begin(),v.end()
#define T ll test;cin>>test; while(test--)
#define rep(i,a,n) for(ll i=a;i<(long long)n;++i)
#define repe(i,a,n) for(ll i=a;i<=(long long)n;++i)
#define repr(i,n,a) for(ll i=n;i>(long long)a;--i)
#define repre(i,n,a) for(ll i=n;i>=(long long)a;--i)
#define endl '\n'
#define MAX 100005
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define start_clock auto start = high_resolution_clock::now()
#define stop_clock auto stop = high_resolution_clock::now()
#define clock_duration auto duration = duration_cast<microseconds>(stop - start)
#define time_taken cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
#define N 3010
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace std::chrono;
ll n,m;
map<pii,bool>mp;                                                        //for checking the triplet
vc<ll>adj[N+1];
ll dp[N][N];
pi p[N][N];
void s_path(pi s)
{
    queue<pi>q;                                                            // For BFS containing a pair (predecessor and present element)
    q.push(s);
    while(!q.empty())                                                      //BFS
    {
        pi idx=q.front();
        ll u=idx.f;
        ll v=idx.s;
        q.pop();
        for(auto w:adj[v])
        {
            if(mp.find({u,{v,w}})==mp.end()&&dp[v][w]==INF)
            {
                q.push({v,w});
                dp[v][w]=dp[u][v]+1;                                      //storing the distance from v to w
                p[v][w]={u,v};                                            //storing the parents of v,w i.e,u
            }
        }
    }
    ll wt=INF,last_i;
    for(ll i=1;i<=n;i++)
    {
        if(wt>dp[i][n])
        {
            wt=dp[i][n];
            last_i=i;
        }
    }
    if(wt==INF)
    {
        cout<<"-1"<<"\n";
        return;
    }
    stack<ll>ans;
    ans.push(n);
    ans.push(last_i);
    ll m=n,i=last_i;
    while(i!=1)
    {
        pi par=p[i][m];
        ans.push(par.f);
        m=i;
        i=par.f;
    }
    cout<<wt<<"\n";
    for(ll i=1;!ans.empty();i++,ans.pop())cout<<ans.top()<<" ";
    cout<<"\n";
}
int main(){
    FASTER;
        ll k;
        cin>>n>>m>>k;
        memset(dp,0,sizeof dp);
        repe(i,1,n)
            repe(j,1,n)p[i][j]={0,0},dp[i][j]=INF;

        rep(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        rep(i,0,k)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            mp[{x,{y,z}}]=1;
        }
        s_path({0,1});
}

