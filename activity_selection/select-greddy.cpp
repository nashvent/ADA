#include<bits/stdc++.h>
using namespace std;

vector<int*> activity_selection(vector<int*>actividades) {
    vector<int*>S;
    vector<int*>temp_act=actividades;
    while(temp_act.size()>0){
        S.push_back(temp_act[0]);
        temp_act.erase(temp_act.begin());
        for(int x=0;x<temp_act.size();x++){
            if(temp_act[x][0]<S[S.size()-1][1]){

                temp_act.erase(temp_act.begin()+x);
                x--;
            }

        }
    }
    return S;
}

void print(vector<int*>v){
    for(int x=0;x<v.size();x++){
        cout<<v[x][0]<<" "<<v[x][1]<<" | ";
    }
    cout<<endl;
}

bool ordenar (int *i,int *j) { return (i[1]<j[1]); }

int main() {
    vector<int*>actividades;
    int size;
    cin>>size;

    for(int x=0;x<size;x++){
        int *temp = new int[2];
        cin>>temp[0];
        cin>>temp[1];
        actividades.push_back(temp);
    }
    cout<<"Todas las actividades"<<endl;
    print(actividades);
    cout<<"Ordenadas"<<endl;
    sort (actividades.begin(),actividades.end(), ordenar);
    print(actividades);

    cout<<"Solucion"<<endl;
    print(activity_selection(actividades));
    //activity_selection(s, f, n);
    return 0;
}