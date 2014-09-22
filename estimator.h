#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/foreach.hpp>
#include <numeric>

#ifndef KENDALL_TAU_ESTIMATOR
#define KENDALL_TAU_ESTIMATOR

using namespace std;

typedef vector<int> IntList;
typedef vector<double> DoubleList;
typedef vector<string> StringList;

class KendallTauEstimator {

public:
    double EstimateOneLine(string line);
    void FeedOneLine(string line);
    double Average();

private:

    DoubleList taus_;
    IntList ExtractAlignment(string line);
};

#endif