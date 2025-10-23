#include "Bin.h"
#include "vector"
using std::vector;
#include "cmath"
using std::floor;
#include <stdexcept>


//BIN::BIN():data_before{0.0}, data_after{0.0}, width{1.0}{}


BIN::BIN(double bin_var_min, double bin_var_max, int bin_num){
    if(bin_var_max <= bin_var_min){
        throw std::invalid_argument("When initializing BIN object, upper limit must be greater than lower limit");
    }
    if(bin_num <=0){
        throw std::invalid_argument("BIN object can not be initialized with bin number <= 0.");
    }
    data_before=0.0;
    data_after=0.0;
    width=(bin_var_max - bin_var_min)/bin_num;
    heights = vector<double>(bin_num, 0.0);
    for(int i = 0; i <= bin_num; i++){
        edges.push_back(bin_var_min + i*width);
    }
}


BIN& BIN::operator+=(const BIN &other){
    if(edges != other.edges){
        return *this;
    }
    data_before += (other.data_before);
    data_after += (other.data_after);
    for(int i=0; i<=heights.size()-1; i++){
        heights[i] += (other.heights)[i];
    }
    return *this;
}


BIN operator+(BIN bin1, const BIN &bin2){
    bin1 += bin2;
    return bin1;
}


BIN& BIN::operator*=(const double fac){
    data_before *= fac;
    data_after *= fac;
    for(double &bh : heights){
        bh *= fac;
    }
    return *this;
}


BIN operator*(BIN bin1, const double fac){
    bin1 *= fac;
    return bin1;
}


BIN& BIN::operator/=(const double fac){
    data_before /= fac;
    data_after /= fac;
    for(double &bh : heights){
        bh /= fac;
    }
    return *this;
}


BIN operator/(BIN bin1, const double fac){
    bin1 /= fac;
    return bin1;
}


void BIN::Swallow(const double bin_var, const double weight){
    int i;
    if(edges.empty()){
        return;
    }
    if(bin_var < edges[0]){
        data_before += weight/width;
        return;
    }
    if(bin_var >= edges[edges.size()-1]){
        data_after += weight/width;
        return;
    }
    i = floor((bin_var - edges[0])/width);
    heights[i] += weight/width;
}


void BIN::reset_heights(){
    data_before = 0.0;
    data_after = 0.0;
    for(double &bh : heights){
        bh = 0.0;
    }
}


ostream & operator<<(ostream &ostr, BIN &bin){
    if(bin.edges.empty()){
        return ostr;
    }
    ostr << bin.edges[0] - bin.width << endl;
    for(double &be : bin.edges){
        ostr << be << endl;
    }
    ostr << bin.edges[bin.edges.size()-1] + bin.width << endl;
    ostr << bin.data_before << endl;
    for(double &bh : bin.heights){
        ostr << bh << endl;
    }
    ostr << bin.data_after;
    return ostr;
}


fstream & operator<<(fstream &fstr, BIN &bin){
    if(bin.edges.empty()){
        return fstr;
    }
    fstr << bin.edges[0] - bin.width << '\n';
    for(double &be : bin.edges){
        fstr << be << '\n';
    }
    fstr << bin.edges[bin.edges.size()-1] + bin.width << '\n';
    fstr << bin.data_before << '\n';
    for(double &bh : bin.heights){
        fstr << bh << '\n';
    }
    fstr << bin.data_after;
    return fstr;
}


double BIN::integrate(){
    double res = 0.0;
    res += data_before*width;
    res += data_after*width;
    for(double bh : heights){
        res += bh*width;
    }
    return res;
}


