#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "shell.h"
int mai(void)
{
        char **command;
        char *sentence;
        int i = 0;
        sentence = "hello world , i'm falcon and my real name is soufiane ";
        command = split(sentence);
        while (command[i])
        {
                printf("%s",command[i]);
                i++;
                printf("\n");
        }
        return (0);


}
