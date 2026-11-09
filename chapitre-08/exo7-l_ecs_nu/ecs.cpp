#include <iostream>
#include <cstdio>

struct Vec2 {
    double x=0,y=0;
    Vec2(double a=0,double b=0):x(a),y(b){}
    Vec2& operator+=(Vec2 b){x+=b.x;y+=b.y;return *this;}
};
Vec2 operator*(Vec2 a,double k){return {a.x*k,a.y*k};}

const int MAX=1000,H=20,L=40;
using Entite=int;

struct Transform{Vec2 position;double rotation;Vec2 echelle;};
struct Corps{Vec2 vitesse;double masse;};
struct Sprite{char glyphe;};

Transform t[MAX];Corps c[MAX];Sprite s[MAX];
bool at[MAX]={},ac[MAX]={},as[MAX]={};
int suivant[MAX],libre=0;
char image[H][L];

void initialiser(){
    for(int i=0;i<MAX;i++)suivant[i]=i+1;
    suivant[MAX-1]=-1;
}
Entite creerEntite(){
    if(libre==-1)return -1;
    int e=libre;libre=suivant[e];return e;
}
void detruireEntite(Entite e){
    at[e]=ac[e]=as[e]=false;
    suivant[e]=libre;libre=e;
}
int systemePhysique(double dt){
    int n=0;
    for(int i=0;i<MAX;i++)if(at[i]&&ac[i]){
        c[i].vitesse.y-=9.81*dt;
        t[i].position+=c[i].vitesse*dt;n++;
    }
    return n;
}
int systemeRendu(){
    int n=0;
    for(int i=0;i<MAX;i++)if(at[i]&&as[i]){
        int x=(int)t[i].position.x,y=(int)t[i].position.y;
        if(x>=0&&x<L&&y>=0&&y<H){image[H-1-y][x]=s[i].glyphe;n++;}
    }
    return n;
}
int main(){
    initialiser();
    Entite ids[100];

    for(int i=0;i<100;i++){
        int e=ids[i]=creerEntite();
        at[e]=true;t[e].position=Vec2(i%40,i/40);
        if(i<40||i>=80){as[e]=true;s[e].glyphe=i<40?'#':'E';}
        if(i>=40)ac[e]=true;
    }

    for(int i=0;i<5;i++)
        std::cout<<systemePhysique(.1)<<" "<<systemeRendu()<<'\n';

    for(int i=4;i<50;i+=5)detruireEntite(ids[i]);
    for(int i=0;i<5;i++)std::cout<<creerEntite()<<'\n';

    std::cout<<systemePhysique(.1)<<" "<<systemeRendu()<<'\n';

    for(auto& ligne:image)for(char& c:ligne)c=' ';
    systemeRendu();
    for(auto& ligne:image){for(char c:ligne)std::printf("%c",c);std::printf("\n");}
}
