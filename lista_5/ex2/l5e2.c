#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_STATE 1
#define INPUT_LINE_SIZE 1026 // one line can have until 1024 chars besides the '\n' and '\0' last characters.

int isFinalState(int state)
{
    if ((state >= 2 && state <= 9) || (state >= 11 && state <= 13))
        return 1;
    else
        return 0;
}

int getCharColunIndex(char character)
{
    if (character == ' ')
        return 0;
    else if (character >= 'a' && character <= 'z')
        return (character - 96);
    else if (character >= '0' && character <= '9')
        return (26 + (character - 47));
    else if (character == '.')
        return 37;
    else if (character == '-')
        return 38;
    else if (character == '\n')
        return 39;
    else
        return 40; // other
}

int getNextState(int currentState, char character, int edges[][41])
{
    int index = getCharColunIndex(character);
    int result = edges[currentState][index];
    return result;
}

void processLexeme(char *address, int length, int finalState)
{
    if (length == 0)
        return;
    char temp = address[length];
    char nextChar = address[1];
    address[length] = '\0';
    // printf("%s\n", address);

    if (finalState == 2 || finalState == 4)
    {
        printf("%s ID \n", address);
    }
    else if (finalState == 3)
    {
        printf("IF\n");
    }
    else if (finalState == 5 || finalState == 9 || finalState == 13)
    {
        printf("%s error\n", address);
    }
    else if (finalState == 6 || finalState == 8)
    {
        printf("%s REAL\n", address);
    }
    else if (finalState == 7)
    {
        printf("%s NUM\n", address);
    }
    else if (finalState == 11)
    {
        // address[length-1] = '\0';
        printf("%s comment\n", address);
        // address[length-1] ='\n';
    }
    else if (finalState == 12)
    {
        address[length - 1] = '\0';
        printf("%swhite space\n", address);
        address[length - 1] = '\n';
    }

    address[length] = temp;
}

int main(void)
{

    int edges[][41] = {/*input characters
                      B   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o   p   q   r   s   t   u   v   w   x   y   z   0   1   2   3   4   5   6   7   8   9   .   -  \n   O*/    
        /*state 0*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        /*state 1*/  {12, 4,  4,  4,  4,  4,  4,  4,  4,  2,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  5,  9, 13, 13},
        /*state 2*/  {0,  4,  4,  4,  4,  4,  3,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0},
        /*state 3*/  {0,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0},
        /*state 4*/  {0,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0},
        /*state 5*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  0,  0,  0,  0},
        /*state 6*/  {0,  0,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  0,  0,  0,  0},
        /*state 7*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  8,  0,  0,  0},
        /*state 8*/  {0,  0,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  0,  0,  0,  0},
        /*state 9*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10,  0,  0},
        /*state 10*/ {0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 11,  0},
        /*state 11*/ {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        /*state 12*/ {12, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        /*state 13*/ {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},

        /*obs: B stands for blank and O stands for other*/
    };

    char inputLine[INPUT_LINE_SIZE];
    char arrayDeEntradas[90][INPUT_LINE_SIZE];
    for (int i = 0; i < 90; i++)
    {
        for (int j = 0; j < INPUT_LINE_SIZE; j++)
        {
            arrayDeEntradas[i][j] = '\0';
        }
    }
    int indexDePalavras = -1;
    char *entradaAnterior;

    while (fgets(inputLine, INPUT_LINE_SIZE, stdin) != NULL)
    {

        entradaAnterior = inputLine;
        indexDePalavras++;
        int lastFinalState = 0;
        int currentState = INITIAL_STATE;

        int acceptingCursor = 0;
        int readingCursor = 0;

        char *baseAddress = inputLine;
        int textSize = 0;
        int teste = strlen(inputLine);
        while (textSize < teste)
        {
            char atualCaractere = baseAddress[readingCursor];
            arrayDeEntradas[indexDePalavras][readingCursor] = atualCaractere;
            readingCursor++;
            textSize++;
        }
        if (*inputLine == '\n' && *entradaAnterior == '\n')
        {
            for (int i = 0; i < 90; i++)
            {
                lastFinalState = 0;
                currentState = INITIAL_STATE;
                acceptingCursor = 0;
                readingCursor = 0;
                baseAddress = arrayDeEntradas[i];
                char actual[INPUT_LINE_SIZE];
                for (int k = 0; k < INPUT_LINE_SIZE; k++)
                {
                    actual[k] = '\0';
                }
                
                while(1)
                {

                        // reading next character:
                        char currentChar = baseAddress[readingCursor];
                        actual[readingCursor] = currentChar;
                        readingCursor++;

                        // changing state based on read character:
                        currentState = getNextState(currentState, currentChar, edges);

                        if (currentState == 0)
                        { // the automaton transition function is not defined for the current state-input pair. So it may have recognized some token.

                            if (*baseAddress == '\0'|| *baseAddress == '\n')
                                break; // finished processing line

                            if(actual[acceptingCursor-1] == '\n')
                                actual[acceptingCursor-1] = '\0';

                            processLexeme(actual, acceptingCursor, lastFinalState);
                            baseAddress += acceptingCursor;
                            acceptingCursor = 0;
                            readingCursor = 0;
                            lastFinalState = 0;
                            currentState = INITIAL_STATE;

                            for (int k = 0; k < INPUT_LINE_SIZE; k++)
                            {
                                actual[k] = '\0';
                            }
                        }
                        else if (isFinalState(currentState))
                        { // the automaton is now recognizing a new substring (lexeme).

                            lastFinalState = currentState;
                            acceptingCursor = readingCursor;
                        }
                }
            }
        }
    }

    return 0;
}