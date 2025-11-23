#include "infrastructure/players_input/players_input.h"

#include <stdint.h>

#include <iostream>

namespace RSP {
namespace infrastructure {

uint8_t InputPlayer() {
  std::cout << "なにを出しますか？" << std::endl;
  std::cout << "グー:1, パー:2, チョキ:3" << std::endl;

  int input{0};
  std::cin >> input;

  if ((input < 1) || (input > 3)) {
    std::cout << "ごめんなさい、もう一度選んでください" << std::endl;

    InputPlayer();
  }

  const uint8_t cast_input{static_cast<uint8_t>(input)};

  return cast_input;
}

}  // namespace infrastructure
}  // namespace RSP