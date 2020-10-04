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
    vector<float> _qVec;
    vector<float> _pVec;
    vector<vector<uint16_t>> _nVec;
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
    float _search_unomodal(const uint16_t& N) const;
    float _search_multimodal(const uint16_t& N) const;
    float _search(const uint16_t& N, float (*f)(const float& x)) const;
    template<typename T>
    void _print(const vector<vector<T>> &vec) const;
public:
    RandomSearcher(const float &a, const float &b);
    void print() const;
};

#endif // INCLUDE_RANDOMSEARCHER_HPP

