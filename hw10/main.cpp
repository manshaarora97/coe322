// perfect numbers with ranges
#include <algorithm>
#include <functional>
#include <print>
#include <ranges>
using namespace std;
namespace rng = std::ranges;

int main() {

  // sum of the factors of n (not counting n itself)
  auto factor_sum = [] (int n) {
    auto factors = rng::views::iota(1,n)
      | rng::views::filter( [n] (int i) { return n%i==0; } );
    return rng::fold_left(factors,0,plus<>());
  };

  // using iota and for_each
  rng::for_each
    ( rng::views::iota(1,10001),
      [&] (int n) {
        if (n==factor_sum(n))
          print("{} ",n); }
    );
  println("");

  // using filter
  auto perfect = rng::views::iota(1,10001)
    | rng::views::filter( [&] (int n) { return n==factor_sum(n); } );
  rng::for_each( perfect, [] (int n) { print("{} ",n); } );
  println("");
}
