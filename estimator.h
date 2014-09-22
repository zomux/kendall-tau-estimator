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
typedef vector<string> StringList;
typedef boost::tuple<int, int> IntPair;
typedef vector<IntPair> IntPairList;

class KendallTauEstimator {

public:
    double EstimateOneLine(string line);
    void FeedOneLine(string line);
    double Average();

private:

    IntList taus;
    IntList ExtractAlignment(string line);
};

#endif