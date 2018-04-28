#include <stdio.h>

void *shell(int a, int b, int c) 
{
        if ((a == 0xffffffff) && (b == 0xdeadbeef) && (c == 0xffffffff)) {
                system("/bin/bash -ip");
        }
        return NULL;
}

void *vuln(char* buf) 
{
        char buffer[888];
        strcpy(buffer, buf);
        return NULL;
}

int main(int argc, char** argv) 
{
        if ( argc < 2 ) { fprintf(stderr, "Uso: %s AAAAAAAAAAA...\n", argv[0]);
                exit(-1); }
        vuln(argv[1]);
        return 0;
}
