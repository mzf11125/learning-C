#include <stdio.h>

int main() {
    double assignmentScore, midtermScore, finalExamScore;
    double finalScore;

    
    scanf("%lf %lf %lf", &assignmentScore, &midtermScore, &finalExamScore);

	
	if (assignmentScore > 100 || midtermScore > 100 || finalExamScore > 100) {
        assignmentScore = midtermScore = finalExamScore = 100;
    }
	
	
    finalScore = (0.2 * assignmentScore) + (0.3 * midtermScore) + (0.5 * finalExamScore);

    
    printf("%.2lf\n", finalScore);

    return 0;
}
