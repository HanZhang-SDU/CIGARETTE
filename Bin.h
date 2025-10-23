#ifndef BIN_H
#define BIN_H
#include <vector>
using std::vector;
#include <ostream>
using std::ostream;
using std::endl;
#include <fstream>
using std::fstream;


class BIN{
    friend void Swallow(BIN &bin, double bin_var, double weight);
    friend ostream & operator<<(ostream &ostr, BIN &bin);
    friend fstream & operator<<(fstream &fstr, BIN &bin);
    public:
        BIN() = delete;
        BIN(double bin_var_min, double bin_var_max, int bin_num);
        ~BIN(){};
        BIN& operator+=(const BIN &other);
        BIN& operator*=(const double fac);
        BIN& operator/=(const double fac);
        void reset_heights();
        void Swallow(const double bin_var, const double weight);
        double integrate();
    private:
        double data_before;
        double data_after;
        double width;
        vector<double> edges;
        vector<double> heights;
};


BIN operator+(BIN bin1, const BIN &bin2);


BIN operator*(BIN bin1, const double fac);


BIN operator/(BIN bin1, const double fac);


ostream & operator<<(ostream &ostr, BIN &bin);


fstream & operator<<(fstream &fstr, BIN &bin);


#endif //BIN_H
