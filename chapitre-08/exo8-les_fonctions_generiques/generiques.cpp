#include <iostream>
#include <string>

struct Vec2 { double x,y; };

template<typename T>
void echanger(T& a,T& b){T t=a;a=b;b=t;}

template<typename T>
T maximum(T a,T b){return a>b?a:b;}

template<typename T>
T minimum(T a,T b){return a<b?a:b;}

template<typename T>
T clamp(T x,T bas,T haut){return minimum(maximum(x,bas),haut);}

template<typename T>
void trier(T t[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(t[j]<t[i])echanger(t[i],t[j]);
}

int main(){
    int a=3,b=7;
    double x=2.5,y=8.5;

    echanger(a,b);
    std::cout<<a<<" "<<b<<'\n';
    std::cout<<maximum(a,b)<<'\n';
    std::cout<<minimum(x,y)<<'\n';
    std::cout<<clamp(12,0,10)<<'\n';

    Vec2 u{1,2},v{3,4};
    echanger(u,v);

    // maximum(u,v);
    // maximum(3,7.5);

    std::string mots[]={"zebre","Yaounde","arbre","Zoo","abricot"};
    trier(mots,5);
    for(auto m:mots)std::cout<<m<<'\n';
}
