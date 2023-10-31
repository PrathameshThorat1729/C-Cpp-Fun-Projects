#include <stdio.h>
#include <time.h>
#include <string.h>

char* month_list[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

void print_month(int, int, int, int);

// Number of days in given month and respective year
int no_of_days(int month, int year)
{
  month++; // as input is 0 - 11
  if (month == 2)
  {
    if (year % 4 == 0) return 29;
    else return 28;
  }
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    return 31;
  else
    return 30;
}

int main(int arg, char** args)
{
  int all = 0; // flag to print all months in year
  struct tm* t_ptr;
  time_t t = time(0);
  t_ptr = localtime(&t);
  
  int today = t_ptr->tm_mday; // today's date
  int today_mon = t_ptr->tm_mon; // today's month
  int mon = t_ptr->tm_mon; // default month ( today's )
  int year = t_ptr->tm_year + 1900; // default year ( today's )

  // handling command line input
  for(int i = 1; i < arg; i++)
  {
    if (strcmp(args[i], "month") == 0)
    {
      if ((mon + 1) != atoi(args[++i]) && all == 0) today = 0;
      mon = atoi(args[i]) - 1;
    }
    else if (strcmp(args[i], "year") == 0)
    {
      if (year != atoi(args[++i]) && all == 0) today = 0;
      year = atoi(args[i]);
    }
    else if (strcmp(args[i], "-a") == 0) all = 1;
  }
  
  // set t_ptr to point 1st day of month
  t_ptr->tm_sec = 0;
  t_ptr->tm_min = 0;
  t_ptr->tm_hour = 0;
  t_ptr->tm_mday = 1;
  t_ptr->tm_mon = mon;
  t_ptr->tm_year = year - 1900;
  t = mktime(t_ptr);
  t_ptr = localtime(&t);
  
  int day = t_ptr->tm_wday; // 1st day of month
  
  if (all == 0)
    print_month(today, day, mon, year);
  else if (all == 1)
  {
    // set t_ptr to point 1st day of year
    t_ptr->tm_mon = 0;
    t = mktime(t_ptr);
    t_ptr = localtime(&t);
    
    day = t_ptr->tm_wday;
    
    for (int i = 0; i < 12; i++)
    {
      if (i == today_mon)
        print_month(today, day, i, year);
      else
        print_month(0, day, i, year);
      printf(" -----------------------------------\n");
      day = ( day + no_of_days(i, year) ) % 7;
    }
  }
  
  return 0;
}

void print_month(int today, int day, int month, int year)
{
  int date = 1; // date counter
  int start = 0; // whether to start print date or not
                 // 0 for not to start
                 // 1 for to start
                 // 2 for not to start, printing done
  
  printf("\n Year  : %d\n Month : %s\n", year, month_list[month]);
  printf("\n Sun  Mon  Tue  Wed  Thr  Fri  Sat\n\n");
  
  while (start != 2)
  {
    for (int week_day = 0; week_day < 7; week_day++)
    {
      if (start == 0 && week_day == day) start = 1;
      if (start == 1)
      {
        if (date == today) printf(" \033[4;30;107m");
        else printf(" ");
        
        (date < 10) ? printf(" 0%d ", date++) : printf(" %d ", date++);
        printf("\033[0m");
      }
      else printf("     ");
      if (date > no_of_days(month, year)) start = 2;
    }
    printf("\n");
  }
  printf("\n");
}