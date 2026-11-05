#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int smallestPrimeFactor(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return i;
    }
    return n;
}

int largestProperDivisor(int n) {
    if (n <= 1)
        return n;
    int spf = smallestPrimeFactor(n);
    if (spf == n)
        return 1;
    return n / spf;
}

void primeFactor(int n) {
    printf("%d = ", n);
    int temp = n;
    int first = 1;
    for (int i = 2; i * i <= temp; i++) {
        int count = 0;
        while (temp % i == 0) {
            count++;
            temp /= i;
        }
        if (count > 0) {
            if (!first)
                printf(" * ");
            printf("%d^%d", i, count);
            first = 0;
        }
    }
    if (temp > 1) {
        if (!first)
            printf(" * ");
        printf("%d^1", temp);
    }
    printf("\n");
}

int findNearestPerfect(int x) {
    int perfects[] = {6, 28, 496, 8128};
    int numPerfects = sizeof(perfects) / sizeof(perfects[0]);
    int nearest = perfects[0];
    int minDiff = abs(x - perfects[0]);
    for (int i = 1; i < numPerfects; i++) {
        int diff = abs(x - perfects[i]);
        if (diff < minDiff || (diff == minDiff && perfects[i] < nearest)) {
            minDiff = diff;
            nearest = perfects[i];
        }
    }
    return nearest;
}

int main() {
    int n;
    printf("Enter n (>= 2): ");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Invalid input!\n");
        return 1;
    }
    
    printf("Prime factor:\n");
    primeFactor(n);
    
    int largestDiv = largestProperDivisor(n);
    printf("Largest proper divisor of %d is: %d\n", n, largestDiv);
    
    int nearestPerfect = findNearestPerfect(largestDiv);
    printf("The perfect number nearest to %d is: %d\n", largestDiv, nearestPerfect);
    
    return 0;
}
