#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
vector<int> divisor(int a){
  vector<int> res;
  for(int i=1;i*i<=a;i++){
    if(a%i==0){
      res.push_back(i);
      if(i!=a/i) res.push_back(a/i);
    }
  }
  return res;
}

int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> b;
  vector<int> c(n+1,0);
  for(int i=n;i>=1;--i){
    if(a[i-1]!=c[i]){
      b.push_back(i);
      vector<int> div = divisor(i);
      rep(j,div.size()){
	c[div[j]] = (c[div[j]]+1)%2;
      }
    }
  }
  cout << (int)b.size() << "\n";
  rep(i,b.size()) cout << b[i] << " ";
  if(b.size()!=0) cout  << "\n";
  return 0;
}
