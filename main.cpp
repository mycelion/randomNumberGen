
#include <iostream>
#include <random>

using namespace std;

int
rand_int (int low, int high)
{
  static std::default_random_engine re
  {
    std::random_device
    {
  } ()};
  using Dist = std::uniform_int_distribution < int >;
  static Dist uid
  {
  };
  return uid (re, Dist::param_type
	      {
	      low, high}
  );
}

int
main ()
{
  for (int i = 0; i < 500; i++)
    {
      int a = rand_int (0, 250);
      int b = rand_int (0, 250);
      while (b == a)
	{
	  b = rand_int (0, 250);
	}
      int c = rand_int (1, 100);
      int d = rand_int (0, 9);
      cout << "(" << a << ", " << b << ", " << c << "." << d << "), ";
    }

  return 0;
}
