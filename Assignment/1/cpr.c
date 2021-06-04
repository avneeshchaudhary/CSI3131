/* ------------------------------------------------ ------------
File: cpr.c

Last name: Rodger Retanal
Student number: 300052309

Description: This program contains the code for creation
 of a child process and attach a pipe to it.
         The child will send messages through the pipe
         which will then be sent to standard output.

Explanation of the zombie process
(point 5 of "To be completed" in the assignment):

        (please complete this part);

------------------------------------------------------------- */
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

#define READ_END 0
#define WRITE_END 1

/* Prototype */
void createChildAndRead(int);

/* -------------------------------------------------------------
Function: main
Arguments:
        int ac	- number of command arguments
        char **av - array of pointers to command arguments
Description:
        Extract the number of processes to be created from the
        Command line. If an error occurs, the process ends.
        Call createChildAndRead to create a child, and read
        the child's data.
-------------------------------------------------- ----------- */

int main(int ac, char **av) {
  int processNumber;

  if (ac == 2) {
    if (sscanf(av[1], "%d", &processNumber) == 1) {
      createChildAndRead(processNumber);
    } else
      fprintf(stderr, "Cannot translate argument\n");
  } else
    fprintf(stderr, "Invalid arguments\n");

  return 0;
}

/* ------------------------------------------------ -------------
Function: createChildAndRead
Arguments:
        int prcNum - the process number
Description:
        Create the child, passing prcNum-1 to it. Use prcNum
        as the identifier of this process. Also, read the
        messages from the reading end of the pipe and sends it to
        the standard output (df 1). Finish when no data can
        be read from the pipe.
-------------------------------------------------- ----------- */

void createChildAndRead(int prcNum) {
  if (prcNum <= 1) {
    printf("Process 1 begins\n");
    fflush(stdout);
    sleep(5);
    printf("Process 1 ends\n");
    fflush(stdout);
    return;
  }

  printf("Process %d begins\n", prcNum);
  fflush(stdout);

  int fd[2];

  if ((pipe(fd)) == -1) {
    fprintf(stderr, "Pipe Failed\n");
    return;
  }

  pid_t pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Fork Failed\n");
    return;
  }

  if (pid > 0) {
    close(fd[WRITE_END]);

    char buff;
    while (read(fd[READ_END], &buff, 1) > 0) {
      write(STDOUT_FILENO, &buff, 1);
    }

    close(fd[READ_END]);

    sleep(5);
    printf("Process %d ends\n", prcNum);
    fflush(stdout);
  } else {
    close(fd[READ_END]);
    dup2(fd[WRITE_END], STDOUT_FILENO);

    char prcStr[5];
    sprintf(prcStr, "%d", prcNum - 1);

    char *args[3] = {"cpr", prcStr, NULL};
    execvp("./cpr", args);
  }
}
