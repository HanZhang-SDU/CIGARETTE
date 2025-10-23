#ifndef VEGAS_H
#define VEGAS_H
#include "VEGAS_Integrator.h"
using std::fstream;
#include <string>
using std::string;
#include "Bin.h"


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ);


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL);


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS);


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, VEGAS_INTEGRATOR_VERBOSE level);


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, VEGAS_INTEGRATOR_VERBOSE level, void *param);


void DVEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, BIN bin);


void DVEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, BIN bin, string &filename);


void DVEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, BIN bin, string &filename, VEGAS_INTEGRATOR_VERBOSE level);


void DVEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, BIN bin, string &filename, VEGAS_INTEGRATOR_VERBOSE level, void *param);


#endif //VEGAS_H
