#include <iostream>
#include <cstdio>
class Image {
    int l,h;
    char* p;
    static int v;
public:
    Image(int L,int H):l(L),h(H),p(new char[L*H]) {
        for(int i=0;i<l*h;i++) p[i]=' ';
        v++;
    }
    Image(const Image& a):Image(a.l,a.h) {
        for(int i=0;i<l*h;i++) p[i]=a.p[i];
    }
    ~Image(){delete[] p;v--;}

    Image& operator=(const Image& a) {
        // if(this==&a) return *this;
        delete[] p;
        l=a.l; h=a.h; p=new char[l*h];
        for(int i=0;i<l*h;i++) p[i]=a.p[i];
        return *this;
    }
    void point(int x,int y){if(x>=0&&x<l&&y>=0&&y<h)p[y*l+x]='#';}
    void afficher()const{
        for(int y=0;y<h;y++){
            for(int x=0;x<l;x++)std::cout<<p[y*l+x];
            std::cout<<'\n';
        }
    }
    void adresse(){std::printf("%p\n",(void*)p);}
    static int compte(){return v;}
};
int Image::v=0;

int main(){
    {
        Image a(10,5); a.point(2,2);
        Image b=a; b.point(3,2);
        a.afficher(); b.afficher();
        Image c(4,4); c=a; c.point(4,2); a.afficher();
        std::cout<<Image::compte()<<'\n';
        a.adresse(); a=a; a.adresse(); a.afficher();
    }
    std::cout<<Image::compte()<<'\n';
}
