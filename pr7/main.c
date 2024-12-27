#include "./src/include/function.h"
#include "./src/include/color.h"

#include <stdio.h>
#include <conio.h>

int main() {
    printf(BLK WHTB"=== NON-LINEAR EQUATION SOLVER ===\n\n" CRESET
        "This program calculates all roots of nonlinear equations in [a, b] interval.\n");

    do {
        double a = 0.0, b = 0.0;
        double (*functionChoice)(double, double) = 0;
        double (*derivativeChoice)(double, double) = 0;

        unsigned char choiceFunction = getChoice("\n---> Choose the equation:\n"
                                               BBLK "1. " CRESET "cos(t / x) - 2 * sin(1 / x) + 1 / x\n"
                                               BBLK "2. " CRESET "sin(ln(x)) - cos(ln(x)) + t * ln(x)\n",
                                               '1', '2');
        switch (choiceFunction) {
            case '1':
                printf("\nChoice: " BYEL "1\n" CRESET);
                break;
            case '2':
                printf("\nChoice: " BYEL "2\n" CRESET);
                break;
            default:
                printf(ERR_MSG "Invalid input.\n");
                break;
        }
        
        unsigned char choiceMethod = getChoice("\n---> Choose the solving method:\n"
                                             BBLK "1. " CRESET "Half division method\n"
                                             BBLK "2. " CRESET "Newton method\n",
                                             '1', '2');
        switch (choiceMethod) {
            case '1':
                printf("\nChoice: " BYEL "1\n" CRESET);
                break;
            case '2':
                printf("\nChoice: " BYEL "2\n" CRESET);
                break;
            default:
                printf(ERR_MSG "Invalid input.");
                break;
        }
        double t = getDouble("\nEnter t:", conditionT, MIN_T, MAX_T);
        printf("\n---> Enter intervals of x (from a to b):\n");
        switch (choiceFunction) {
            case '1':
                functionChoice = equationCos;
                derivativeChoice = equationDerivativeCos;
                do {
                    a = getDouble("\nEnter a:", conditionIntervalCos, MIN_RANGE, MAX_RANGE);
                    b = getDouble("\nEnter b:", conditionIntervalCos, MIN_RANGE, MAX_RANGE);
                    if (a >= b) {
                        printf(ERR_MSG "Value of a must be less the value of b.\n");
                        pressToExit();
                    }
                } while (a >= b);
                break;
            case '2':
                functionChoice = equationSin;
                derivativeChoice = equationDerivativeSin;
                do {
                    a = getDouble("\nEnter a:", conditionIntervalSin, 1e-15, MAX_RANGE);
                    b = getDouble("\nEnter b:", conditionIntervalSin, 1e-15, MAX_RANGE);
                    if (a >= b){
                        printf(ERR_MSG "a must be less than b. Press Enter to try again, Q to exit...\n");
                        pressToExit();
                    }
                } while (a >= b);
                break;
            default:
                printf(ERR_MSG "Invalid input.");
                break;
        }
        double epsilon = getDouble("\nEnter calculation precision;", conditionEpsilon, MIN_EPS, MAX_EPS);
        calculation(functionChoice, derivativeChoice, a, b, t, epsilon, choiceMethod);

        printf("\nPress Enter to restart, any key to exit...\n");
    } while (getch() == 13 && (clearScreen(), 1));
    return 0;
}