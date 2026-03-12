#include "VEGAS.h"
#include "cmath"
using std::fmin;
#include <fstream>
using std::fstream;
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS){
    VEGAS_Integrator inter;
    inter.Set_Integrand(integrand, DIM);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.Integration(EPS_REL, EPS_ABS);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL){
    VEGAS(integrand, DIM, RES, ERR, CHISQ, EPS_REL, 1.0e-20);
}


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ){
    VEGAS(integrand, DIM, RES, ERR, CHISQ, 1.0e-3, 1.0e-20);
}


void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, vector<BIN> &vbin, double EPS_REL, double EPS_ABS){
    VEGAS_Integrator inter;
    inter.Set_Integrand(bintegrand, DIM);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL), vbin);
    inter.Integration(EPS_REL, EPS_ABS, vbin);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, vector<BIN> &vbin, double EPS_REL){
    VEGAS(bintegrand, DIM, RES, ERR, CHISQ, vbin, EPS_REL, 1.0e-20);
}


void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, vector<BIN> &vbin){
    VEGAS(bintegrand, DIM, RES, ERR, CHISQ, vbin, 1.0e-3, 1.0e-20);
}


void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, BIN &bin, double EPS_REL, double EPS_ABS){
    vector<BIN> vbin;
    vbin.push_back(bin);
    VEGAS(bintegrand, DIM, RES, ERR, CHISQ, vbin, EPS_REL, EPS_ABS);
    bin = *(vbin.begin());
}


void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, BIN &bin, double EPS_REL){
    VEGAS(bintegrand, DIM, RES, ERR, CHISQ, bin, EPS_REL, 1.0e-20);
}


void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, BIN &bin){
    VEGAS(bintegrand, DIM, RES, ERR, CHISQ, bin, 1.0e-3, 1.0e-20);
}


