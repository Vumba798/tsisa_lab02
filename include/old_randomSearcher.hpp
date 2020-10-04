#ifndef RANDOM_SEARCHER_HPP_
#define RANDOM_SEARCHER_HPP_

#include <searcher.hpp>
#include <vector>


class RandomSearcher : public Searcher {
    public:
        inline RandomSearcher(const float &a, const float &b) : Searcher(a, b);
        void print() const override final;
        std::vector<float> search() const;
};
#endif // RANDOM_SEARCHER_HPP_
