#include <stdio.h>
#define Dday 100

int isleapyear (int year){
  if ((year % 4 == 0) || ((year % 100 != 0) && (year % 400 == 0)))
    return 1;
  else
    return 0;
}

int daycount (int month,int day, int * arr){
  int sum=0;
  for (int i=0 ; i<month-1; i++)
    sum += arr[i];
  return sum + day;
}

int main(void) {
	int year1, month1, day1, year2, month2=0, day2, days1, days2;
  int yeararr[] =  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	printf("Enter the first meeting day : ");
	scanf("%d %d %d", &year1, &month1, &day1);

	if(isleapyear(year1) == 1){
	  yeararr[1] = 29;
	  days1 = daycount(month1, day1, yeararr) + Dday;
	  year2 = year1;
	  if(days1>daycount(12, 31, yeararr)){
	    days1 -= daycount(12, 31, yeararr);
	    year2 = year1+1;
	  }
	  while(days1-yeararr[month2++] > 0){
	    days1 -= yeararr[month2];
	    day2 = days1-2;
	  }
	}
  else{
	  days1 = daycount(month1, day1, yeararr) + Dday;
	  year2 = year1;

	  if(days1>daycount(12, 31, yeararr)){
	    days1 -= daycount(12, 31, yeararr);
	    year2 = year1+1;
	     // 다음해가 윤년이고, 2월 28일 이후인 날짜가 기념일 일때, 배열요소값 변경
	    if(isleapyear(year1+1) == 1 && days1>=59){
	      yeararr[1] = 29;
	    }
	  }
	  while(days1-yeararr[month2++] > 0){
	    days1 -= yeararr[month2];
	    day2 = days1-2;
	  }
	}
  printf("The 100th day is %d-%d-%d.\n", year2, month2, day2);
	return 0;
}
