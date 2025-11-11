#include <cmath>
using std::acos;
using std::sqrt;
using std::pow;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;
#include <string>
using std::string;
#include "VEGAS.h"
#include "Bin.h"


double In(vector<double> x){
    double a = 0.1;
    double Pi = acos(-1.0);
    int n = x.size();
    double res = 1.0;
    for(double &xi : x){
        res = res*(1/(a*sqrt(Pi)));
        res = res*exp(-pow(xi - 1.0/2.0, 2)/pow(a, 2));
    }
    return res;
}


double DIn(vector<double> x, vector<double> *pvd){
    double a = 0.1;
    double Pi = acos(-1.0);
    int n = x.size();
    double res = 1.0;
    for(double &xi : x){
        res = res*(1/(a*sqrt(Pi)));
        res = res*exp(-pow(xi - 1.0/2.0, 2)/pow(a, 2));
    }
    for(int i = 0; i < (*pvd).size(); i++){
        (*pvd)[i] = x[i];
    }
    return res;
}


int main(){
    int DIM = 4;
    double RES, ERR, CHISQ; 
    double EPS_REL = 1.0e-4;
    double EPS_ABS = 1.0e-20;
    VEGAS_INTEGRATOR_VERBOSE verb = INFO;
    string filename("data.txt");
    fstream fs;


//    //If you just want to compute the integral, then
//    VEGAS(In, DIM, RES, ERR, CHISQ, EPS_REL, EPS_ABS);
//    cout << "res = " << RES << ", err = " << ERR << ", chisq = " << CHISQ << endl;


    //If you want to collect one bin data, then
    BIN xbin(0.0, 1.0, 51);
    DVEGAS(In, DIn, DIM, RES, ERR, CHISQ, xbin, EPS_REL, EPS_ABS);
    cout << "res = " << RES << ", err = " << ERR << ", chisq = " << CHISQ << endl;
    cout << "xbin.integrate() = " << (xbin).integrate() << ", " << "xbin.integrate()/res = " << xbin.integrate()/RES << endl;
    fs.open(filename, fs.out);
    fs << xbin << '\n';
    fs.close();



//    //If you just want to collect bin data while doing the integral, then
//    vector<BIN> vbin{BIN(0.0, 1.0, 51), BIN(0.0, 1.0, 81)};
//    DVEGAS(In, DIn, DIM, RES, ERR, CHISQ, vbin, EPS_REL);
//    cout << "res = " << RES << ", err = " << ERR << ", chisq = " << CHISQ << endl;
//    cout << "vbin[0].integrate() = " << (vbin[0]).integrate() << ", " << "vbin[0].integrate()/res = " << (vbin[0]).integrate()/RES << endl;
//    cout << "vbin[1].integrate() = " << (vbin[1]).integrate() << ", " << "vbin[1].integrate()/res = " << (vbin[1]).integrate()/RES << endl;
//    fs.open(filename, fs.out);
//    fs << vbin[0] << '\n';
//    fs.close();


    return 0;
}
