#include "infrastructure/players_input/players_input.h"

#include <iostream>

std::string InputPlayer()
{
  std::cout << "What do you choose?" << std::endl;
  std::cout << "rock:1, paper:2, scissors:3" << std::endl;

  int input{0};
  std::cin >> input;

  std::string result_string{"input received"};

  return result_string;
}