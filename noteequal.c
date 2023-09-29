#include <stdio.h>

int main ()
{
  long long a, b, c, d;

  scanf ("%lld %lld %lld %lld", &a, &b, &c, &d);

  if (a >= 0 && a <= 1000000 && b >= 0 && b <= 1000000 && c >= 0 && c <= 1000000 && d >= 0 && d <= 1000000){
          
      long long multiplication = a * b;
      long long addition = c + d;

      if (multiplication > addition)
	    {
	  printf ("True\n");
	    }
      else
	    {
	  printf ("False\n");
	    }
    }
  else
    {
      printf ("Invalid input. All numbers should be between 0 and 1000000.\n");
    }

  return 0;
}
