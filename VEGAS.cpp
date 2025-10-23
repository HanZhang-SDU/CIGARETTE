#include "VEGAS.h"
#include "cmath"
using std::fmin;
#include <fstream>
using std::fstream;
#include <iostream>
using std::cout;
using std::endl;


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ){
    VEGAS_Integrator inter;
    inter.Set_Integrand(integrand, DIM, nullptr);
    inter.Improve_Grid(1.0e-2);
    inter.Integration(1.0e-3, 1.0e-9);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL){
    VEGAS_Integrator inter;
    inter.Set_Integrand(integrand, DIM, nullptr);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.Integration(EPS_REL, 1.0e-9);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS){
    VEGAS_Integrator inter;
    inter.Set_Integrand(integrand, DIM, nullptr);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.Integration(EPS_REL, EPS_ABS);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, VEGAS_INTEGRATOR_VERBOSE level){
    VEGAS_Integrator inter;
    inter.Set_Verbose(level);
    inter.Set_Integrand(integrand, DIM, nullptr);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.Integration(EPS_REL, EPS_ABS);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, VEGAS_INTEGRATOR_VERBOSE level, void *param){
    VEGAS_Integrator inter;
    inter.Set_Verbose(level);
    inter.Set_Integrand(integrand, DIM, param);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.Integration(EPS_REL, EPS_ABS);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


//The following interfaces are intented for doing bin.


void DVEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, BIN bin){
    VEGAS_Integrator inter;
    inter.Set_Integrand(integrand, DIM, nullptr);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.DIntegration(EPS_REL, EPS_ABS, bin);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
}


void DVEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, BIN bin, string &filename){
    VEGAS_Integrator inter;
    inter.Set_Integrand(integrand, DIM, nullptr);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.DIntegration(EPS_REL, EPS_ABS, bin);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
    fstream fs{filename, fs.out};
    if (!fs.is_open()){
        std::cout << "failed to open " << filename << endl;
        return;
    }
    fs << bin << '\n';
}


void DVEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, BIN bin, string &filename, VEGAS_INTEGRATOR_VERBOSE level){
    VEGAS_Integrator inter;
    inter.Set_Verbose(level);
    inter.Set_Integrand(integrand, DIM, nullptr);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.DIntegration(EPS_REL, EPS_ABS, bin);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
    fstream fs{filename, fs.out};
    if (!fs.is_open()){
        std::cout << "failed to open " << filename << endl;
        return;
    }
    fs << bin << '\n';
}


void DVEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, BIN bin, string &filename, VEGAS_INTEGRATOR_VERBOSE level, void *param){
    VEGAS_Integrator inter;
    inter.Set_Verbose(level);
    inter.Set_Integrand(integrand, DIM, param);
    inter.Improve_Grid(fmin(1.0e-2, 10*EPS_REL));
    inter.DIntegration(EPS_REL, EPS_ABS, bin);
    RES = inter.Get_Result();
    ERR = inter.Get_Error();
    CHISQ = inter.Get_Chisq();
    fstream fs{filename, fs.out};
    if (!fs.is_open()){
        std::cout << "failed to open " << filename << endl;
        return;
    }
    fs << bin << '\n';
}


