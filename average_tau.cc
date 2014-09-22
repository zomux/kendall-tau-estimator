#include <iostream>
#include "estimator.h"

using namespace std;

int main() {

    KendallTauEstimator *estimator = new KendallTauEstimator();
    string line;
    while(getline(cin, line)) {
        if (boost::contains(line, "{") && boost::contains(line, "}")) {
            estimator->FeedOneLine(line);
        }
    }

    cout << "Average: " << estimator->Average() << endl;

    return 0;
}