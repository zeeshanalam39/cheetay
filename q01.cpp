#include<iostream>
using namespace std;

int spirallyTraverse(int matrix[4][4], int R, int C){
  int spiralArray[16] = {0};
  for(int i=0; i<R; i++) {
    for(int j=)
  }
  return spiralArray;
}

int main() {
  int R = 4;
  int C = 4;
  int matrix[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15,16}
  };
  // 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
  spirallyTraverse(matrix, R, C);
  return 0;
}
