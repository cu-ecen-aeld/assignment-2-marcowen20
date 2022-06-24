#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Please specify writefile and writestr");
        exit(1);
    } else {
        FILE* file = fopen(argv[1], "w");
        size_t size = strlen(argv[2]);
        char *writeStr = malloc(size);
        if(writeStr == NULL) {
            syslog(LOG_USER | LOG_ERR, "Cannot allocate memory for write string");
        } else if(file == NULL) {
            syslog(LOG_USER | LOG_DEBUG, "Cannot open file %s for writing", argv[1]);
            exit(1);
        } else {
            syslog(LOG_USER | LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
            strcpy(writeStr, argv[2]);
            fprintf(file, "%s", writeStr);
        }
        fclose(file);
        free(writeStr);
    }
}
