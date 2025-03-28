#include <stdio.h>
#include <ctype.h>

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    printf("\nCategory & Advisory: ");
    if (celsius < 0) {
        printf("Freezing Wear a heavy coat!\n");
    }
    else if (celsius < 10) {
        printf("Cold Wear a jacket.\n");
    }
    else if (celsius < 25) {
        printf("Comfortable Enjoy the day!\n");
    }
    else if (celsius < 35) {
        printf("Hot Stay hydrated.\n");
    }
    else {
        printf("Extreme Heat Stay indoors if possible!\n");
    }
}

int main() {
    float input_temp;
    char input_scale, target_scale;
    char cont;

    do {
        printf("\nEnter temperature value: ");
        scanf_s("%f", &input_temp);

        printf("Enter input scale (C, F, or K): ");
        scanf_s(" %c", &input_scale, 1);

        printf("Enter target scale (C, F, or K): ");
        scanf_s(" %c", &target_scale, 1);

        input_scale = toupper(input_scale);
        target_scale = toupper(target_scale);

        if (input_scale == target_scale) {
            printf("Error: Input and target scales are the same.\n");
            goto continue_prompt;
        }

        if ((input_scale != 'C' && input_scale != 'F' && input_scale != 'K') ||
            (target_scale != 'C' && target_scale != 'F' && target_scale != 'K')) {
            printf("Invalid scale entered. Use C, F, or K.\n");
            goto continue_prompt;
        }

        if (input_scale == 'K' && input_temp < 0) {
            printf("Error: Kelvin cannot be negative.\n");
            goto continue_prompt;
        }

        float temp_in_celsius;
        float converted;

        // Convert to Celsius
        if (input_scale == 'C') temp_in_celsius = input_temp;
        else if (input_scale == 'F') temp_in_celsius = fahrenheit_to_celsius(input_temp);
        else temp_in_celsius = kelvin_to_celsius(input_temp);

        // Convert to target scale
        if (target_scale == 'C') converted = temp_in_celsius;
        else if (target_scale == 'F') converted = celsius_to_fahrenheit(temp_in_celsius);
        else converted = celsius_to_kelvin(temp_in_celsius);

        printf("\nConverted temperature: %.2f %c\n", converted, target_scale);
        categorize_temperature(temp_in_celsius);

    continue_prompt:
        printf("\nDo you want to convert another temperature? (Y/N): ");
        scanf_s(" %c", &cont, 1);
        cont = toupper(cont);

    } while (cont == 'Y');

    printf("\nProgram terminated.\n");
    return 0;
}
