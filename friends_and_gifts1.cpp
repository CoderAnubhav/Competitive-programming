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
#define q queue<long long>
#define pqd priority_queue <long long>
#define pqi priority_queue <long long, vector<long long>, greater<long long>>
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

typedef long long ll;
typedef long double ld;
using namespace std;
using namespace std::chrono;
int main(){
    FASTER;
        ll n;
        cin>>n;
        bool vis[n+1];
        memset(vis,0,sizeof vis);
        vll nr,ng;
        ll ans[n+1];
        repe(i,1,n)
        {
            cin>>ans[i];
            if(ans[i]==0)
            {
                ng.push_back(i);                         // not given
            }
            else vis[ans[i]]=true;                       //received
        }
       //rep(i,0,ng.size())cout<<ng[i]<<" ";
       // cout<<"\n";
        repe(i,1,n)
            if(!vis[i])
                nr.push_back(i);                        //not received

       // rep(i,0,nr.size())cout<<nr[i]<<" ";
       // cout<<"\n";
        rep(i,0,ng.size())
            ans[ng[i]]=nr[i];

        rep(i,0,ng.size()-1)
        {
            if(ans[ng[i]]==ng[i])
                swap(ans[ng[i]],ans[ng[i+1]]);
        }
        if(ans[ng[ng.size()-1]]==ng[ng.size()-1])swap(ans[ng[0]],ans[ng[ng.size()-1]]);
        repe(i,1,n)cout<<ans[i]<<" ";
        cout<<"\n";
    return 0;
}
