#ifndef VEGAS_H
#define VEGAS_H
#include "VEGAS_Integrator.h"
using std::fstream;
#include <string>
using std::string;
#include "Bin.h"
#include <vector>
using std::vector;


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ);
void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL);
void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS);


void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, vector<BIN> &vbin);
void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, vector<BIN> &vbin, double EPS_REL);
void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, vector<BIN> &vbin, double EPS_REL, double EPS_ABS);


void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, BIN &bin);
void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, BIN &bin, double EPS_REL);
void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, BIN &bin, double EPS_REL, double EPS_ABS);


#endif //VEGAS_H
