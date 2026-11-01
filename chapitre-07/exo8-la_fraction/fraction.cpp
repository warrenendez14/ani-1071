#include <iostream>
#include <cstdlib>

int pgcd(int a,int b) {
    a=abs(a); b=abs(b);
    while(b) { int r=a%b; a=b; b=r; }
    return a;
}

class Fraction {
    int n,d;
public:
    Fraction(int a,int b) {
        if(b==0) { n=0; d=0; return; }
        int g=pgcd(a,b);
        n=a/g; d=b/g;
        if(d<0) { n=-n; d=-d; }
    }

    Fraction operator+(Fraction f) const { return Fraction(n*f.d+f.n*d,d*f.d); }
    Fraction operator-(Fraction f) const { return Fraction(n*f.d-f.n*d,d*f.d); }
    Fraction operator*(Fraction f) const { return Fraction(n*f.n,d*f.d); }
    Fraction operator/(Fraction f) const {
        if(f.n==0) return Fraction(0,0);
        return Fraction(n*f.d,d*f.n);
    }
    bool operator==(Fraction f) const { return n==f.n && d==f.d; }

    void afficher() const {
        if(d==0) std::cout<<"Erreur";
        else std::cout<<n<<"/"<<d;
    }
};

int main() {
    Fraction a(1,2),b(1,3);

    std::cout<<"Addition : "; (a+b).afficher();
    std::cout<<"\nSoustraction : "; (a-b).afficher();
    std::cout<<"\nMultiplication : "; (a*b).afficher();
    std::cout<<"\nDivision : "; (a/b).afficher();

    std::cout<<"\nReduction : "; Fraction(4,8).afficher();
    std::cout<<"\nNegatif : "; Fraction(1,-2).afficher();

    std::cout<<"\nEgalite : "<<(Fraction(1,2)==Fraction(2,4));
    std::cout<<"\nDifference : "<<(a==b);

    std::cout<<"\nDenominateur nul : "; Fraction(1,0).afficher();
    std::cout<<"\nDivision par zero : "; (a/Fraction(0,1)).afficher();
}
