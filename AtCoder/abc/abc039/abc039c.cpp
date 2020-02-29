#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;cin >> s;
  if(s.substr(0,4)=="WBWW"){
    if(s.substr(4,6)=="BWBWBW") cout << "Re" << "\n";
    else cout << "La" << "\n";
  }
  else if(s.substr(0,6)=="WBWBWW"){
    if(s.substr(6,6)=="BWBWBW") cout << "Do" << "\n";
    else cout << "So" << "\n";
  }
  else if(s.substr(0,6)=="WWBWBW"){
    if(s[6]=='B') cout << "Mi" << "\n";
    else cout << "Si" << "\n";
  }
  else cout << "Fa" << "\n";

  return 0;
}
