// Program to perform postfix evaluation.
#include<stdio.h> //header files
#include<ctype.h>
#include<math.h>

#define MAX 20

void push(int e); //function prototypes
int pop();
int a[MAX], top = -1; //global declarations

int main(void)
{
    char post[MAX], ch;
    int i, op1, op2, result;

    printf("Program to evaluate postfix expression\n");
    printf("Enter the postfix expression: ");
    scanf("%s", post);

    for (i = 0; post[i] != '\0'; i++)
    {
        ch = post[i]; //take one symbol from the expression
        if (isdigit(ch)) //check if it is an operand
            push(ch - '0');
        else //else if it is an operator
        {
            //pop 2 operands from the stack
            op2 = pop();
            op1 = pop();
            switch (ch) //perform the operation depending upon the operator
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '^':
                result = pow(op1, op2);
                break;
            case '%':
                result = op1 % op2;
                break;
            default:
                printf("Invalid character\n");
            }
            push(result); //push the result onto the stack
        }
    }
    printf("Result of the above expression is %d\n", pop()); /*pop the final result from the stack*/
    return 0;
}

/*function to push*/
void push(int e)
{
    ++top;
    a[top] = e;
}

/*function to pop*/
int pop()
{
    int ele;
    ele = a[top];
    --top;
    return (ele);
}