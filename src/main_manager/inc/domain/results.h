#ifndef MAIN_MANAGER_INC_DOMAIN_RESULTS_H
#define MAIN_MANAGER_INC_DOMAIN_RESULTS_H

#include <stdint.h>

#include "hand.h"

namespace RSP {
namespace domain {

enum class Results : uint8_t { player_win = 0, player_lose, draw };

}  // namespace domain
}  // namespace RSP

#endif  // MAIN_MANAGER_INC_DOMAIN_RESULTS_H