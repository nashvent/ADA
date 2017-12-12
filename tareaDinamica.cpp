#include <bits/stdc++.h>
using namespace std;
int productSum(int*A,int size){
  if (size==0)
    return 0;
  int *f=new int[size+1];
  f[0]=0;
  f[1]=A[0];
  for(int j=1;j<size;j++){
    f[j+1]=max(f[j]+A[j],f[j-1]+(A[j]*A[j-1]));
  }
  return f[size];
}


int main(){
  int A[7]={1,4,3,2,3,4,2};
  cout<<productSum(A,7)<<endl;
  int B[10]={2,2,1,3,2,1,2,2,1,2};
  cout<<productSum(B,10)<<endl;
  return 0;
}
