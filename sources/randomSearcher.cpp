#include <randomSearcher.hpp>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <utility>
#include <random>
using std::endl;
using std::cout;
using std::cin;
using std::setw;
using std::setfill;
using std::setprecision;
using std::right;

float RandomSearcher::_search(const uint16_t& N, float (*f)(const float& x)) const{
    std::vector<float> yVec;
    for (size_t i = 0; i < N; ++i) {
        float x = static_cast<float>(std::rand())/static_cast<float>(RAND_MAX);
        x = x * (_interval.second - _interval.first) + _interval.first;
        yVec.emplace_back(f(x));
    }
    return *std::min_element(yVec.begin(), yVec.end());
}

RandomSearcher::RandomSearcher(const float &a, const float& b) {
    if(a >= b){
        throw std::invalid_argument("a must be less than b");
    }
    _interval = std::make_pair(a,b);
    for (float i = 0.005; i < 0.105; i+=0.005){
        _qVec.emplace_back(i);
    }
    for (float i = 0.9; i <= 0.99; i += 0.01){
        _pVec.emplace_back(i);
    }
    for (size_t i = 0; i < _qVec.size(); ++i){
        std::vector<uint16_t> tmpNvec;
        std::vector<float> tmpUnomodalYvec;
        std::vector<float> tmpMultiModalYvec;
        for (size_t j = 0; j < _pVec.size(); ++j) {
            std::vector<float> multiModalX;
            std::vector<float> unoModalX;
            tmpNvec.emplace_back(_calculate_N(_pVec[j], _qVec[i]));
            tmpUnomodalYvec.emplace_back(_search(tmpNvec.back(), _uno_modal_func));
            tmpMultiModalYvec.emplace_back(_search(tmpNvec.back(), _multi_modal_func));
        }
        _unomodalYvec.emplace_back(tmpUnomodalYvec);
        _multimodalYvec.emplace_back(tmpMultiModalYvec);
        _nVec.emplace_back(tmpNvec);
    }
}


template <typename T>
void RandomSearcher::_print(const std::vector<std::vector<T>> &vec) const {
    std::vector<float> xVec;

    cout << "========================================================"
         << "=======================================================\n";
    cout << "|   q\\p   |";
    for(size_t i = 0; i < _pVec.size(); ++i){
        cout << " " << setw(7) << _pVec.at(i) << " |";
    }
    cout << endl;
    for(size_t i = 0; i < _qVec.size(); ++i){
        cout << "|";
        for(size_t j = 0; j < _pVec.size(); ++j) {
            cout << setfill('-') << setw(10) << right << "+";
        }
        cout << setfill(' ') << "---------|" << endl;
        cout << "| " << setw(7) << _qVec.at(i) << " |";
        for (size_t k = 0; k < _pVec.size(); ++k) {
            cout << " " << setw(7) << setprecision(3) <<  vec.at(i).at(k) << " |";
        }
        cout << endl;
    }
    cout << "---------------------------------------------------------"
         << "------------------------------------------------------\n";

}

void RandomSearcher::print() const{
    cout << "\t\t\t\t\t\tN PRINT\n";
    _print(_nVec);
    cout << "\n\n\n\t\t\t\t\t\tUNOMODAL PRINT\n";
    _print(_unomodalYvec);
    cout << "\n\n\n\t\t\t\t\t\tMULTIMODAL PRINT\n";
    _print(_multimodalYvec);
}

