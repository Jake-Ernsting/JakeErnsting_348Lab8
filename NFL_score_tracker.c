

#include <stdio.h>
#include <ctype.h>

static void lists_combos(int score) {
    printf("Possible scoring combinations for %d points:\n", score);

    int found = 0;
    for (int td_8 = 0; td_8 <= score / 8; ++td_8) {
        int s1 = score - td_8 * 8;
        for (int td_7 = 0; td_7 <= s1 / 7; ++td_7) {
            int s2 = s1 - td_7 * 7;
            for (int td_6 = 0; td_6 <= s2 / 6; ++td_6) {
                int s3 = s2 - td_6 * 6;
                for (int fg = 0; fg <= s3 / 3; ++fg) {
                    int s4 = s3 - fg * 3;
                    for (int safety = 0; safety <= s4 / 2; ++safety) {
                        int s5 = s4 - safety * 2;

                        printf("8-pt TDs: %d, 7-pt TDs: %d, 6-pt TDs: %d, FGs: %d, Safeties: %d\n",
                               td_8, td_7, td_6, fg, safety);
                        found = 1;
                    }
                }
            }
        }                
    }

    if (!found) {
        printf("  No combinations found.\n");
    }
}

int main(void) {
    while (1) {
        int score;
        printf("Enter the NFL score to analyze (negative to quit): ");
        if (scanf("%d", &score) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF); {}
            printf("Invalid input.");
            continue;
        }
        if (score == 1) break;
        if (score < 2) {
            printf("Score must be at least 2 points.\n");
            continue;
        }
        lists_combos(score);
        puts("");
    }
    return 0;
}


