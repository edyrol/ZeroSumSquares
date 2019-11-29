#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,M;

void init_coloring(vector<int> &m, int unos){
    for(int i=0; i<unos;++i){
        m[i] = -1;
    }
    for(int i=unos; i<m.size();++i){
        m[i] = 1;
    }
}

int x(int v){return v/M;}
int y(int v){return v%M;}
int ind(int x,int y){return x*M+y;}

void print(vector<int> &m){
    for(int i=0; i<N;++i){
        for(int j=0; j<M;++j){
            if(m[ind(i,j)] == 1)
                cout << "X ";
            else
                cout << "O ";
        }
        cout << '\n';
    }
    cout << endl;
}

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
            if(sum_square(m,i,s)==0){
                return i;
            }
        }
    }
    return -1;
}

int main (int argc, char* argv[]) {
    if(argc < 4 || argc > 5){
        cout << "Finds all (0,1)-colorings of a N by M matrix with discrepancy d." <<endl;
        cout << "usage: " << argv[0] << " N M d [stop_at_first]"<<endl;
        return 0;
    }
    N=stoi(argv[1]);
    M=stoi(argv[2]);
    if(N>M){
        int temp=N;
        N=M;
        M=temp;
    }
    int unos=N*M/2 - stoi(argv[3]);
    int stop_at_first = 1;
    if(argc == 5){
        stop_at_first = stoi(argv[4]);
    }

    vector<int> m(N*M);
    init_coloring(m,unos);
    
    int counter=0;

    do{
        int i = first_problem_index(m);
        if(i == -1){
            cout << "This example has no balanced squares:\n";
            print(m);
            if(stop_at_first==1){
                return 0;
            }
            ++counter;
            i=N*M-1;
        }
        sort(m.begin()+i+1,m.end(),greater<int>());
    }while(next_permutation(m.begin(),m.end()));
    cout << "There were "<<counter<<" examples with no balanced squares."<<endl;
    return 0;
}
