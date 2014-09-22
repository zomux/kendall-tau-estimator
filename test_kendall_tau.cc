#include "estimator.h"

using namespace std;

int main() {
    string testcase = "NULL ({ }) ＤＮＡ ({ 1 }) 解析 ({ 2 }) の ({ 3 }) 技術 ({ 4 }) を ({ }) 解説 ({ 6 }) し ({ 5 }) た ({ }) 。 ({ 7 })";

    KendallTauEstimator estimator;
    estimator.FeedOneLine(testcase);
    cout << estimator.Average() << endl;
}