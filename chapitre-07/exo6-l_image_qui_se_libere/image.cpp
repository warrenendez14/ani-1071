#include <iostream>

class Image {
    int l, h;
    char* p;
    static int vivantes;

    void point(int x,int y,char c='#') {
        if(x>=0 && x<l && y>=0 && y<h) p[y*l+x]=c;
    }

public:
    Image(int L,int H):l(L),h(H),p(new char[L*H]) {
        effacer(); vivantes++;
    }

    ~Image() { delete[] p; vivantes--; }

    Image(const Image&)=delete;
    Image& operator=(const Image&)=delete;

    int largeur() const { return l; }
    int hauteur() const { return h; }

    void effacer(char c=' ') {
        for(int i=0;i<l*h;i++) p[i]=c;
    }

    void afficher() const {
        for(int y=0;y<h;y++) {
            for(int x=0;x<l;x++) std::cout<<p[y*l+x];
            std::cout<<'\n';
        }
    }

    void segment(double x0,double y0,double x1,double y1,char c='#') {
        for(int i=0;i<=60;i++) {
            double t=i/60.0;
            point(int(x0+(x1-x0)*t+0.5),
                  int(y0+(y1-y0)*t+0.5),c);
        }
    }

    static int nombreVivantes() { return vivantes; }
};

int Image::vivantes=0;

int main() {
    std::cout<<"Avant la boucle : "<<Image::nombreVivantes()<<'\n';

    for(int i=1;i<=10;i++) {
        Image a(20,10);
        a.segment(0,0,19,9);
        std::cout<<"Tour "<<i<<" : "<<Image::nombreVivantes()<<" image(s) vivante(s)\n";
    }

    std::cout<<"Apres la boucle : "<<Image::nombreVivantes()<<'\n';

    Image a(21,11);
    a.segment(1,1,19,9);
    a.segment(1,9,19,1);
    std::cout<<"Dessin des deux segments :\n";
    a.afficher();

    // Image b = a;
}
