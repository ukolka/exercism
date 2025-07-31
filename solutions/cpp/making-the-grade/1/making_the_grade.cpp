#include <array>
#include <string>
#include <vector>
#include <sstream>

static int lowest_score{40};
static int max_score{100};

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> result;
    result.reserve(student_scores.size());
    for (auto &score : student_scores) {
        result.emplace_back(score);
    }
    
    return result;
}


// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int sum{};
    for (auto &score : student_scores) {
        if (score <= lowest_score) {
            ++sum; 
        }
    }
    return sum;
}

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
    std::vector<int> result{};
    for (auto &score : student_scores) {
        if (score >= threshold) {
            result.emplace_back(score);
        }
    }
    return result;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int len{4};
    std::array<int, 4> result{lowest_score + 1};
    int increment = (highest_score - lowest_score) / len;
    
    for (int i{1}; i < len; ++i) {
        result[i] = result[i - 1] + increment;    
    }
    return result;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, 
    std::vector<std::string> student_names
) {
    std::vector<std::string> result;
    result.reserve(student_scores.size());
    for (int i = student_scores.size() - 1, rank = 1; i >= 0; --i, ++rank) {
        std::ostringstream oss;
        oss << rank << ". " << student_names[i] << ": " << student_scores[i];
        result.emplace_back(oss.str());
    }
    return result;
}

// Create a string that contains the name of the first student to make a perfect score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    for (int i{}; i < student_scores.size(); ++i) {
        if (student_scores[i] == max_score) {
            return student_names[i];
        }
    }
    return "";
}
