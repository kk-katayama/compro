#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
vector<int> dx = {-1,-1,-1,0,0,0,1,1,1};
vector<int> dy = {-1,0,1,-1,0,1,-1,0,1};
int main()
{
  int h,w;cin >> h >> w;
  vector<vector<char>> s(h,vector<char>(w));
  rep(i,h) rep(j,w) cin >> s[i][j];

  vector<vector<char>> t(h,vector<char>(w,'#'));  
  rep(i,h) rep(j,w){
    if(s[i][j]=='.'){
      rep(k,9){
	int nx = i+dx[k];
	int ny = j+dy[k];
	if(nx>=0&&nx<h&&ny>=0&&ny<w) t[nx][ny]='.';
      }
    }
  }

  vector<vector<char>> u(h,vector<char>(w,'.'));
  rep(i,h) rep(j,w){
    if(t[i][j]=='#'){
      rep(k,9){
	int nx = i+dx[k];
	int ny = j+dy[k];
	if(nx>=0&&nx<h&&ny>=0&&ny<w) u[nx][ny]='#';
      }
    }
  }

  if(u==s){
    cout << "possible" << "\n";
    rep(i,h){
      rep(j,w) cout << t[i][j];
      cout  << "\n";
    }
  }
  else cout << "impossible" << "\n";
  return 0;
}
