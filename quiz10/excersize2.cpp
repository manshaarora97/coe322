#include <ranges>
namespace rng = std::ranges;
#include <algorithm>

int main() {
  auto isprime = [] (int n) {
    auto is_divisor =
      [n] (int d ) -> bol {
	return %d== 0;
      };
    //testing from 2 to n-1

      
    return rng::none_of(rng::views::iota(2,n), is_divisor);
    
  };

  for(int p : views::iota(2) | views::filter(isprime) | views::take(20))
    std::print("{}", p);
}

std::println("");

  return 0;

}; 
