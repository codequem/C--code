#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main(void)
{
    int N= 3000;
    double u=4*(3.1415926)*(1e-7);
    double L=0.26;
    double D=0.035;
    double Kh=176.2;
    double Ih=5.00;
    double Im=500;

    double U1,U2,U3,U4;
    double Uh;
    double B;
    double Bz,Bd;
    Bz=u*N*Im/(sqrt(L*L+D*D));
    Bd=0.5*Bz;
    double X;
    for(int i=0;i<18;i++)
    {
        cout<<"请输入X:";
        cin>>X;
        cout<<"请输入U1,U2,U3,U4:";
        cin>>U1>>U2>>U3>>U4;
        B=Uh/Kh*Ih;
        Uh=0.25*fabs(U1-U2+U3-U4);
        cout<<"X:"<<X<<"(cm)"<<endl;
        cout<<"Uh:"<<Uh<<"B:"<<B<<endl;
    }
    cout<<"理论B中心值:"<<Bz;
    cout<<"理论B边缘值:"<<Bd;
}