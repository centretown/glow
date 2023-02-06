#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include <iostream>
#include <string>

#include "test_yaml.h"
#include "check_chroma_detail.h"
#include "../src/Chroma.h"
using namespace glow;

void check_detail(const Chroma &original, const Chroma &derived)
{
  check_chroma_detail(original,derived);
}

TEST_CASE("Chroma Basic", "chroma_basic")
{
  Chroma chroma;
  HSVColor a, b;
  a.from_color_wheel(float(0), float(100), float(100));
  b.from_color_wheel(float(0), float(50), float(50));
  REQUIRE(chroma.setup(20, a, b, -1));
  std::string input =
      "length: 20\n"
      "delta: -1\n" // out of order
      "source:\n"
      "  hue: 0\n"
      "  saturation: 100\n"
      "  value: 100\n"
      "target:\n"
      "  hue: 0\n"
      "  saturation: 50\n"
      "  value: 50\n";
  test_yaml(chroma, input, check_detail);

  Chroma chroma_length_only;
  REQUIRE(chroma_length_only.setup(20));
  std::string input_length_only =
      "length: 20\n";
  test_yaml(chroma_length_only, input_length_only, check_detail);
}