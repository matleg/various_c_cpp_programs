#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
from : https://stackoverflow.com/questions/5580761/why-use-double-indirection-or-why-use-pointers-to-pointers/25110045

example of use:
- you have a pointer and its value is an address.
- you want to change that address.
- you can do pointer1 = pointer2, and pointer1 would now have the address of pointer2.
- but you want a function to do that for you, and you want the result 
  to persist after the function is done, you need a new pointer3 just to point to pointer1,
  and pass pointer3 to the function.
*/

int wordsinsentence(char **x)
{
    int w = 0;
    while (*x)
    {
        w += 1;
        x++;
    }
    return w;
}

int wordsinmono(char ***x)
{
    int w = 0;
    while (*x)
    {
        w += wordsinsentence(*x);
        x++;
    }
    return w;
}

int wordsinbio(char ****x)
{
    int w = 0;
    while (*x)
    {
        w += wordsinmono(*x);
        x++;
    }
    return w;
}


int main(void)
{
    char *word;
    char **sentence;
    char ***monologue;
    char ****biography;

    //fill data structure
    word = malloc(4 * sizeof *word);
    strcpy(word, "abc");

    printf("word string: %s\n", word);

    sentence = malloc(4 * sizeof *sentence); 
    sentence[0] = word;
    sentence[1] = word;
    sentence[2] = word;
    sentence[3] = NULL;

    printf("word sentence: %s %s %s %s \n", *sentence, *sentence+1, *sentence+2, *sentence+3);
    printf("word sentence: %s %s %s %s \n", *sentence, sentence[1], sentence[2], sentence[3]);

    monologue = malloc(4 * sizeof *monologue);
    monologue[0] = sentence;
    monologue[1] = sentence;
    monologue[2] = sentence;
    monologue[3] = NULL;

    biography = malloc(4 * sizeof *biography);
    biography[0] = monologue;
    biography[1] = monologue;
    biography[2] = monologue;
    biography[3] = NULL;


    printf("total words in my bio: %d\n", wordsinbio(biography));

    free(biography);
    free(monologue);
    free(sentence);
    free(word);
}