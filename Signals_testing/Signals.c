#include<stdio.h>
#include<signal.h>
#include<unistd.h>
int count=0;
void sig_handler(int signo)
{
  if (signo == SIGINT)
    count+=1;
    printf("received SIGINT, Before closed only %d times remain\n",10-count);
}

int main(void)
{
  
  if (signal(SIGINT, sig_handler) == SIG_ERR)
  printf("\ncan't catch SIGINT\n");
  // A long long wait so that we can easily issue a signal to this process
  while(1){
  	if(count==10){
		break;
	}
  }  	
    
  return 0;
}
