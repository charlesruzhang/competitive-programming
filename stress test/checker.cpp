#include <bits/stdc++.h>
using namespace std;

static bool is_valid_perm(const vector<int>& a, int n){
  if ((int)a.size()!=n) return false;
  vector<int> seen(n+1,0);
  for(int x:a){ if(x<1||x>n||seen[x]) return false; seen[x]=1; }
  return true;
}

int main(int argc, char** argv){
  if(argc<4){ cerr<<"usage: checker IN FAST BRUTE\n"; return 2; }
  ifstream in(argv[1]), fa(argv[2]), br(argv[3]);
  if(!in||!fa||!br){ cerr<<"file open error\n"; return 2; }

  int n; in>>n;
  vector<pair<int,int>> E(n-1);
  for(int i=0;i<n-1;++i) in>>E[i].first>>E[i].second;

  string sF,sB;
  if(!(fa>>sF) || !(br>>sB)) return 1;
  if(sF!="YES" || sB!="YES") return 1;

  vector<int> AF(n), AB(n);
  for(int i=0;i<n;++i) if(!(fa>>AF[i])) return 1;
  for(int i=0;i<n;++i) if(!(br>>AB[i])) return 1;

  if(!is_valid_perm(AF,n)) return 1;
  if(!is_valid_perm(AB,n)) return 1;

  return 0; // accept any valid output
}
