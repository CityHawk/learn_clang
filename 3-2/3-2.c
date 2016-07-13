#include <stdio.h>
#include <string.h>

void escape(char s[],char t[]) {
    int i,j;
    for (i=0, j=0; s[i]!='\0';i++) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;

            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;

            case '\a':
                t[j++] = '\\';
                t[j++] = 'a';
                break;

            case '\b':
                t[j++] = '\\';
                t[j++] = 'b';
                break;

            case '\f':
                t[j++] = '\\';
                t[j++] = 'f';
                break;

            case '\r':
                t[j++] = '\\';
                t[j++] = 'r';
                break;

            case '\v':
                t[j++] = '\\';
                t[j++] = 'v';
                break;

            default:
                t[j++] = s[i];
                break;
        }
    }
    t[j]=s[i];
}
void unescape(char s[], char t[]) {
    int i,j;

    for (i = 0, j=0; s[i] != '\0'; i++) {
        if (s[i]=='\\') {
            switch (s[i+1]) {
                case 'n':
                    t[j++] = '\n';
                    i++;
                    break;
                case 't':
                    t[j++] = '\t';
                    i++;
                    break;
                case 'a':
                    t[j++] = '\a';
                    i++;
                    break;
                case 'b':
                    t[j++] = '\b';
                    i++;
                    break;
                case 'f':
                    t[j++] = '\f';
                    i++;
                    break;
                case 'r':
                    t[j++] = '\r';
                    i++;
                    break;
                case 'v':
                    t[j++] = '\v';
                    i++;
                    break;
                default:
                    t[j++] = '\\';
                    break;
            }
        } else {
            t[j++] = s[i];
        }
    }

    t[j]=s[i];
}
int main() {
    char s[] = "Hello\nworld\tfoo\a bar \b baz \f moo \r xyz \v \\";
    char t[strlen(s)];
    char t1[strlen(s)];
    escape(s,t);
    printf("%s\n", s);
    printf("%s\n", t);
    unescape(t,t1);
    printf("%s\n", t1);
}
