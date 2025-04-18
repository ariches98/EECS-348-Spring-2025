#include "string_math.h"
#include <iostream>



int main() {
	// Prompt user for input filename
    std::string filename;
    std::cout << "Enter input filename: ";
    std::cin >> filename;

	// Read lines from the file
    auto lines = read_lines(filename);
    for (const auto& line : lines) {
        if (is_valid_double(line)) {
            std::string result = add_string_doubles(line, "-123.456");
            std::cout << "Valid: " << line << " + (-123.456) = " << result << std::endl;
        }
        else {
            std::cout << "Invalid: " << line << std::endl;
        }
    }
    return 0;
}
