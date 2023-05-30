#include <stdio.h>

int suma(int *S, int n, int a[]){
    int i;
    for(i=0; i<n; i++)
        (*S)+=a[i];
    return 0;
}

int exista(int S, int n, int a[]){
    int i;
    for(i=0; i<n; i++)
        if(a[i]==S) {
            return 1;
        }
    return 0;
}

int div_et_impera(int L, int n, int a[]){
    if(n<=0) return 0;
    int Ss=0, Sd=0, S1=L, S2=L, S=0;
    suma(&Ss, n/2+n%2, a);
    Sd = L-Ss;
    printf("1. Ss=%d Sd=%d S=%d\n", Ss, Sd, S1);
    if(!exista(Ss, n/2, a)) S1+= div_et_impera(Ss, n/2, a);
    if(!exista(Sd, n, a+n/2)) S1+= div_et_impera(Sd, n/2, a+n/2);

    Ss=0, Sd=0, S2=L, S=0;
    suma(&Sd, n/2, a+n/2+n%2);
    Ss = L - Sd;
    printf("2. Ss=%d Sd=%d S=%d\n", Ss, Sd, S1);
    if(!exista(Ss, n/2, a)) S2+= div_et_impera(Ss, n/2, a);
    if(!exista(Sd, n, a+n/2)) S2+= div_et_impera(Sd, n/2, a+n/2);

    if(S1<S2) S=S1;
    else S=S2;
    return S;

}


int main() {
    //int n=3, a[]={1, 1, 4}, L=6;
    int n=4, a[]={3, 1, 4, 1}, L=10;
    //int n=4, a[]={2, 2, 2, 2}, L=10;
    //int n=4, a[]={4, 2, 5, 3}, L=20;
    printf("%d\n", div_et_impera(L, n, a));
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    return 0;
}
