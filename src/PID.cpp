#include "PID.h"
#include "iostream" 

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
 this->Kp=Kp;
 this->Ki=Ki;
 this->Kd=Kd;
 p_error=-0.7598;
 i_error=0;
 d_error=0;
}

void PID::UpdateError(double cte) {
 d_error=-cte-p_error;
 i_error+=-cte;
 p_error=-cte;
}

double PID::TotalError() {
 double e=eval();
 cout<<"e="<<e<<endl;
 if(e> 1) e= 1;
 if(e<-1) e=-1;
 return e;
}

double PID::eval(){
 return Kp*p_error+Ki*i_error+Kd*d_error;
}

