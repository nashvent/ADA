#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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

void insert(vector<int>&lista){
  for(int x=1;x<lista.size();x++){
    int y=x;
    //while(y>0 and lista[y]<lista[y-1]){
    while(y>0 and es_mayor(lista[y-1],lista[y])){
      int temp=lista[y];
      lista[y]=lista[y-1];
      lista[y-1]=temp;
      y--;
    }
    
  }
}

vector<int>agregarEl(int tam){ //Random
  vector<int>vect(tam);
  for(int x=0;x<tam;x++){
    vect[x]=rand()%tam;
  }
  return vect;
}

vector<int>agregarEl1(int tam){ //Mejor Caso
  vector<int>vect(tam);
  for(int x=0;x<tam;x++){
    vect[x]=x;
  }
  return vect;
}


vector<int>agregarEl2(int tam){ //Peor caso
  vector<int>vect(tam);
  for(int x=0;x<tam;x++){
    vect[x]=tam-x;
  }
  return vect;
}

int main(){
  
  for(int x=1000;x<=50000;x+=1000){    
    vector<int>lista=agregarEl(x);
    //clock_t begin = clock();
    insert(lista);
    cout<<op<<endl;
    op=0;
    //clock_t end = clock();
    //double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //cout<<double(end - begin) / CLOCKS_PER_SEC<<endl;
  }
  
  //print(agregarEl(10));

  //insert(lista);
  //cout<<lista[2]<<endl;
  
  return 0;
}
