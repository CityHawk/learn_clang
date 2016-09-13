/* itoa:  convert n to characters in s */
void itoa(int n, char *s)
{
    void reverse(char *);
    int sign;
    char *start;
    start = s;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    do {       /* generate digits in reverse order */
        *s = n % 10 + '0';   /* get next digit */
        s++;
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0) {
        *s = '-';
        s++;
    }
    *s = '\0';
    reverse(start);
}
