#include <iostream>
#include <cmath>

const double pi=3.141592653589793;

double lerp(double a,double b,double t){return a+(b-a)*t;}

double lerpAngle(double a,double b,double t){
    double d=fmod(b-a+3*pi,2*pi)-pi;
    return a+d*t;
}

double deg(double a){
    a=fmod(a*180/pi,360);
    return a<0?a+360:a;
}

void test(double a,double b){
    for(int i=0;i<=10;i++){
        double t=i/10.0;
        std::cout<<deg(lerp(a,b,t))<<" "<<deg(lerpAngle(a,b,t))<<"\n";
    }
}

int main(){
    test(350*pi/180,10*pi/180);
    test(10*pi/180,350*pi/180);
    test(0,pi);

    double cap=340,c1=340,c2=340;
    for(int i=0;i<12;i++){
        cap=fmod(cap+4,360);
        c1=lerp(c1,cap,.3);
        c2=deg(lerpAngle(c2*pi/180,cap*pi/180,.3)*180/pi);
        std::cout<<cap<<" "<<c1<<" "<<c2<<"\n";
    }
}
