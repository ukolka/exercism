#pragma once
#include <string>
using namespace std;

namespace run_length_encoding {
    string encode(const string& input);
    string decode(const string& input);
}  // namespace run_length_encoding
