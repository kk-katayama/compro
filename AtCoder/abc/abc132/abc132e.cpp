#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
//include <utility>,<queue>
template <typename X>
class Graph{
private:
  int node;
  int edge_num;
  int edge_num2;  
  vector<vector<pair<int,X>>> edge;
  vector<vector<int>> edge2;  
  vector<X> d;//distance from start
  
  const X inf = 1e+9;//initial value

public:
  //***************Constractor****************************
  Graph(int n){
    node = n;
    edge.resize(node);
  }

  Graph(int n,int m,vector<int> a,vector<int> b,vector<X> c){
    node = n;
    edge_num = m;
    edge.resize(node);
    rep(i,edge_num){
      edge[a[i]].push_back(make_pair(b[i],c[i]));
    }
  }

  Graph(int n,int m,vector<int> a,vector<int> b){
    node = n;
    edge_num2 = m;
    edge.resize(node);
    edge2.resize(node);
    rep(i,edge_num2){
      edge2[a[i]].push_back(b[i]);
    }
  }  
  //***********************************************
  
  void add_edge(int from,int to,X cost){
    edge[from].push_back(make_pair(to,cost));
    //    edge[to].push_back(make_pair(from,cost));    
  }

  //********************dijkstra********************************  
  void dijkstra(int s){
    priority_queue<pair<X,int>,vector<pair<X,int>>,greater<pair<X,int>>> pq;
    d.assign(node,inf);
    d[s] = 0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
      pair<X,int> p = pq.top();pq.pop();
      int v = p.second;
      if(d[v]<p.first) continue;
      for(auto &w:edge[v]){
	if(d[w.first]>d[v]+w.second){
	  d[w.first] = d[v] + w.second;
	  pq.push(make_pair(d[w.first],w.first));
	}
      }
    }
  }

  void dfs(int v,int c,int s){
    if(c==3){
      add_edge(s,v,1);
      //      cout << s << ":" << v << "\n";
      return ;
    }
    for(auto w:edge2[v]){
      dfs(w,c+1,s);
    }
  }

  void solve(int s,int g){
    rep(i,node) dfs(i,0,i);
    dijkstra(s);
    if(d[g]==inf) cout << -1 << "\n";
    else cout << d[g] << "\n";
  }
  
  //*****************************************************************
  X get_inf(){ return inf;}
  X get_d(int v){ return d[v];  }

  //**************************************************
};

int main()
{
  int n,m;cin >> n >> m;
  vector<int> u(m),v(m);
  rep(i,m){    cin >> u[i] >> v[i];u[i]--;v[i]--; }
  int s,g;cin >> s >> g;
  s--;g--;
  Graph<int> gp(n,m,u,v);
  gp.solve(s,g);
  return 0;
}
