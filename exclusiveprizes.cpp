#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1001

int main() {
    int t;  
    scanf("%d", &t);

    int results[t]; 

    for (int caseNum = 0; caseNum < t; caseNum++) {
        int n;
        scanf("%d", &n);

        int items[MAX_ITEMS] = {0};
        int uniqueTypes = 0;

        for (int i = 0; i < n; i++) {
            int itemType;
            scanf("%d", &itemType);

            if (items[itemType] == 0) {
                uniqueTypes++;
            }

            items[itemType]++;
        }

        results[caseNum] = uniqueTypes;
    }

    for (int caseNum = 0; caseNum < t; caseNum++) {
        printf("%d\n", results[caseNum]);
    }

    return 0;
}
