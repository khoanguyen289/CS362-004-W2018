#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    return (rand() % (127 - 32 + 1) + 32); // get a random ascii value between Space and Del
}

char *inputString()
{
    char *str = malloc(6 * sizeof(char));
    int i;

    // this takes too long on flip
    // for (i = 0; i < 5; i++) {
    //     str[i] = ((rand() % (122 - 97) + 1) + 97); // get a random ascii value between a and z
    // }

    // conditionally randomize based on position of the characters so the program can run within 5 minutes on flip
    for (i = 0; i < 5; i++) {
        if (i == 0 || i == 2 || i == 4) {
          str[i] = ((rand() % (118 - 112) + 1) + 112); // get a random ascii value between p and v
        } else { // i = 1 || i = 3
          str[i] = ((rand() % (104 - 98) + 1) + 98); // get a random ascii value between b and h
        }
    }
    str[5] = '\0';
    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
