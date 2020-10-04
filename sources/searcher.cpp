#include <randomSearcher>
RandomSearcher::RandomSearcher(const float &a, const float& b) {
    if(a >= b){
        throw std::invalid_argument("a must be less than b");
    }
    interval = std::make_pair(a,b);
    for (float i = 0.05; i <= 0.1; i+=0.05){
        qVec.emplace_back(i);
    }
    for (float i = 0.9; i <= 0.99; i += 0.01){
        pVec.emplace_back(i);
    }
}
