#include "types.h"
#include "stat.h"
#include "user.h"

static volatile int sink = 0;
static void burn(int n){ for(int i=0;i<n;i++) sink += i; }

int main(int argc, char **argv){
  int N = 3;
  int tickets[3] = {10, 20, 30};
  int TICKS = 1000;
  int pids[3];
  int i, j;

  printf(1, "Starting lottery scheduling experiment...\n");

  for(i = 0; i < N; i++) {
    int pid = fork();
    if(pid == 0) {
      settickets(tickets[i]);
      int count = 0;
      for(j = 0; j < TICKS; j++) {
        count++;
        if(j % 100 == 0) {
          sleep(1);
        }
      }
      printf(1, "PID %d with %d tickets ran %d iterations\n", getpid(), tickets[i], count);
      exit();
    } else {
      pids[i] = pid;
    }
  }

  for(i = 0; i < N; i++) {
    wait();
  }

  printf(1, "Experiment complete.\n");
  exit();
}
