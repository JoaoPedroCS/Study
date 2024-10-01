#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void countLetWorSent(string txt, float *w, float *l, float *s);
float evalVar(float wor, float let, float sent);

int main(void)
{
    float wor = 1;
    float let = 0;
    float sent = 0;
    string txt = get_string("Text: ");
    countLetWorSent(txt, &wor, &let, &sent);
    float index = evalVar(wor, let, sent);
    if (index < 1) {printf("Before Grade 1\n");}
    else if (index >= 16) {printf("Grade 16+\n");}
    else
    {
        printf("Grade %i\n", (int) round(index));
    }

}

void countLetWorSent(string txt, float *w, float *l, float *s)
{
    int length = strlen(txt);
    for (int i=0; i < length; i++)
    {
        if (isalpha(txt[i])) {*l +=1;}
        else if (txt[i] == ' ') {*w += 1;}
        else if (txt[i] == '.' || txt[i] == '!' || txt[i] == '?') {*s += 1;}
    }
}

float evalVar(float wor, float let, float sent)
{
    float L = (let / wor) * 100;
    float S = (sent / wor) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}
