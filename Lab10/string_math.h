#ifndef STRING_MATH_H
#define STRING_MATH_H

#include <string>
#include <vector>

bool is_valid_double(const std::string& s);
std::string add_string_doubles(const std::string& a, const std::string& b);
void split_double(const std::string& s, std::string& int_part, std::string& frac_part);
std::vector<std::string> read_lines(const std::string& filename);

#endif // STRING_MATH_H
#pragma once
