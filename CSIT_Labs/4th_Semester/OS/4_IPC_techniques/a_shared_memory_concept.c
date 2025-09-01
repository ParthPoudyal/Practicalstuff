// Note: Run in Linux

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

#define MAX 10

// Structure for message queue
struct mesg_buffer
{
    long mesg_type;
    char mesg_text[100];
} message;

key_t key;
int msgid;

void sendmsg(key_t key)
{
    // msgget creates a message queue and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT); // 0666 is permission
    if (msgid == -1)
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    message.mesg_type = 1;

    printf("Write Data: ");
    fgets(message.mesg_text, MAX, stdin);

    // msgsnd to send message
    if (msgsnd(msgid, &message, sizeof(message.mesg_text), 0) == -1)
    {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Data sent is: %s\n", message.mesg_text);
}

void getmsg()
{
    // msgrcv to receive message
    if (msgrcv(msgid, &message, sizeof(message.mesg_text), 1, 0) == -1)
    {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("Data received is: %s\n", message.mesg_text);

    // Destroy the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    // Ensure the file exists before calling ftok
    FILE *file = fopen("progfile", "a"); // create if not exists
    if (file == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fclose(file);

    // ftok to generate unique key
    key = ftok("progfile", 65);
    if (key == -1)
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    sendmsg(key);
    getmsg();

    printf("This code was executed by Parth Poudyal\n");

    return 0;
}
