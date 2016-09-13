#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
/* minprintf:  minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap;   /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                char _s[10];
                int i = 0;
                itoa(ival, _s);
                while (_s[i]) {
                    putchar(_s[i++]);
                }
                /* printf("Should I fail"); */
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);   /* clean up when done */
}

int main(int argc, char *argv[]) {
    minprintf("String: %s\n", "MyString");
    minprintf("Integer: %d\n", 51234);
    return 0;
}
