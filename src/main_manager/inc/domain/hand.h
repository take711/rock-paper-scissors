#ifndef MAIN_MANAGER_INC_DOMAIN_HAND_H
#define MAIN_MANAGER_INC_DOMAIN_HAND_H

#include <stdint.h>

#include <string>

namespace RSP {
namespace domain {

class Hand {
 public:
  enum class Value : uint8_t { rock = 1U, paper, scissors };

  Hand();
  explicit Hand(const uint8_t created);

  Hand::Value GetHand() const;

  bool IsDraw(const Hand opponent) const;

  bool IsWin(const Hand opponent) const;

  bool IsLose(const Hand opponent) const;

  std::string ToString() const;

 private:
  Hand::Value value_;
};

}  // namespace domain
}  // namespace RSP

#endif  // MAIN_MANAGER_INC_DOMAIN_HAND_H