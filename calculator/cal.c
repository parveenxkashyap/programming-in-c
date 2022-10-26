// import module
#include <stdio.h>
#include <float.h>

int main() {
    char op;
    double a, b, res;

    // Read 
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &op);

    // Read two numbers
    printf("Enter two operands: ");
    scanf("%lf %lf", &a, &b);
    
     // switch-case
    switch (op) {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
         res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    default:
        printf("Error! Incorrect Operator Value\n");
        res = -DBL_MAX;
    }
    if(res!=-DBL_MAX)
      printf("%.2lf", res);
    
    return 0;
}