#include <iostream>
#include <algorithm>
#define MAXN 1000001
#define MAXM 2000001
using namespace std;
int n, m, pai[MAXN], peso[MAXN];
struct edge{
  int node1, node2;
  int d;
};
bool sml(edge one, edge two){
  return one.d < two.d;
}
edge mst[MAXM], edges[MAXM];
// union find functions
int find(int x){
  if(pai[x] == x){
    return x;
  }
  return pai[x] = find(pai[x]);
}
void join(int x, int y){
  x = find(x);
  y = find(y);
  if(peso[x] > peso[y]){
    pai[y] = x;
    peso[x] += peso[y];
  } else if(peso[x] < peso[y]){
    pai[x] = y;
    peso[y] += peso[x];
  } else{
    pai[y] = x;
    peso[x] += peso[y];
  }
}
int main(){
  cin >> n >> m;
  //set up the union find
  for(int i = 1; i <= n; i++){
    pai[i] = i;
    peso[i] = 1;
  }
  for(int i = 1; i <= m; i++){
    cin >> edges[i].node1 >> edges[i].node2 >> edges[i].d;
  }
  //order the edges array
  sort(edges + 1, edges + m + 1, sml);
  int sz = 0, total = 0;
  //compute the smallest edges into the minnimum spanning tree
  for(int i = 1; i <= m; i++){
    if(find(edges[i].node1) != find(edges[i].node2)){
      join(edges[i].node1, edges[i].node2);
      mst[sz++] = edges[i];
      total += edges[i].d;
    }
  }
  cout << total << '\n';
}
