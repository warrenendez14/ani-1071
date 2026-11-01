#include <iostream>
#include <cstdio>

struct Couleur {
    unsigned char r,g,b,a;

    Couleur(unsigned int v) {
        r=v>>24; g=v>>16; b=v>>8; a=v;
    }

    unsigned int empaqueter() const {
        return (unsigned(r)<<24)|(unsigned(g)<<16)|(unsigned(b)<<8)|a;
    }
};

int sat(double x) {
    if(x>255) return 255;
    if(x<0) return 0;
    return int(x+0.5);
}

Couleur operator*(Couleur c,double k) {
    return {0}; // remplacé ci-dessous
}

Couleur ajouter(Couleur c,Couleur d) {
    return Couleur((unsigned(sat(c.r+d.r))<<24)|
                   (unsigned(sat(c.g+d.g))<<16)|
                   (unsigned(sat(c.b+d.b))<<8)|sat(c.a+d.a));
}

Couleur operator+(Couleur c,Couleur d) { return ajouter(c,d); }

Couleur multiplier(Couleur c,double k) {
    return Couleur((unsigned(sat(c.r*k))<<24)|
                   (unsigned(sat(c.g*k))<<16)|
                   (unsigned(sat(c.b*k))<<8)|c.a);
}

Couleur lerp(Couleur c,Couleur d,double t) {
    return Couleur((unsigned(sat(c.r+(d.r-c.r)*t))<<24)|
                   (unsigned(sat(c.g+(d.g-c.g)*t))<<16)|
                   (unsigned(sat(c.b+(d.b-c.b)*t))<<8)|
                   sat(c.a+(d.a-c.a)*t));
}

int main() {
    unsigned char x=200+200;
    std::cout<<"Sans saturer : "<<(int)x<<'\n';

    Couleur c(0xC86432FF), d(0x6496C880);

    Couleur m=multiplier(c,2);
    Couleur s=c+d;
    Couleur t=lerp(c,d,0.5);

    std::printf("Multiplication : %08X\n",m.empaqueter());
    std::printf("Addition : %08X\n",s.empaqueter());
    std::printf("Lerp : %08X\n",t.empaqueter());

    std::printf("Original : %08X\n",c.empaqueter());
    std::printf("Retour : %08X\n",Couleur(c.empaqueter()).empaqueter());

    // Couleur test = {200,100,50,255};
}
