#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H
#include <string>
#include <stdexcept>
using namespace std;

namespace phone_number {
    class phone_number {
    private:
        string digits;
    public:
        phone_number(const string& input); 

        string number() const;

        string area_code() const; 

        operator std::string () const {
            return "(" + area_code() + ") " +
                digits.substr(digits.size() - 7, 3) +
                "-" + digits.substr(digits.size() - 4, 4);
        }
    };
}  // namespace phone_number

#endif // PHONE_NUMBER_H