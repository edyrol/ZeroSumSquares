#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

void init_coloring(vector<int> &m, int unos){
    for(int i=0; i<unos;++i){
        m[i] = -1;
    }
    for(int i=unos; i<m.size();++i){
        m[i] = 1;
    }
}

void print(vector<int> &m){
    for(int i=0; i<N;++i){
        for(int j=0; j<N;++j){
            if(m[i*N+j] == 1)
                cout << "X ";
            else
                cout << "O ";
        }
        cout << '\n';
    }
    cout << endl;
}

int x(int v){return v/N;}
int y(int v){return v%N;}
int ind(int x,int y){return x*N+y;}

//sum of square that ends in v and has side s
int sum_square(vector<int> &m, int v, int s){
    return m[v]+
           m[ind(x(v)-s,y(v))]+
           m[ind(x(v),y(v)-s)]+
           m[ind(x(v)-s,y(v)-s)];
}


int first_problem_index(vector<int> &m){
    for(int i=0;i<m.size();++i){
        int max_s = min(x(i),y(i));
        for (int s=1;s<=max_s;++s){
            if(sum_square(m,i,s)==0)
                return i;
        }
    }
    return -1;
}

int main () {
    int unos;
    cout << "Tamaño de la matriz: ";
    cin >> N;
    cout << "Número de unos (N/2="<< N*N/2 << "): ";
    cin >> unos;

    vector<int> m(N*N);
    init_coloring(m,unos);
    
    do{
        int i = first_problem_index(m);
        if(i == -1){
            cout << "Aquí no hay cuadrados balanceados!!\n";
            print(m);
            //return 0;
            i=N*N-1;
        }
        if(m[i] == -1){
            sort(m.begin()+i+1,m.end(),greater<int>());
        }else{
            sort(m.begin()+i,m.end(),greater<int>());
        }
    }while(next_permutation(m.begin()+1,m.end()));
    cout << "Terminé!\n";
    return 0;
}
