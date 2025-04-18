#include "string_math.h"
#include <fstream>
#include <sstream>
#include <cctype>
#include <iostream>
#include <algorithm>

// Function to read lines from a file
std::vector<std::string> read_lines(const std::string& filename) {
    std::ifstream infile(filename);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(infile, line)) {
        lines.push_back(line);
    }
    return lines;
}

// Function to check if a string is a valid double
bool is_valid_double(const std::string& s) {
    if (s.empty()) return false;
    int i = 0, len = s.length();
    if (s[i] == '+' || s[i] == '-') i++;
    bool has_digits = false, has_dot = false, has_frac_digits = false;

    for (; i < len; ++i) {
        if (std::isdigit(s[i])) {
            if (!has_dot) has_digits = true;
            else has_frac_digits = true;
        }
        else if (s[i] == '.') {
            if (has_dot) return false; // multiple dots
            has_dot = true;
        }
        else {
            return false; // invalid character
        }
    }
    if (has_dot && !has_frac_digits) return false;
    if (!has_digits && !has_frac_digits) return false;
    return true;
}
// Function to split a string into integer and fractional parts
void split_double(const std::string& s, std::string& int_part, std::string& frac_part) {
    size_t dot_pos = s.find('.');
    if (dot_pos == std::string::npos) {
        int_part = s;
        frac_part = "";
    }
    else {
        int_part = s.substr(0, dot_pos);
        frac_part = s.substr(dot_pos + 1);
    }
}
// Function to add two parts of a string (integer or fractional)
std::string add_parts(const std::string& a, const std::string& b, bool is_fractional) {
    std::string result;
    int carry = 0;
    int max_len = std::max(a.size(), b.size());
    std::string a_pad = a, b_pad = b;

    if (is_fractional) {
        a_pad.append(max_len - a.size(), '0');
        b_pad.append(max_len - b.size(), '0');
    }
    else {
        a_pad.insert(0, max_len - a.size(), '0');
        b_pad.insert(0, max_len - b.size(), '0');
    }

    for (int i = max_len - 1; i >= 0; --i) {
        int digit_a = a_pad[i] - '0';
        int digit_b = b_pad[i] - '0';
        int sum = digit_a + digit_b + carry;
        carry = sum / 10;
        result.insert(result.begin(), '0' + (sum % 10));
    }
    if (!is_fractional && carry) result.insert(result.begin(), '0' + carry);
    return result;
}
// Function to add two string representations of doubles
std::string add_string_doubles(const std::string& a_str, const std::string& b_str) {
    bool neg_a = (a_str[0] == '-');
    bool neg_b = (b_str[0] == '-');
    std::string a = (neg_a || a_str[0] == '+') ? a_str.substr(1) : a_str;
    std::string b = (neg_b || b_str[0] == '+') ? b_str.substr(1) : b_str;

    std::string a_int, a_frac, b_int, b_frac;
    split_double(a, a_int, a_frac);
    split_double(b, b_int, b_frac);

    std::string frac_sum = add_parts(a_frac, b_frac, true);
    if (frac_sum.length() > std::max(a_frac.size(), b_frac.size())) {
        frac_sum.pop_back();
        a_int = add_parts(a_int, "1", false);
    }
    std::string int_sum = add_parts(a_int, b_int, false);
    std::string result = int_sum;
    if (!frac_sum.empty()) result += "." + frac_sum;

    if (neg_a && neg_b) result = "-" + result;
    return result;
}