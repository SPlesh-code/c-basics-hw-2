#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MESSAGE_SIZE 256

typedef struct {
    char date[11];
    char time[13];
    char status[6];
    char message[MESSAGE_SIZE];
} Log;

int main()
{
    Log *logs = NULL;
    int count = 0;
    char input[MESSAGE_SIZE];

    while (1)
    {
        int status;

        printf("\nSet status of log 1- INFO, 2- ERROR: ");
        scanf("%d", &status);
        getchar();

        if (status != 1 && status != 2)
        {
            printf("Wrong status!\n");
            continue;
        }

        printf("Set log message: ");
        fgets(input, MESSAGE_SIZE, stdin);

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "-") == 0)
            break;

        Log *temp = realloc(logs, (count + 1) * sizeof(Log));

        if (temp == NULL)
        {
            printf("Memory allocation error!\n");
            free(logs);
            return 1;
        }

        logs = temp;

        time_t current_time = time(NULL);
        struct tm *local = localtime(&current_time);

        strftime(logs[count].date, sizeof(logs[count].date),
                 "%Y-%m-%d", local);

        strftime(logs[count].time, sizeof(logs[count].time),
                 "%H:%M:%S", local);

        if (status == 1)
            strcpy(logs[count].status, "INFO");
        else
            strcpy(logs[count].status, "ERROR");

        strcpy(logs[count].message, input);

        count++;
    }

    printf("\n========== SERVER LOG ==========\n");

    for (int i = 0; i < count; i++)
    {
        printf("%s | %s | %s - %s\n",
               logs[i].date,
               logs[i].time,
               logs[i].status,
               logs[i].message);
    }

    printf("================================\n");

    free(logs);

    return 0;
}
