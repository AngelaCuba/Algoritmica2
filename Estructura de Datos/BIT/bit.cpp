#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
#define MAX_N 100010

int BIT[10010];
int tamanoVector;

void update(int posicion, int valor){
    for(; posicion<=tamanoVector; posicion+=posicion & -posicion){
        BIT[posicion]+=valor;
    }
}

int query2(int posicion){
    int resultado =0;
    for(; posicion>0; posicion-= posicion & -posicion){
        resultado+=BIT[posicion];
    }
    return resultado;
}

int query(int inicio, int final){
    return query2(final) - query2(inicio-1);
}

main(){
    input;
    cin>>tamanoVector;
    for(int i=0; i<tamanoVector; i++){
        int x;
        cin>>x;
        update(i+1,x);
    }
    cout<<query(3,4)<<endl;
    cout<<query(1,6)<<endl;
    cout<<query(4,5)<<endl;
    cout<<query(1,1)<<endl;
    cout<<query(2,2)<<endl;
    return 0;
}
