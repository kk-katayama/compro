#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int fir=0,sec=0;
  rep(i,n){
    if(fir<a[i]){
      sec = fir;
      fir = a[i];
    }
    else if(sec<a[i]){
      sec = a[i];
    }
  }
  rep(i,n){
    if(a[i]==fir) cout << sec << "\n";
    else cout << fir << "\n";
  }
  
  return 0;
}
