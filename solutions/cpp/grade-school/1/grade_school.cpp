#include "grade_school.h"

namespace grade_school {
    void school::add(const string& name, int n) {
        auto& g = roster_[n];
        auto it = find(g.begin(), g.end(), name);
        if (it == g.end()) {
            g.push_back(name);
            sort(g.begin(), g.end(), [](const string& a, const string&b) {
                return a < b;
            });
        }
    }

    map<int, vector<string>> school::roster() const {
        return roster_; 
    }

    vector<string> school::grade(int n) const {
        if(roster_.count(n))
            return roster_.at(n);
        else
            return vector<string>();
    }
}  
