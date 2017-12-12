#include <bits/stdc++.h>
using namespace std;
int op=0;

bool es_mayor(int a,int b){
  op++;
  return a>b;
}

void print(vector<int>lista){
  for(int x=0;x<lista.size();x++){
    cout<<lista[x]<<" ";
  }
  cout<<endl;
}


vector<int> merge(vector<int>L,vector<int>R){
  vector<int>res;
  while(R.size()>0 and L.size()>0){
    //if(R[0]>L[0]){
    if(es_mayor(R[0],L[0])){
      res.push_back(L[0]);
      L.erase(L.begin());
    }
    else{
      res.push_back(R[0]);
      R.erase(R.begin());
    }
  }
  if(R.size()>0)
    res.insert( res.end(), R.begin(), R.end());
  else
    res.insert( res.end(), L.begin(), L.end());
  
  return res;
}


vector<int> merge_sort(vector<int>A){
  vector<int>res;
  if(A.size()<2)
    return A;
  int m=A.size()/2;
  vector<int>L(A.begin(), A.begin() + m);
  vector<int>R(A.begin()+m,A.end());
  L=merge_sort(L);
  R=merge_sort(R);
  res=merge(L,R);
  return res;
}

vector<int>agregarEl(int tam){ //Random
  vector<int>vect(tam);
  for(int x=0;x<tam;x++){
    vect[x]=rand()%tam;
  }
  return vect;
}



int main(){
  for(int x=1000;x<=100000;x+=1000){    
    vector<int>lista=agregarEl(x);
    //clock_t begin = clock();
    merge_sort(lista);
    cout<<op<<endl;
    op=0;
      //clock_t end = clock();
    //double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //cout<<double(end - begin) / CLOCKS_PER_SEC<<endl;
  }

  return 0;
}
