// NAME:Jake Ernsting
// KU ID: 3144926
// DATE: 10/21/2025
// PROGRAM: EECS 348 Lab 8 - NFL Score Tracker
// DESCRIPTION: This program reads NFL score combinations and lists 
// all possible ways to achieve that score using football scoring methods.
// INPUT: A non-negative score of an NFL game
// OUTPUT: All combinations of scoring plays that result in the given score
// SOURCES: ChatGPT & VSCode co-pilot 

#include <stdio.h>
#include <ctype.h>

static void lists_combos(int score) {   // Lists all the scoring methods to reach a total score
    printf("Possible scoring combinations for %d points:\n", score);

    int found = 0;  // Checks if at least one combination is found
    for (int td_8 = 0; td_8 <= score / 8; ++td_8) { // Loops through all possible combinations with 8 point tds
        int s1 = score - td_8 * 8;                  // Remaining score after 8-pt TDs
        for (int td_7 = 0; td_7 <= s1 / 7; ++td_7) {    // Loops through all possible combinations with 7 point tds
            int s2 = s1 - td_7 * 7;                     // Remaining score after 7-pt TDs
            for (int td_6 = 0; td_6 <= s2 / 6; ++td_6) {    // Loops through all possible combinations with 6 point tds
                int s3 = s2 - td_6 * 6;                     // Remaining score after 6-pt TDs
                for (int fg = 0; fg <= s3 / 3; ++fg) {  // Loops through all possible combinations with field goals
                    int s4 = s3 - fg * 3;               // Remaining score after field goals
                    for (int safety = 0; safety <= s4 / 2; ++safety) {  // Loops through all possible combinations with safeties
                        int s5 = s4 - safety * 2;                       // Remaining score after safeties
                        if (s5 == 0) {              // If remaining is zero, an exact combination is found     
                            printf("8-pt TDs: %d, 7-pt TDs: %d, 6-pt TDs: %d, FGs: %d, Safeties: %d\n",
                                td_8, td_7, td_6, fg, safety);
                            found = 1;  // Mark that at least one combination is found
                        }
                    }
                }
            }
        }                
    }

    if (!found) {      // Output if no combinations were found
        printf("No combinations found.\n");
    }
}

int main(void) {
    while (1) {     // Main loop to repeatedly ask for scores until a negative score is entered
        int score;
        printf("Enter the NFL score to analyze (enter 1 to quit): ");
        if (scanf("%d", &score) != 1) {     // Makes sure input is a valid integer
            int c; while ((c = getchar()) != '\n' && c != EOF); {}
            printf("Invalid input.");
            continue;
        }

        if (score == 1) break;  // Break loop if user wants to quit
        
        if (score < 0) {    // Negative scores are not valid
            printf("Score cannot be negative.\n");
            continue;
        }

        if (score < 2) {    // Dont allow scores less than 2 except 1
            printf("Score must be at least 2 points.\n");
            continue;
        }
        lists_combos(score);    // List combinations for valid scores
        puts("");   // Add blank
    }
    return 0;
}


