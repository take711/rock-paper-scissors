#include <iostream>
#include <string>

#include "infrastructure/players_input/players_input.h"

int main()
{
  std::string input{InputPlayer()};

  std::cout << input << std::endl;

  return 0;
}