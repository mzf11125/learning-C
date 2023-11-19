#include <stdio.h>

int main() {
    int N;
    int score = 0;

    scanf("%d", &N);

    int j, l, b;
    scanf("%d %d %d", &j, &l, &b);

    int participantScores[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &participantScores[i]);
        score += participantScores[i];
    }

    int allscore = score + (j + l + b);
    int averageScore = allscore / (N+3);

    if (j >= averageScore) {
        printf("Jojo lolos\n");
    } else {
        printf("Jojo tidak lolos\n");
    }

    if (l >= averageScore) {
        printf("Lili lolos\n");
    } else {
        printf("Lili tidak lolos\n");
    }

    if (b >= averageScore) {
        printf("Bibi lolos\n");
    } else {
        printf("Bibi tidak lolos\n");
    }

    return 0;
}
