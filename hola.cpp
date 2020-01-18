#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int>b;
  int a;
  cin >> a;
  b.push_back(a + 3);
  cout<<b.at(0)<<endl;
  return 1;
}