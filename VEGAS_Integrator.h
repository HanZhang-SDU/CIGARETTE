#ifndef VEGAS_INTEGRATOR_H
#define VEGAS_INTEGRATOR_H

#include "VEGAS_map.h"
#include "VEGAS_Stratify.h"
#include <random> // The random number generator and distributions. c++11
#include <vector>
#include <complex>
#include <string>
using std::string;
#include "Bin.h"

typedef std::complex<double> VEGAS_INTEGRAND_RETURN_TYPE;
typedef VEGAS_INTEGRAND_RETURN_TYPE (*INTEGRAND)(std::vector<double> x, void *param);
using URD=std::uniform_real_distribution<double>;

enum VEGAS_INTEGRATOR_VERBOSE
{
    NONE = 0,
    INFO = 1,
    DEBUG = 2,
    ALL = 3
};

class VEGAS_Integrator
{
    friend void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ);
    friend void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL);
    friend void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS);
    friend void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, VEGAS_INTEGRATOR_VERBOSE level);
    friend void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, VEGAS_INTEGRATOR_VERBOSE level, void *param);
    friend void DVEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, BIN bin);
    friend void DVEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, BIN bin, string &filename);
    friend void DVEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, BIN bin, string &filename, VEGAS_INTEGRATOR_VERBOSE level);
    friend void DVEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, BIN bin, string &filename, VEGAS_INTEGRATOR_VERBOSE level, void *param);


private:
    VEGAS_INTEGRATOR_VERBOSE verb;

    INTEGRAND func;
    int N_DIM;
    void* userdata;

    VEGAS_Map map;
    VEGAS_Stratify strat;

    std::mt19937 rng; // Mersenne twister random number engine
    URD dist; // uniform distribution in double in [0.0, 1.0)

    std::vector<double> Results;
    std::vector<double> Sigma2;


//public:
    VEGAS_Integrator(){verb = INFO;};
    ~VEGAS_Integrator(){};

    void Set_Verbose(VEGAS_INTEGRATOR_VERBOSE level);

    void Set_Integrand(INTEGRAND integrand, int dim, void* param);
    void Set_Bin_Param();
    void Improve_Grid(double eps_rel);
    void Integration(double eps_rel, double eps_abs);
    void DIntegration(double eps_rel, double eps_abs, BIN &bin);
    
    
    double Get_Result();
    double Get_Error();
    double Get_Chisq();

};


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ);


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL);


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS);


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, VEGAS_INTEGRATOR_VERBOSE level);


void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS, VEGAS_INTEGRATOR_VERBOSE level, void *param);


#endif //VEGAS_INTEGRATOR_H
