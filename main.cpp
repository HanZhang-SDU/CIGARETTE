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


VEGAS_INTEGRAND_RETURN_TYPE In(vector<double> x, void *userdata){
    double a = 0.1;
    double Pi = acos(-1.0);
    int n = x.size();
    double res = 1.0;
    //do bin according to bin_var
    double bin_var;
    for(double &xi : x){
        res = res*(1/(a*sqrt(Pi)));
        res = res*exp(-pow(xi - 1.0/2.0, 2)/pow(a, 2));
    }
    //do bin according to x[0]
    bin_var = x[0];
    return {res, bin_var};
}


int main(){
    string filename("data.txt");
    fstream fs{filename, fs.out};
    if (!fs.is_open()){
        std::cout << "failed to open " << filename << '\n';
        return -1;
    }
    int DIM = 4;
    double RES, ERR, CHISQ; 
    double EPS_REL = 1.0e-3;
    double EPS_ABS = 1.0e-20;
    VEGAS_INTEGRATOR_VERBOSE verb = INFO;
    void *userdata = nullptr;
    //If you just want to compute the integral, call VEGAS.
    //VEGAS(In, DIM, RES, ERR, CHISQ, EPS_REL, EPS_ABS);
    //If you need differential distribution, call DVEGAS.
    DVEGAS(In, DIM, RES, ERR, CHISQ, EPS_REL, EPS_ABS, {0.0, 1.0, 51}, filename);
    cout << "res = " << RES << ", err = " << ERR << ", chisq = " << CHISQ << endl;
    return 0;
}
