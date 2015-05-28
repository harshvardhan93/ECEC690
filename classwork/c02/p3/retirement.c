#include<stdio.h>
#include<stdlib.h>

struct _retire_info
{
  int months;
  double dollars;
  double rate;
};

typedef struct _retire_info retire_info;

void retirement(int startAge, double initial, retire_info working, retire_info retired)
{
  double ac_balance=0;
    ac_balance=initial;
  int totalage=startAge+working.months+retired.months;
  working.rate=working.rate/12;
  retired.rate=retired.rate/12;
  for(int i=startAge;i<totalage;i++)
    {
      int i_year=i/12;
      int i_month=i%12;
      if(i==startAge)
	{
	  printf("Age %3d month %2d you have $%.2f\n",i_year,i_month,ac_balance);
	}
      else if(i>=startAge && i<=(startAge+working.months))
	{
	  ac_balance=(ac_balance+(ac_balance*working.rate/100)+working.dollars);
	  printf("Age %3d month %2d you have $%.2lf\n",i_year,i_month,ac_balance);
	}
      else
	{
	  ac_balance=(ac_balance+(ac_balance*retired.rate/100)+retired.dollars);
	  printf("Age %3d month %2d you have $%.2lf\n",i_year,i_month,ac_balance);
	}
    }

}


int main(void)
{
  retire_info working, retired;
  int startAge;
  double savings;
  working.months=489;
  working.dollars=1000;
  working.rate=4.5;
  retired.months=384;
  retired.dollars=-4000;
  retired.rate=1;
  startAge=327;
  savings=21345;
  //printf("Calling function retirement");
  retirement(startAge, savings, working, retired);
  
  return EXIT_SUCCESS;
}
