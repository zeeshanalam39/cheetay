#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void candyStore(int candies[4], int N, int K, int len, int *minPrice, int *maxPrice){
  if(N < 1 || N > 100000 || K < 0 || K > N-1) return;
  *minPrice = 0;
  *maxPrice = 0;
  vector <int> boughtCandies;

  int min, max;
  int candiesLeft;
  int prevMin, prevMax;
  bool findingMinPrice, findingMaxPrice;
  
  for(int count=0; count<2; count++) {
    if(count == 0) {
      findingMinPrice = true;
      findingMaxPrice = false;
    }
    else if(count == 1) {
      findingMaxPrice = true;
      findingMinPrice = false;
    }

    candiesLeft = len;
    prevMin = 0;
    prevMax = 0;

    while(candiesLeft > 0) {
    // cout<<"size: "<<boughtCandies.size()<<endl;
    min = candies[0];
    max = candies[0]; // 3
    for(int i=1; i<len; i++) {
      auto cand = find(boughtCandies.begin(), boughtCandies.end(), candies[i]);
      if(cand != boughtCandies.end()) {
        ;
      } else if(findingMinPrice) {
            if(candiesLeft == len) {
                min = min < candies[i] ? min : candies[i];
            } else {
              if(candies[i] > prevMin){
                 min = min < candies[i] ? min : candies[i];
              }
            }
      } else if(findingMaxPrice) {   // {3, 2, 1, 4}
        // cout<<"PrevMax: "<<prevMax<<endl;
          if(candiesLeft == len) {
              max = max > candies[i] ? max : candies[i];
          } else {
              if(candies[i] < prevMax){
                  max = max > candies[i] ? max : candies[i];
          }
        }
      }
  }
  if(findingMinPrice){
      prevMin = min;
      *minPrice = *minPrice + min;
      // cout<<"Ptr: "<<*minPrice<<endl;
      boughtCandies.push_back(min);
  } else if(findingMaxPrice){
      prevMax = max;
      *maxPrice = *maxPrice + max;
      // cout<<"Ptr: "<<*minPrice<<endl;
      boughtCandies.push_back(max);
  }
  candiesLeft--;
  
  if(candiesLeft > 0) {
    for(int i=0; i<K; i++) {
    if(findingMinPrice) max = candies[0];
    else if(findingMaxPrice) min = candies[0];
    for(int j=0; j<len; j++) {
      auto cand = find(boughtCandies.begin(), boughtCandies.end(), candies[j]);
      if(cand != boughtCandies.end()) {
          ;
      } else {
          if(!findingMinPrice) {
              min = min < candies[j] ? min : candies[j];  
          } else if(!findingMaxPrice) {
              max = max > candies[j] ? max : candies[j]; 
          }      
      }
    }
    if(!findingMinPrice) boughtCandies.push_back(min);
    if (!findingMaxPrice) boughtCandies.push_back(max); 
    candiesLeft--;
  }
  }
  }
    boughtCandies.clear();
  }
}

int main() {
  int candies[] = {3, 2, 1, 4};   // {3, 2, 1, 4, 5, 7, 6}
  int N = 4;
  int K = 2;
  // 3 7

  // int candies[] = {3, 2, 1, 4, 5};   // {3, 2, 1, 4, 5, 7, 6}
  // int N = 5;
  // int K = 4;
  // 1 5
  int minPrice, maxPrice;
  int size = sizeof(candies)/sizeof(candies[0]);

  candyStore(candies, N, K, size, &minPrice, &maxPrice);

  cout<<minPrice<<" "<<maxPrice<<endl;
  return 0;
}
