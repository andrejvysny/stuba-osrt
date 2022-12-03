#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

timer_t vytvorCasovac(int);
void spustiCasovac(timer_t, int);
int main(void)
{
  timer_t casovac;
  casovac=vytvorCasovac(SIGKILL);
  spustiCasovac(casovac,10);
  while(1)
  {
    sleep(1);
    printf("Dalsia sekunda\n");
  }
}



timer_t vytvorCasovac(int signal)
{
  struct sigevent kam;
  kam.sigev_notify=SIGEV_SIGNAL;
  kam.sigev_signo=signal;
  
  timer_t casovac;
  timer_create(CLOCK_REALTIME, &kam, &casovac);
  return(casovac); 
}

void spustiCasovac(timer_t casovac, int sekundy)
{
  struct itimerspec casik;
  casik.it_value.tv_sec=sekundy;
  casik.it_value.tv_nsec=0;
  casik.it_interval.tv_sec=0;
  casik.it_interval.tv_nsec=0;
  timer_settime(casovac,CLOCK_REALTIME,&casik,NULL);
}
