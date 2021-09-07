#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// f(x) = mx + b
typedef struct SlopeIntercept {
    // The slope of the equation.
    double m;

    // The y-intercept.
    double b;
} SlopeIntercept;

void print_problem(SlopeIntercept a, SlopeIntercept b) {
    printf(
        "Solve this system of equations\n"
        "\ty = %fx + %f\n"
        "\ty = %fx + %f\n"
        ,
        a.m, a.b,
        b.m, b.b
    );
}

char* rm_trailing_zeroes(double n) {
    char buf[50];
    sprintf(buf, "%f", n);
    printf("%s\n", buf);

    char buf2[strlen(buf)];

    int i;
    for (i = strlen(buf); i != 0; i--) {
        printf("i = %d\n", i);
        if (buf[i] == '\0')
            continue;
        if (buf[i] != '0')
            break;
    }

    if (buf[i] == '.')
        i--;

    printf("i = %d\n\n", i);
    for (int j = 0; j < i + 1; j++) {
        printf("j = %d\n", j);
        buf2[j] = buf[j];
    };
    printf("\n");
    printf("%s\n", buf2);

    return NULL;
}

double find_x(SlopeIntercept a, SlopeIntercept b) {
    return (b.b - a.b) / (a.m - b.m);
}

int main(int argc, char* argv[]) {
    SlopeIntercept a = {.m = 2, .b = 4};
    SlopeIntercept b = {.m = 4, .b = 2};

    print_problem(a, b);
    double x = find_x(a, b);
    printf("\nThe x is %f\n\n", x);

    rm_trailing_zeroes(1);
}