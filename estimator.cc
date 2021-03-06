#include "estimator.h"

using namespace std;

IntList KendallTauEstimator::ExtractAlignment(string line) {
    IntList alignments;
    boost::regex partition_regex(".+? \\(\\{ ([0-9]+) \\}\\)");

    boost::sregex_iterator regex_it(line.begin(), line.end(), partition_regex);
    boost::sregex_iterator end;
    boost::smatch match;

    for (int index = 0; regex_it != end; ++regex_it, ++index) {
        match = *(regex_it);
        string aligned_parts_str = match[1].str();
        boost::trim(aligned_parts_str);
        if (aligned_parts_str.size() == 0) continue;
        alignments.push_back(atoi(aligned_parts_str.c_str()));
    }
    return alignments;
}

double KendallTauEstimator::EstimateOneLine(string line) {
    IntList alignments = ExtractAlignment(line);

    int concordant_num = 0;
    int all_count = 0;

    for (int i = 0; i < alignments.size() - 1; ++i) {
        for (int j = i + 1; j < alignments.size(); ++j) {
            // Is concordant?
            if ( (alignments[j] - alignments[i]) >= 0 ) {
                concordant_num += 1;
            }
            all_count += 1;
        }
    }
    double tau;
    if (all_count == 0) {
        tau = 0;
    } else {
        tau = 2.0 * concordant_num / all_count - 1.0;
    }

    return tau;
}

void KendallTauEstimator::FeedOneLine(string line) {
    taus_.push_back(EstimateOneLine(line));
}

double KendallTauEstimator::Average() {

    if (taus_.size() == 0) {
        return 0;
    } else {
        double sum = accumulate(taus_.begin(), taus_.end(), 0.0);
        double average = sum / taus_.size();
        return average;
    }
}
