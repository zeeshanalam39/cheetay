#include<iostream>
using namespace std;

int activitySelection(int start[2], int end[2], int N){
  if(N <=1 || N >=210) return 0;

  int total = 1;
  int s, e = 0;
  for(s=1; s<N; s++) {
    if(start[s] >= 1 && start[s] <=109 && end[s] >= 1 && end[s] <=109) {
       if(start[s] >= end[e]) {
        // cout<<start[s]<<" "<<end[e]<<endl;
        total++;
        // s = e;
        e = s;
      }
    }
  }
  return total;
}

int main() {
  // int start[] = {2, 1};
  // int end[] = {2, 3};
  // int N = 2;
  int start[] = {1, 3, 2, 5};
  int end[] = {2, 4, 3, 6};
  int N = 4;
  cout<<"Total activities: "<<activitySelection(start, end, N)<<endl;
  return 0;
}
