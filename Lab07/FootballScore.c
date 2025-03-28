#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter 1 or less to STOP\n");
        printf("Enter the NFL score: ");
        scanf_s("%d", &score);

        if (score <= 1) break;

        printf("\nPossible combinations of scoring plays if a team’s score is %d:\n\n", score);

        for (int td2 = 0; td2 <= score / 8; td2++) {
            for (int td1 = 0; td1 <= score / 7; td1++) {
                for (int td = 0; td <= score / 6; td++) {
                    for (int fg = 0; fg <= score / 3; fg++) {
                        for (int safety = 0; safety <= score / 2; safety++) {
                            int total = td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2;
                            if (total == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                    td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }

        printf("\n");
    }

    return 0;
}
