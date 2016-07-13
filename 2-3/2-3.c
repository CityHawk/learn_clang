#include <stdio.h>
#include <assert.h>
#include <string.h>

long htoi(char s[]);
int lettertonumber(char i);

int main() {
    assert(htoi("0xAB") == 171);
    assert(htoi("0Xabc") == 2748);
    assert(htoi("abc") == 2748);
    assert(htoi("FFF") == 4095);
    assert(htoi("0XA") == 10);
    assert(htoi("2") == 2);
    assert(htoi("0x2") == 2);
    assert(htoi("zog") == -1);
    assert(htoi("XXA") == -1);
    assert(htoi("deadbeef") == 3735928559 );
}

long htoi(char s[]) {
    int startsymbol,i,_t;
    long sum;
    sum = 0;

    if ((s[0] == '0') && (s[1] == 'x' || s[1] == 'X'))
        startsymbol = 2;
    else
        startsymbol = 0;


    for (i=startsymbol; i < strlen(s); ++i) {
        if ((_t = lettertonumber(s[i])) > 0 )
            sum = sum*16 + _t;
        else
            return -1;
    }
    /* printf("%ld\n", sum); */

    return sum;
}

int lettertonumber(char i) {
    if ( i >='A' && i <= 'F' )
        return i - 'A' + 10;
    else if ( i >='a' && i <= 'f' )
        return i - 'a' + 10;
    else if ( i>= '0' && i <= '9' )
        return i-'0';
    else
        return -1;
}

