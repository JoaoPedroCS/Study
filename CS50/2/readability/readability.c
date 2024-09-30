#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void countLetWorSent(string txt, int wor, int let, int sent);
void evalVar(string txt, int wor, int let, int sent);

int main(void)
{
    string txt = get_string("Text: ");
}

void countLetWorSent(string txt, int wor, int let, int sent)
{
    int length = strlen(txt);
    for (int i=0; i < length; i++)
    {
        if (isalpha(txt[i])) {let +=1;}
        else if (txt[i] == ' ') {wor += 1;}
        else if (txt[i] == '.' || txt[i] == '!' || txt[i] == '?') {sent += 1;}
    }
}

void evalVar(string txt, int wor, int let, int sent)
{
    
}
