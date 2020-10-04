#ifndef INCLUDE_RANDOMSEARCHER_HPP
#define INCLUDE_RANDOMSEARCHER_HPP

#include <algorithm>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <vector>

using std::vector;

class RandomSearcher{
protected:
    vector<float> _qVec; // common poin is in the interval of uncertainty
    vector<float> _pVec; // point of minimum is in the interval of uncertainty
    vector<vector<uint16_t>> _nVec; // vector of points
    vector<vector<float>> _unomodalYvec; 
    vector<vector<float>> _multimodalYvec;
    std::pair<float,float> _interval;

    float static _uno_modal_func(const float &x)  {
        return -0.5 * std::cos(0.5 * x) - 0.5;
    }
    float static _multi_modal_func(const float &x) {
        return _uno_modal_func(x) * std::sin(5*x);
    }
    inline uint16_t _calculate_N(const float &p, const float &q) const {
        return std::ceil(std::log(1-p) / std::log(1-q));
    }
    // searchers minimum value from the vector
    float _search(const uint16_t& N, float (*f)(const float& x)) const;
    template<typename T>
    void _print(const vector<vector<T>> &vec) const;
public:
    RandomSearcher(const float &a, const float &b);
    void print() const;
};

#endif // INCLUDE_RANDOMSEARCHER_HPP

