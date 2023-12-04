#include <stdio.h>
#include <math.h>

int countDigitOne(int n) {

    int count = 0;
    int factor = 1;
     int i = 1;

 while (i <= n) {
int divider = i * 10;
count += (n / divider) * factor + fmin(fmax(n % divider - i + 1, 0), factor);
i *= 10;
factor *= 10;
 }
 return count;

}
int main() {
 int n;
 
// Get user input
printf("Enter a non-negative integer (n): ");
scanf("%d", &n);
 
// Validate input
    if (n < 0) {
           printf("Please enter a non-negative integer.\n");
           return 1;
    }

 // Calculate and display result
 
 int result = countDigitOne(n);
 printf("The total number of digit 1 in numbers up to %d is: %d\n", n, result);
 return 0;
 
}
