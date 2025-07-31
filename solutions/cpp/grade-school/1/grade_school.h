#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

namespace grade_school {
    class school {
    private:
        map<int, vector<string>> roster_;
    public:
        void add(const string& name, int n); 

        map<int, vector<string>> roster() const; 

        vector<string> grade(int n) const; 
    };
}  

#endif