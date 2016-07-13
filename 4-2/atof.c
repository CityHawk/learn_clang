#include <ctype.h>
#include <math.h>

double atof(char s[]) {
    double val, power, epower;
    int i, sign;
    int j, esign, eval;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        esign = (s[i] == '-') ? -1 : 1;

        if (!isdigit(s[i]))
            i++;

        for (eval = 0; isdigit(s[i]); i++) {
            eval = eval*10+(s[i] - '0');
        }

        epower = pow(10, esign*eval);
        return ( sign * val / power ) * epower;

    }

    return sign * val / power;
}
