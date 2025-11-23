#include <iostream>
#include <random>
#include <string>

#include "domain/hand.h"
#include "domain/results.h"
#include "infrastructure/players_input/players_input.h"

namespace {
uint8_t GetRandomHand() {
  static std::random_device rd{};
  static std::mt19937 gen{rd()};

  std::uniform_int_distribution<int> dist{1, 3};

  const int value{dist(gen)};

  return static_cast<uint8_t>(value);
}

std::string ResultToString(RSP::domain::Results input) {
  std::string result{};

  switch (input) {
    case RSP::domain::Results::draw:
      result = "結果 : あいこ";
      break;
    case RSP::domain::Results::player_win:
      result = "結果 : あなたの勝ち！";
      break;
    case RSP::domain::Results::player_lose:
      result = "結果 : あなたの負け...";
      break;
    default:
      result = "なにごとですか？";
      break;
  }

  return result;
}

RSP::domain::Results Judge(const RSP::domain::Hand player,
                           const RSP::domain::Hand cpu) {
  RSP::domain::Results result{RSP::domain::Results::draw};

  std::cout << "あなた : " << player.ToString() << std::endl;
  std::cout << "相手 : " << cpu.ToString() << std::endl;

  if (player.IsDraw(cpu)) {
    result = RSP::domain::Results::draw;
  } else if (player.IsWin(cpu)) {
    result = RSP::domain::Results::player_win;
  } else if (player.IsLose(cpu)) {
    result = RSP::domain::Results::player_lose;
  } else {
    // この分岐に入る想定はないため、何もしない
  }

  return result;
}

}  // namespace

int main() {
  const uint8_t input{RSP::infrastructure::InputPlayer()};

  const RSP::domain::Hand players_hand{input};
  const RSP::domain::Hand cpus_hand{GetRandomHand()};

  std::cout << ResultToString(Judge(players_hand, cpus_hand)) << std::endl;

  return 0;
}
