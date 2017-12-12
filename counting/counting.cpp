#include <bits/stdc++.h>
using namespace std;

template<class T>
void print(vector<T>lista){
  for(int x=0;x<lista.size();x++){
    cout<<lista[x]<<" ";
  }
  cout<<endl;
}


vector<int> counting_sort(vector<int> A,int k){
  vector<int>result;
  vector<int>m_A(k+1,0);
  for(int x=0;x<A.size();x++){
    m_A[A[x]]++;
  }
  
  for(int x=0;x<m_A.size();x++){
    for(int y=0;y<m_A[x];y++)
      result.push_back(x);
  }
  return result;
  //print(print_counting(m_A));
}





typedef pair<int,int> par;
typedef vector<par> vector_par;

void stable_pairs(vector_par){
  
}


void print_vector_pair(vector_par lista){
  for(int x=0;x<lista.size();x++){
    cout<<lista[x].first<<" ";
  }
  cout<<endl;
}

vector_par concatening_buckets(vector<vector_par>v_b){
  vector_par result;
  for(int x=0;x<v_b.size();x++){
    for(int y=0;y<v_b[x].size();y++)
      result.push_back(v_b[x][y]);
  }
  return result;
}


bool compare_pairs (par i,par j){
  return (int(i.first)<int(j.first));
}

vector_par bucket_sort(vector_par A,int k,int num_b){//k es el mayor
  vector<vector_par>buckets(num_b+1);
  vector_par result;
  int tam_b=k/num_b;
  
  for(int x=0;x<A.size();x++){
    //cout<<"contador "<<A[x].first/tam_b<<endl;
    buckets[A[x].first/tam_b].push_back(A[x]);
  }
  if(num_b<k){
    for(int x=0;x<buckets.size();x++){
      stable_sort (buckets[x].begin(),buckets[x].end(),compare_pairs);
    }
  }
  result=concatening_buckets(buckets);
  return result;
}


int main(){

  vector<int>A={2,10,5,6};

  vector_par v;
  for(int x=0;x<10;x++){
    par n_par;
    n_par.first=10-x;
    v.push_back(n_par);
  }
  //print(counting_sort(A,10));
  print_vector_pair(v);
  print_vector_pair(bucket_sort(v,10,3));
  return 0;
}
