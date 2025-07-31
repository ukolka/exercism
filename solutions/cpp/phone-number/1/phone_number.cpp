#include "phone_number.h"

namespace phone_number {
    phone_number::phone_number(const string& input) {
        size_t max_len = 11;
        digits = "";
        for (auto it = input.rbegin(); it != input.rend(); ++it) {
            if (isdigit(*it)) {
                digits = *it + digits;
                if (digits.length() == max_len - 4 && digits[0] < '2') {
                    throw domain_error("Expect valid exchange code.");
                }
                if (digits.length() == max_len - 1 && digits[0] < '2') {
                    throw domain_error("Expect valid area code.");
                }
                if (digits.length() == max_len && digits[0] != '1') {
                    throw domain_error("Expect 1 as country code.");
                }
                if (digits.length() > max_len) {
                    throw domain_error("Expect not too many digits.");
                }
            }
        }
        if (digits.size() < 10) {
            throw domain_error("Expect at least 10 digits.");
        }
    }

    string phone_number::number() const {
        return digits.substr(digits.size() - 10); 
    }

    string phone_number::area_code() const {
        return number().substr(0, 3);
    }

}  // namespace phone_number
