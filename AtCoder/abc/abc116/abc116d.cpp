#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
bool comp(pair<ll,int> &a,pair<ll,int> &b){
  return a.first>b.first;
}
int main()
{
  int n,k;cin >> n >> k;
  vector<pair<ll,int>> p(n);
  rep(i,n){
    int t;ll d;
    cin >> t >> d;
    p[i] = {d,t};
  }

  sort(p.begin(), p.end(),comp);
  ll sum = 0;
  ll num = 0;
  map<ll,int> mp;
  vector<ll> a;
  rep(i,k){
    if(mp[p[i].second]==0) num++;
    else a.push_back(p[i].first);
    sum += p[i].first;
    mp[p[i].second]++;
  }
  vector<ll> b;
  for(int i=k;i<n;++i){
    if(mp[p[i].second]==0) b.push_back(p[i].first);
    mp[p[i].second]++;
  }

  reverse(a.begin(), a.end());
  ll res = num*num+sum;
  rep(i,min(a.size(),b.size())){
    sum -= a[i]-b[i];
    num++;
    res = max(res,num*num+sum);
  }
  cout << res << "\n";
  return 0;
}
