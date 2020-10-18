#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 40

char infix[SIZE];
char postfix[SIZE];
//last index of postfix expression
int pIndex = -1;
//stack used for infix to postfix conversion
char stack[SIZE];
int top = -1;
//stack used for evaluation of postfix expression
int evStack[SIZE];
int evTop = -1;
//pointer array of intergers holding the values of variables in the expression
int* values[26];

void displayStack();
int priority(char);
void infixToPostfix();
void displayPostfix();
void getValues();
int getIndex(char);
int evaluatePostfix();

int main(){
    int i;
    //initialise all elements of pointer array to null
    for(i = 0; i < 26; i++){
        values[i] = NULL;
    }
    //input the infix expression
    printf("Enter the infix expression: \n");
    scanf("%s", infix);
    //convert infix to postfix expression
    infixToPostfix();
    //display postfix expression
    displayPostfix();
    //get values of each operands
    getValues();
    //evaluate the result and display
    int result = evaluatePostfix();
    printf("\nResult = %d\n", result);
}

//convert infix expression to postfix expression
void infixToPostfix(){
    int i;
    strcat(infix, ")");
    stack[++top] = '(';
    for(i = 0; i < strlen(infix); i++){
        char ch = infix[i];
        //check if the element is an operand
        if(isalpha(ch)){
            postfix[++pIndex] = ch;
        }
        //check if its a closing bracket
        else if(ch == ')'){
            //pop untill opening bracket is found
            char popped = stack[top--];
            while(popped != '('){
                postfix[++pIndex] = popped;
                //stack[top--] will pop an element from stack and return it
                popped = stack[top--];
            }
        }
        //check if its an opening bracket
        else if(ch == '('){
            //simply push the element to stack
            stack[++top] = ch;
        }
        //otherwise it has to be an operator 
        else{
            if(priority(ch) > priority(stack[top])){
                //incoming operator is of high priority
                stack[++top] = ch;
            }
            else{
                //incoming operator is of low or same priority
                while(priority(ch) <= priority(stack[top])){
                    postfix[++pIndex] = stack[top--];
                }
                stack[++top] = ch;
            }
        }
    }
}

//returns the result after evaluating postfix expression
int evaluatePostfix(){
    //add '#' at the end of expression to denote the end of expression
    postfix[++pIndex] = '#';
    int i;
    for(i = 0; i <= pIndex; i++){
        char ch = postfix[i];
        //check if the element is an operand
        if(isalpha(ch)){
            //get the value of operand from values array
            int num = *values[getIndex(ch)];
            //push the number to the evaluation stack
            evStack[++evTop] = num;
        }
        //checks for the end of expression
        else if(ch == '#'){
            return evStack[evTop]; 
        }
        //otherwise its an operator
        else{
            int firstPop = evStack[evTop--];
            int secondPop = evStack[evTop--];
            //do the respective operation on popped elements and push the new result into the stack
            switch(ch){
                case '+':
                    evStack[++evTop] = secondPop + firstPop;
                    break;
                case '-':
                    evStack[++evTop] = secondPop - firstPop;
                    break;
                case '*':
                    evStack[++evTop] = secondPop * firstPop;
                    break;
                case '/':
                    evStack[++evTop] = secondPop / firstPop;
                    break;
                case '^':
                    evStack[++evTop] = pow(secondPop, firstPop);
            }
        }
    }
}

//input the value of an operand and stores it in an array
void getValues(){
    int i;
    for(i = 0; i <= pIndex; i++){
        char ch = postfix[i];
        if(isalpha(ch)){
            //returns a number between 0 and 25 for each letter
            int index = getIndex(ch);
            //check if the value has not been inputted
            if(values[index] == NULL){
                //input the value of operand
                values[index] = (int*)malloc(sizeof(int));
                printf("Enter the value of %c:\n", ch);
                scanf("%d", values[index]);
            }
        }
    }
}

//returns a unique number between 0 and 25 for an alphabet irrespective of case
int getIndex(char ch){
    int index;
    if(islower(ch)){
        //ascii of a is 97
        index = ch - 97;
    }
    else{
        //ascii of A is 65
        index = ch - 65;
    }
    return index;
}

//returns the priority of an operator
int priority(char element){
    //higher priority operator returns higher number
    switch(element){
        //any operator can be placed on top of '(' in stack so set it has lowest priority
        case '(':
            return 0;
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        //no operator can be placed on top of '^' in stack so it has highest priority
        case '^':
            return 3;
        default:
            return -1;
    }
}


void displayPostfix(){
    printf("\nPostfix expression:\n");
    //display the postfix expression
    int i;
    for(i = 0; i <= pIndex; i++){
        printf("%c", postfix[i]);
    }
    printf("\n\n");
}


// void displayStack(){
//     if(evTop == -1){
//         printf("Empty stack\t");
//         return;
//     }
//     int i;
//     for(i = 0; i <= evTop; i++){
//         printf("%d ", evStack[i]);
//     }
//     printf("\n");
// }











