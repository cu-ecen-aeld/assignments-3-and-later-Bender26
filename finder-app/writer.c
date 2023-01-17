#include <stdio.h>
#include <stdint.h>
#include <syslog.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    openlog(NULL,0,LOG_USER);
    if(argc != 3)
    {
        syslog(LOG_ERR, "Invalid Number of arguments: %d", argc - 1);
        return 1;
    }
    FILE *file1 = NULL;
    file1 = fopen(argv[1], "w");
    if(file1== NULL)
    {
        syslog(LOG_ERR,"Error: %s", strerror(errno));
        fclose(file1);
        return 1;
    }
    fprintf(file1,"%s", argv[2]);
    fclose(file1);
    syslog(LOG_DEBUG,"Writing %s to %s", argv[2], argv[1]);
    
    return 0;

}