#include <iostream>
#include <cmath>

struct Vec2 {
    double x=0,y=0;
};

struct Transform {
    Vec2 position;
    double rotation=0;
    Vec2 echelle{1,1};

    Vec2 appliquer(Vec2 p) const {
        double x=p.x*echelle.x,y=p.y*echelle.y;
        return {x*cos(rotation)-y*sin(rotation)+position.x,
                x*sin(rotation)+y*cos(rotation)+position.y};
    }

    Transform compose(const Transform& b) const {
        Transform t;
        t.echelle={echelle.x*b.echelle.x,echelle.y*b.echelle.y};
        t.rotation=rotation+b.rotation;
        t.position=appliquer(b.position);
        return t;
    }
};

struct Mat3 {
    double m[3][3]{};

    static Mat3 identite() {
        Mat3 a;
        for(int i=0;i<3;i++) a.m[i][i]=1;
        return a;
    }

    static Mat3 depuis(const Transform& t) {
        Mat3 a;
        double c=cos(t.rotation),s=sin(t.rotation);
        a.m[0][0]=t.echelle.x*c; a.m[0][1]=-t.echelle.y*s;
        a.m[1][0]=t.echelle.x*s; a.m[1][1]=t.echelle.y*c;
        a.m[0][2]=t.position.x; a.m[1][2]=t.position.y;
        a.m[2][2]=1;
        return a;
    }

    Vec2 appliquer(Vec2 p) const {
        return {m[0][0]*p.x+m[0][1]*p.y+m[0][2],
                m[1][0]*p.x+m[1][1]*p.y+m[1][2]};
    }

    Mat3 operator*(const Mat3& b) const {
        Mat3 r;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                    r.m[i][j]+=m[i][k]*b.m[k][j];
        return r;
    }
};

int main() {
    Transform a,b;
    a.rotation=1.57079632679;
    b.echelle={2,1};

    Vec2 p{1,0};
    Vec2 direct=a.appliquer(b.appliquer(p));
    Vec2 compose=a.compose(b).appliquer(p);

    std::cout<<direct.x<<" "<<direct.y<<'\n';
    std::cout<<compose.x<<" "<<compose.y<<'\n';
}
