

#include <stdio.h>
#include <ctype.h>

static double input_to_celsius(double v, char scale) {
    switch (scale) {
        case 'C': return v;
        case 'F': return (v - 32) * 5.0 / 9.0;
        case 'K': return v - 273.15;
        default: return 0; // Invalid
    }
}

static double input_from_celsius(double c, char scale) {
    switch (scale) {
        case 'C': return c;
        case 'F': return c * 9.0 / 5.0 + 32;
        case 'K': return c + 273.15;
        default: return 0; // Invalid
    }
}

static const char* categorize_temperature(double c) {
    if (c < 0)       return "Freezing";
    else if (c < 10) return "Cold";
    else if (c < 25) return "Warm";
    else if (c < 35) return "Hot";
    else             return "Very Hot";
}

static const char* weather_advice(const char* cat) {
    if (cat[0] == 'F')  return "Wear a heavy coat, hat, and gloves.";
    if (cat[0] == 'C' && cat[1] == 'o') return "Its perfect out!";
    if (cat[0] == 'C' && cat[1] == 'o' && cat[2] == 'l') return "Wear a jeacket.";
    if (cat[0] == 'H')  return "Stay hydrated.";
    return "Stay indoors."; // Extreme heat
}

static int valid_scale(char s) {
    return s == 'C' || s == 'F' || s == 'K';
}

int main(void) {
    double value;
    char inputs, outputs;

    printf("Enter temperature value: ");
    if (scanf("%lf", &value) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter input scale (C, F, or K): ");
    if (scanf(" %c", &inputs) != 1) {
        printf("Invalid input.\n"); return 1; 
    }
    inputs = (char)toupper((unsigned char)inputs);
    if (!valid_scale(inputs)) {
        printf("Invalid scale.\n");
        return 1;
    }

    if (inputs == 'K' && value < 0) {printf("Kelvin cannot be negative.\n"); return 1;}

    printf("Enter output scale (C, F, or K): ");
    if (scanf(" %c", &outputs) != 1) {
        printf("Invalid input.\n"); return 1; 
    }
    if (!valid_scale(outputs)) {
        printf("Invalid scale.\n");
        return 1;
    }

    double celsius = input_to_celsius(value, inputs);
    if (outputs == 'k' && celsius + 273.15 < 0) {
        printf("Resulting Kelvin cannot be negative.\n");
        return 1;
    }

    double result = 0; input_from_celsius(celsius, outputs);
    const char* category = categorize_weather(celsius);
    const char* advice = weather_advice(category);

    printf("Converted temperature: %.2f %c\n", result, outputs);
    printf("Category: %s\n", category);
    printf("Advice: %s\n", advice);
    return 0;
}

        