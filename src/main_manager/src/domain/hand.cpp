#include "domain/hand.h"

namespace RSP {
namespace domain {

Hand::Hand(const uint8_t created) : value_{static_cast<Hand::Value>(created)} {}

Hand::Value Hand::GetHand() const { return value_; }

bool Hand::IsDraw(const Hand opponent) const {
  return value_ == opponent.GetHand();
}

bool Hand::IsWin(const Hand opponent) const {
  bool result{false};

  switch (value_) {
    case Value::rock:
      if (opponent.GetHand() == Hand::Value::scissors) {
        result = true;
      }
      break;
    case Value::paper:
      if (opponent.GetHand() == Hand::Value::rock) {
        result = true;
      }
      break;
    case Value::scissors:
      if (opponent.GetHand() == Hand::Value::paper) {
        result = true;
      }
      break;

    default:
      // この分岐には入らない想定
      break;
  }

  return result;
}

bool Hand::IsLose(const Hand opponent) const {
  bool result{false};

  switch (value_) {
    case Value::rock:
      if (opponent.GetHand() == Hand::Value::paper) {
        result = true;
      }
      break;
    case Value::paper:
      if (opponent.GetHand() == Hand::Value::scissors) {
        result = true;
      }
      break;
    case Value::scissors:
      if (opponent.GetHand() == Hand::Value::rock) {
        result = true;
      }
      break;

    default:
      // この分岐には入らない想定
      break;
  }

  return result;
}

std::string Hand::ToString() const {
  std::string result{""};

  switch (value_) {
    case Value::rock:
      result = "グー";
      break;
    case Value::paper:
      result = "パー";
      break;
    case Value::scissors:
      result = "チョキ";
      break;
    default:
      result = "なにごとです？";
      break;
  }

  return result;
}

}  // namespace domain
}  // namespace RSP