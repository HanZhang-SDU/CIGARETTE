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


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ){
    VEGAS_Integrator inter;
    inter.Set_Integrand(integrand, DIM);
    inter.Improve_Grid(1.0e-2);
    inter.Integration(1.0e-3, 1.0e-9);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL){
    VEGAS_Integrator inter;
    inter.Set_Integrand(integrand, DIM);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.Integration(EPS_REL, 1.0e-9);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS){
    VEGAS_Integrator inter;
    inter.Set_Integrand(integrand, DIM);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.Integration(EPS_REL, EPS_ABS);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


void DVEGAS(INTEGRAND integrand, DINTEGRAND dintegrand, int DIM, double &RES, double &ERR, double &CHISQ, BIN &bin){
    vector<BIN> vbin{bin};
    DVEGAS(integrand, dintegrand, DIM, RES, ERR, CHISQ, vbin);
    bin = vbin[0];
}


void DVEGAS(INTEGRAND integrand, DINTEGRAND dintegrand, int DIM, double &RES, double &ERR, double &CHISQ, BIN &bin, double EPS_REL){
    vector<BIN> vbin{bin};
    DVEGAS(integrand, dintegrand, DIM, RES, ERR, CHISQ, vbin, EPS_REL);
    bin = vbin[0];
}


void DVEGAS(INTEGRAND integrand, DINTEGRAND dintegrand, int DIM, double &RES, double &ERR, double &CHISQ, BIN &bin, double EPS_REL, double EPS_ABS){
    vector<BIN> vbin{bin};
    DVEGAS(integrand, dintegrand, DIM, RES, ERR, CHISQ, vbin, EPS_REL, EPS_ABS);
    bin = vbin[0];
}


void DVEGAS(INTEGRAND integrand, DINTEGRAND dintegrand, int DIM, double &RES, double &ERR, double &CHISQ, vector<BIN> &vbin){
    VEGAS_Integrator inter;
    inter.Set_Integrand(integrand, dintegrand, DIM);
    inter.Improve_Grid(1.0e-2);
    inter.Integration(1.0e-3, 1.0e-9, vbin);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


void DVEGAS(INTEGRAND integrand, DINTEGRAND dintegrand, int DIM, double &RES, double &ERR, double &CHISQ, vector<BIN> &vbin, double EPS_REL){
    VEGAS_Integrator inter;
    inter.Set_Integrand(integrand, dintegrand, DIM);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.Integration(EPS_REL, 1.0e-9, vbin);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


void DVEGAS(INTEGRAND integrand, DINTEGRAND dintegrand, int DIM, double &RES, double &ERR, double &CHISQ, vector<BIN> &vbin, double EPS_REL, double EPS_ABS){
    VEGAS_Integrator inter;
    inter.Set_Integrand(integrand, dintegrand, DIM);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.Integration(EPS_REL, EPS_ABS, vbin);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


