#ifndef VEGAS_INTEGRATOR_H
#define VEGAS_INTEGRATOR_H

#include "VEGAS_map.h"
#include "VEGAS_Stratify.h"
#include <random> // The random number generator and distributions. c++11
#include <vector>
#include <string>
using std::string;
#include "Bin.h"
#include "cmath"
using std::sqrt;
using std::log;
using std::exp;


typedef double (*INTEGRAND)(std::vector<double> x);
typedef double (*BININTEGRAND)(std::vector<double> x, vector<double> *pvd);
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
    friend void VEGAS(INTEGRAND integrand, int DIM, double &RES, double &ERR, double &CHISQ, double EPS_REL, double EPS_ABS);
    friend void VEGAS(BININTEGRAND bintegrand, int DIM, double &RES, double &ERR, double &CHISQ, vector<BIN> &vbin, double EPS_REL, double EPS_ABS);


private:
    VEGAS_INTEGRATOR_VERBOSE verb;

    INTEGRAND func;
    BININTEGRAND bfunc;
    int N_DIM;

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

    void Set_Integrand(INTEGRAND integrand, int dim);
    void Set_Integrand(BININTEGRAND bintegrand, int dim);
    void Set_Bin_Param();
    void Improve_Grid(double eps_rel);
    void Improve_Grid(double eps_rel, vector<BIN> &vbin);
    void Integration(double eps_rel, double eps_abs);
    void Integration(double eps_rel, double eps_abs, vector<BIN> &vbin);
    
    
    double Get_Result();
    double Get_Error();
    double Get_Chisq();

};


#endif //VEGAS_INTEGRATOR_H
