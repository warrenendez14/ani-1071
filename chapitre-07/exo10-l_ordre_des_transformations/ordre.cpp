#include <iostream>
#include <cmath>

struct Vec2 { double x,y; };

Vec2 operator+(Vec2 a,Vec2 b) {
    return {a.x+b.x,a.y+b.y};
}

Vec2 rotate(Vec2 a,double t) {
    return {a.x*cos(t)-a.y*sin(t),a.x*sin(t)+a.y*cos(t)};
}

struct Transform {
    Vec2 position{10,5},echelle{2,1};
    double rotation=3.141592653589793/4;
    int ordre=0;

    Vec2 appliquer(Vec2 p) const {
        if(ordre==0) {
            p={p.x*2,p.y};
            return rotate(p,rotation)+position;
        }
        if(ordre==1) {
            p=rotate(p,rotation);
            p={p.x*2,p.y};
            return p+position;
        }
        p={p.x*2,p.y};
        return rotate(p+position,rotation);
    }
};

const int H=20,L=40;
char image[H][L];

void point(int x,int y) {
    if(x>=0&&x<L&&y>=0&&y<H) image[y][x]='#';
}

void segment(Vec2 a,Vec2 b) {
    for(int i=0;i<=60;i++) {
        double t=i/60.0;
        point(int((a.x+(b.x-a.x)*t)*2),
              H-1-int((a.y+(b.y-a.y)*t)*2));
    }
}

void afficher() {
    for(int y=0;y<H;y++) {
        for(int x=0;x<L;x++)
            std::cout<<(image[y][x]?image[y][x]:' ');
        std::cout<<'\n';
    }
}

int main() {
    Vec2 coins[]={{-.5,-.5},{.5,-.5},{.5,.5},{-.5,.5}};

    for(int o=0;o<3;o++) {
        Transform tr;
        tr.ordre=o;
        Vec2 p[4];

        std::cout<<"\nOrdre "<<o+1<<":\n";

        for(int i=0;i<4;i++) {
            p[i]=tr.appliquer(coins[i]);
            std::cout<<"("<<p[i].x<<", "<<p[i].y<<")\n";
        }

        for(int i=0;i<4;i++)
            segment(p[i],p[(i+1)%4]);

        afficher();

        for(int y=0;y<H;y++)
            for(int x=0;x<L;x++) image[y][x]=' ';
    }
}
