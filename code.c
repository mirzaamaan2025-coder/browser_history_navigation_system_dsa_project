#include <stdio.h>
#include <string.h>

#define MAX 100

char backStack[MAX][100];
char forwardStack[MAX][100];

int backTop = -1;
int forwardTop = -1;

char currentPage[100];

void pushBack(char url[]) {
    if (backTop == MAX - 1) {
        printf("Back history is full.\n");
        return;
    }

    backTop++;
    strcpy(backStack[backTop], url);
}

char* popBack() {
    if (backTop == -1)
        return NULL;

    return backStack[backTop--];
}

void pushForward(char url[]) {
    if (forwardTop == MAX - 1) {
        printf("Forward history is full.\n");
        return;
    }

    forwardTop++;
    strcpy(forwardStack[forwardTop], url);
}

char* popForward() {
    if (forwardTop == -1)
        return NULL;

    return forwardStack[forwardTop--];
}

void clearForward() {
    forwardTop = -1;
}

void visit(char url[]) {
    pushBack(currentPage);
    strcpy(currentPage, url);
    clearForward();

    printf("\nVisited: %s\n", currentPage);
}

void back(int steps) {
    while (steps > 0 && backTop != -1) {
        pushForward(currentPage);
        strcpy(currentPage, popBack());
        steps--;
    }

    printf("\nCurrent Page: %s\n", currentPage);
}

void forward(int steps) {
    while (steps > 0 && forwardTop != -1) {
        pushBack(currentPage);
        strcpy(currentPage, popForward());
        steps--;
    }

    printf("\nCurrent Page: %s\n", currentPage);
}

void displayBackHistory() {
    int i;

    printf("\n===== BACK HISTORY =====\n");

    if (backTop == -1) {
        printf("Empty\n");
        return;
    }

    for (i = backTop; i >= 0; i--)
        printf("%s\n", backStack[i]);
}

void displayForwardHistory() {
    int i;

    printf("\n===== FORWARD HISTORY =====\n");

    if (forwardTop == -1) {
        printf("Empty\n");
        return;
    }

    for (i = forwardTop; i >= 0; i--)
        printf("%s\n", forwardStack[i]);
}

int main() {
    int choice, steps;
    char url[100];

    printf("===== Browser History and Navigation System =====\n");

    printf("\nEnter homepage: ");
    scanf("%s", currentPage);

    do {
        printf("\n1. Visit New Website\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Display Back History\n");
        printf("5. Display Forward History\n");
        printf("6. Display Current Page\n");
        printf("7. Clear Forward History\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visit(url);
                break;

            case 2:
                printf("Enter number of steps: ");
                scanf("%d", &steps);
                back(steps);
                break;

            case 3:
                printf("Enter number of steps: ");
                scanf("%d", &steps);
                forward(steps);
                break;

            case 4:
                displayBackHistory();
                break;

            case 5:
                displayForwardHistory();
                break;

            case 6:
                printf("\nCurrent Page: %s\n", currentPage);
                break;

            case 7:
                clearForward();
                printf("\nForward history cleared.\n");
                break;

            case 8:
                printf("\nExiting Browser History System...\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}
