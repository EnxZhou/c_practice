#include<stdio.h>

char * gets(char *s);
void echo();
void good_echo();

int main(void){
    // echo();
    good_echo();
    return 0;
}

char *gets(char *s)
{
    int c;
    char *dest = s;
    while((c = getchar())!='\n' && c!=EOF)
        *dest++=c;
    if (c == EOF && dest == s)
        return NULL;
    *dest++ = '\0';
    return s;
}

void echo()
{
    char buf[8];
    gets(buf);
    puts(buf);
}

void good_echo(){
    char buf[12];
    while (1){
        char *p = fgets(buf,12,stdin);
        if (p==NULL)
        {
            break;
        }
        printf("%s",p);
    }
    return;
}