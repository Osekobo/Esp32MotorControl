#include <iostream>

int main()
{
   int c ( 6 );   // direct-initialization (initial value in parenthesis)

// Modern initialization forms (preferred):
int d { 7 };   // direct-list-initialization (initial value in braces)
   int s = c + d;
   std::cout << s;
   return 0;
}