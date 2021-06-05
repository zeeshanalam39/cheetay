#include<iostream>
using namespace std;

int countMin(string str) {
  int len = str.length();
  if(len <=1 || len >=109) return 0;
  if(len == 2) {
    return str[0] == str[1] ? 0 : 1;
  } else {
    return len-1;
  }
}

int main() {
  cout<<countMin("aab");
  return 0;
}
