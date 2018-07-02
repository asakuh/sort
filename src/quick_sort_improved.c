#include <stdio.h>

//フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
    int i,j,l,r,pivot;
    if(n<=1) return;
    pivot = A[0];
    l=0;
    r=n;
  for(i = j =1; i<r; i++){
    if(A[i] < pivot){
      int x = A[l];
      A[l] = A[i];
      A[i] = x;
      l++;
      j++;
    }
   else if(A[i] > pivot){
        int y = A[r-1];
        A[r-1] = A[i];
        A[i] = y;
        r--;
        i--;
    }
    else if(A[i]==pivot){
    	j++;
    }
  }
  
  quick_sort(A,l);
  quick_sort(A+r,n-r);
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
