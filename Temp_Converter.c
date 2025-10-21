// NAME:Jake Ernsting
// KU ID: 3144926
// DATE: 10/21/2025
// PROGRAM: EECS 348 Lab 8 - Temperature Converter
// DESCRIPTION: This program converts temperatures between Celsius, Fahrenheit, and Kelvin scales,
// categorizes the feel of temperature, and gives weather advice.
// INPUT: Asks for a temperature, what scale is the input in, and what scale to convert to
// OUTPUT: The converted temperature, its feel, and weather advice
// SOURCES: ChatGPT & VSCode co-pilot 

#include <stdio.h>
#include <ctype.h>
#include <string.h>


static double input_to_celsius(double v, char scale) {  // Converts an input temperature in any scale to Celsius
    switch (scale) {
        case 'C': return v;     // Returns Celsius as is
        case 'F': return (v - 32.0) * 5.0 / 9.0;    // Converts Fahrenheit to Celsius
        case 'K': return v - 273.15;    // Converts Kelvin to Celsius
        default:  return 0.0;   // unreachable if validated
    }
}

static double input_from_celsius(double c, char scale) {    // Converts a Celsius temperature to an output scale
    switch (scale) {
        case 'C': return c;    // Returns Celsius as is
        case 'F': return c * 9.0 / 5.0 + 32.0;  // Converts Celsius to Fahrenheit
        case 'K': return c + 273.15;    // Converts Celsius to Kelvin
        default:  return 0.0;  // unreachable if validated
    }
}


static const char* temp_feel(double c) {    // Categorizes a Celsius temperature into weather feel
    if (c < 0.0)        return "Freezing";  // Below 0 Celsius
    else if (c < 10.0)  return "Cold";      // 0 to 9.99 Celsius
    else if (c < 25.0)  return "Warm";      // 10 to 24.99 Celsius
    else if (c < 35.0)  return "Hot";       // 25 to 34.99 Celsius
    else                return "Very Hot";  // 35 Celsius and above
}

static const char* weather_advice(const char* cat) {   // Provides weather advice based on temperature feel
    if (strncmp(cat, "Freezing", 8) == 0)  return "Wear a heavy coat, hat, and gloves.";
    if (strncmp(cat, "Cold", 4) == 0)      return "Wear a jacket.";
    if (strncmp(cat, "Warm", 4) == 0)      return "It’s perfect out!";
    if (strncmp(cat, "Hot", 3) == 0)       return "Stay hydrated.";
    return "Stay indoors."; // If it is very hot return
}

static int valid_scale(char s) {    // Makes sure the scale input is in Celsius, Fahrenheit, or Kelvin
    return s == 'C' || s == 'F' || s == 'K';
}

int main(void) {
    double value;   // Temperature value
    char inputs, outputs;   // Input and output scales

    printf("Enter temperature value: ");    // Input prompt
    if (scanf("%lf", &value) != 1) {    // Make sure input is a valid number
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter input scale (C, F, or K): ");   // Input scale prompt
    if (scanf(" %c", &inputs) != 1) {   // Make sure input is a valid character
        printf("Invalid input.\n");
        return 1;
    }

    inputs = (char)toupper((unsigned char)inputs);  // Converts to uppercase

    if (!valid_scale(inputs)) {     // Validates scale
        printf("Invalid scale.\n");
        return 1;
    }

    if (inputs == 'K' && value < 0.0) {     // Kelvin cannot be negative
        printf("Kelvin cannot be negative.\n");
        return 1;
    }

    printf("Enter output scale (C, F, or K): ");    // Output scale prompt
    if (scanf(" %c", &outputs) != 1) {   // Read valid input to target scale
        printf("Invalid input.\n");
        return 1;
    }

    outputs = (char)toupper((unsigned char)outputs);    // Converts to uppercase

    if (!valid_scale(outputs)) {    // Validates scale
        printf("Invalid scale.\n");
        return 1;
    }

    double celsius = input_to_celsius(value, inputs);   // Conver the input into Celsius for feel and adivice, then to output scale
    
    if (outputs == 'K' && celsius + 273.15 < 0.0) {   // Resulting Kelvin cannot be negative
        printf("Resulting Kelvin cannot be negative.\n");
        return 1;
    }

    double result      = input_from_celsius(celsius, outputs);  // Change Celsius to output scale
    const char* category = temp_feel(celsius);  // Get temp feel from Celsius
    const char* advice   = weather_advice(category);    // Get advice from temp feel

    // Print output results 
    printf("Converted temperature: %.2f %c\n", result, outputs);
    printf("Category: %s\n", category);
    printf("Advice: %s\n", advice);
    return 0;
}
