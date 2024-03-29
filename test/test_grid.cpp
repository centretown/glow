#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include <catch2/catch_all.hpp>

#include "test_yaml.h"
#include "Grid.h"
#include "check_grid_detail.h"

using namespace glow;

void check_detail(const Grid &original, const Grid &derived)
{
  check_grid_detail(original, derived);
}

TEST_CASE("Grid 2x2 TopLeft Diagonal", "[grid_2x2_topleft_diagonal]")
{
  Grid grid;
  REQUIRE(grid.setup(4, 2, TopLeft, Diagonal));
  REQUIRE(4 == grid.get_length());
  REQUIRE(2 == grid.get_rows());
  REQUIRE(TopLeft == grid.get_origin());
  REQUIRE(Diagonal == grid.get_orientation());
  REQUIRE(1 == grid.get_first());
  REQUIRE(1 == grid.get_offset());

  REQUIRE(0 == grid.map(0));
  REQUIRE(1 == grid.map(1));
  REQUIRE(2 == grid.map(2));
  REQUIRE(3 == grid.map(3));

  std::string input =
      "length: 4\n"
      "rows: 2\n"
      "origin: 0\n"
      "orientation: diagonal\n";
  test_yaml(grid, input, check_detail);
}

TEST_CASE("Grid 2x3 TopLeft Diagonal", "[grid_2x3_topleft_diagonal]")
{
  Grid grid;
  REQUIRE(grid.setup(6, 2, TopLeft, Diagonal));
  REQUIRE(6 == grid.get_length());
  REQUIRE(2 == grid.get_rows());
  REQUIRE(TopLeft == grid.get_origin());
  REQUIRE(Diagonal == grid.get_orientation());
  REQUIRE(1 == grid.get_first());
  REQUIRE(1 == grid.get_offset());
  REQUIRE(4 == grid.get_last());

  REQUIRE(0 == grid.map(0));
  REQUIRE(1 == grid.map(1));
  REQUIRE(3 == grid.map(2));
  REQUIRE(2 == grid.map(3));
  REQUIRE(4 == grid.map(4));
  REQUIRE(5 == grid.map(5));

  std::string input =
      "length: 6\n"
      "rows: 2\n"
      "origin: 0\n"
      "orientation: diagonal\n";

  test_yaml(grid, input, check_detail);
}

TEST_CASE("Grid 3x4 TopLeft Diagonal", "[grid_3x4_topleft_diagonal]")
{
  Grid grid;
  REQUIRE(grid.setup(12, 3, TopLeft, Diagonal));
  REQUIRE(12 == grid.get_length());
  REQUIRE(3 == grid.get_rows());
  REQUIRE(TopLeft == grid.get_origin());
  REQUIRE(Diagonal == grid.get_orientation());

  REQUIRE(3 == grid.get_first());
  REQUIRE(2 == grid.get_offset());
  REQUIRE(8 == grid.get_last());

  REQUIRE(0 == grid.map(0));
  REQUIRE(1 == grid.map(1));
  REQUIRE(4 == grid.map(2));
  REQUIRE(2 == grid.map(3));
  REQUIRE(5 == grid.map(4));
  REQUIRE(8 == grid.map(5));

  REQUIRE(3 == grid.map(6));
  REQUIRE(6 == grid.map(7));
  REQUIRE(9 == grid.map(8));
  REQUIRE(7 == grid.map(9));
  REQUIRE(10 == grid.map(10));
  REQUIRE(11 == grid.map(11));

  std::string input =
      "length: 12\n"
      "rows: 3\n"
      "origin: 0\n"
      "orientation: diagonal\n";

  test_yaml(grid, input, check_detail);
}

TEST_CASE("Grid 4x5 TopLeft Diagonal", "[grid_4x5_topleft_diagonal]")
{
  Grid grid;
  REQUIRE(grid.setup(20, 4, TopLeft, Diagonal));
  REQUIRE(20 == grid.get_length());
  REQUIRE(4 == grid.get_rows());
  REQUIRE(TopLeft == grid.get_origin());
  REQUIRE(Diagonal == grid.get_orientation());

  REQUIRE(5 == grid.get_columns());

  REQUIRE(6 == grid.get_first());
  REQUIRE(3 == grid.get_offset());
  REQUIRE(13 == grid.get_last());

  REQUIRE(0 == grid.map(0));
  REQUIRE(1 == grid.map(1));
  REQUIRE(5 == grid.map(2));
  REQUIRE(2 == grid.map(3));
  REQUIRE(6 == grid.map(4));
  REQUIRE(10 == grid.map(5));
  REQUIRE(3 == grid.map(6));
  REQUIRE(7 == grid.map(7));
  REQUIRE(11 == grid.map(8));
  REQUIRE(15 == grid.map(9));
  REQUIRE(4 == grid.map(10));
  REQUIRE(8 == grid.map(11));
  REQUIRE(12 == grid.map(12));
  REQUIRE(16 == grid.map(13));
  REQUIRE(9 == grid.map(14));
  REQUIRE(13 == grid.map(15));
  REQUIRE(17 == grid.map(16));
  REQUIRE(14 == grid.map(17));
  REQUIRE(18 == grid.map(18));
  REQUIRE(19 == grid.map(19));

  std::string input =
      "length: 20\n"
      "rows: 4\n"
      "origin: 0\n"
      "orientation: diagonal\n";

  test_yaml(grid, input, check_detail);
}

TEST_CASE("Grid 4x9 TopLeft Diagonal", "[grid_4x9_topleft_diagonal]")
{
  Grid grid;
  REQUIRE(grid.setup(36, 4, TopLeft, Diagonal));
  REQUIRE(36 == grid.get_length());
  REQUIRE(4 == grid.get_rows());
  REQUIRE(TopLeft == grid.get_origin());
  REQUIRE(Diagonal == grid.get_orientation());

  REQUIRE(9 == grid.get_columns());

  REQUIRE(6 == grid.get_first());
  REQUIRE(3 == grid.get_offset());
  REQUIRE(29 == grid.get_last());

  REQUIRE(0 == grid.map(0));
  REQUIRE(1 == grid.map(1));
  REQUIRE(9 == grid.map(2));
  REQUIRE(2 == grid.map(3));
  REQUIRE(10 == grid.map(4));
  REQUIRE(18 == grid.map(5));
  REQUIRE(3 == grid.map(6));
  REQUIRE(11 == grid.map(7));
  REQUIRE(19 == grid.map(8));
  REQUIRE(27 == grid.map(9));
  REQUIRE(4 == grid.map(10));
  REQUIRE(12 == grid.map(11));
  REQUIRE(20 == grid.map(12));
  REQUIRE(28 == grid.map(13));
  REQUIRE(5 == grid.map(14));
  REQUIRE(13 == grid.map(15));
  REQUIRE(21 == grid.map(16));
  REQUIRE(29 == grid.map(17));
  REQUIRE(6 == grid.map(18));
  REQUIRE(14 == grid.map(19));
  REQUIRE(22 == grid.map(20));
  REQUIRE(30 == grid.map(21));
  REQUIRE(7 == grid.map(22));
  REQUIRE(15 == grid.map(23));
  REQUIRE(23 == grid.map(24));
  REQUIRE(31 == grid.map(25));
  REQUIRE(8 == grid.map(26));
  REQUIRE(16 == grid.map(27));
  REQUIRE(24 == grid.map(28));
  REQUIRE(32 == grid.map(29));
  REQUIRE(17 == grid.map(30));
  REQUIRE(25 == grid.map(31));
  REQUIRE(33 == grid.map(32));
  REQUIRE(26 == grid.map(33));
  REQUIRE(34 == grid.map(34));
  REQUIRE(35 == grid.map(35));

  std::string input =
      "length: 36\n"
      "rows: 4\n"
      "origin: 0\n"
      "orientation: diagonal\n";

  test_yaml(grid, input, check_detail);
}

TEST_CASE("Grid 4x9 TopRight Diagonal", "[grid_4x9_topright_diagonal]")
{
  Grid grid;
  REQUIRE(grid.setup(36, 4, TopRight, Diagonal));
  REQUIRE(36 == grid.get_length());
  REQUIRE(4 == grid.get_rows());
  REQUIRE(TopRight == grid.get_origin());
  REQUIRE(Diagonal == grid.get_orientation());

  REQUIRE(9 == grid.get_columns());

  REQUIRE(6 == grid.get_first());
  REQUIRE(3 == grid.get_offset());
  REQUIRE(29 == grid.get_last());

  REQUIRE(8 == grid.map(0));
  REQUIRE(7 == grid.map(1));
  REQUIRE(17 == grid.map(2));
  REQUIRE(6 == grid.map(3));
  REQUIRE(16 == grid.map(4));

  REQUIRE(26 == grid.map(5));
  REQUIRE(5 == grid.map(6));
  REQUIRE(15 == grid.map(7));
  REQUIRE(25 == grid.map(8));
  REQUIRE(35 == grid.map(9));

  REQUIRE(4 == grid.map(10));
  REQUIRE(14 == grid.map(11));
  REQUIRE(24 == grid.map(12));
  REQUIRE(34 == grid.map(13));
  REQUIRE(18 == grid.map(33));
  REQUIRE(28 == grid.map(34));
  REQUIRE(27 == grid.map(35));

  std::string input =
      "length: 36\n"
      "rows: 4\n"
      "origin: top right\n"
      "orientation: diagonal\n";

  test_yaml(grid, input, check_detail);
}

TEST_CASE("Grid 4x9 BottomRight Diagonal", "[grid_4x9_bottomright_diagonal]")
{
  Grid grid;
  REQUIRE(grid.setup(36, 4, BottomRight, Diagonal));
  REQUIRE(36 == grid.get_length());
  REQUIRE(4 == grid.get_rows());
  REQUIRE(BottomRight == grid.get_origin());
  REQUIRE(Diagonal == grid.get_orientation());

  REQUIRE(9 == grid.get_columns());

  REQUIRE(6 == grid.get_first());
  REQUIRE(3 == grid.get_offset());
  REQUIRE(29 == grid.get_last());

  REQUIRE(35 == grid.map(0));
  REQUIRE(34 == grid.map(1));
  REQUIRE(26 == grid.map(2));
  REQUIRE(33 == grid.map(3));
  REQUIRE(25 == grid.map(4));
  REQUIRE(17 == grid.map(5));
  REQUIRE(32 == grid.map(6));
  REQUIRE(24 == grid.map(7));
  REQUIRE(16 == grid.map(8));
  REQUIRE(8 == grid.map(9));
  REQUIRE(31 == grid.map(10));
  REQUIRE(23 == grid.map(11));
  REQUIRE(15 == grid.map(12));
  REQUIRE(7 == grid.map(13));
  REQUIRE(30 == grid.map(14));
  REQUIRE(22 == grid.map(15));
  REQUIRE(14 == grid.map(16));
  REQUIRE(6 == grid.map(17));
  REQUIRE(29 == grid.map(18));
  REQUIRE(21 == grid.map(19));
  REQUIRE(13 == grid.map(20));
  REQUIRE(5 == grid.map(21));
  REQUIRE(28 == grid.map(22));
  REQUIRE(20 == grid.map(23));
  REQUIRE(12 == grid.map(24));
  REQUIRE(4 == grid.map(25));
  REQUIRE(27 == grid.map(26));
  REQUIRE(19 == grid.map(27));
  REQUIRE(11 == grid.map(28));
  REQUIRE(3 == grid.map(29));

  REQUIRE(18 == grid.map(30));
  REQUIRE(10 == grid.map(31));

  REQUIRE(2 == grid.map(32));
  REQUIRE(9 == grid.map(33));
  REQUIRE(1 == grid.map(34));
  REQUIRE(0 == grid.map(35));

  std::string input =
      "length: 36\n"
      "rows: 4\n"
      "origin: bottom right\n"
      "orientation: diagonal\n";

  test_yaml(grid, input, check_detail);
}

TEST_CASE("Grid Symbolic", "[grid_custom]")
{
  Grid grid_default_rows;
  REQUIRE(grid_default_rows.setup(36, 1, BottomRight, Diagonal));
  std::string input_missing_rows =
      "length: 36\n"
      "origin: bottom right\n"
      "orientation: diagonal\n";
  test_yaml_from_input(grid_default_rows,
                       input_missing_rows, check_detail);

  Grid grid_default_origin;
  REQUIRE(grid_default_origin.setup(36, 4, TopLeft, Diagonal));
  std::string input_missing_origin =
      "length: 36\n"
      "rows: 4\n"
      "orientation: diagonal\n";
  test_yaml_from_input(grid_default_origin,
                       input_missing_origin, check_detail);

  Grid grid_default_orientation;
  REQUIRE(grid_default_orientation.setup(36, 4, BottomRight, Horizontal));
  std::string input_missing_orientation =
      "length: 36\n"
      "rows: 4\n"
      "origin: bottom right\n";
  test_yaml_from_input(grid_default_orientation,
                       input_missing_orientation, check_detail);
}

TEST_CASE("Grid Incomplete", "[grid_incomplete]")
{
  Grid grid_default_length;
  REQUIRE(grid_default_length.setup(10, 4));
  std::string input_missing_half =
      "length: 10\n"
      "rows: 4\n";
  // test_yaml_from_input(grid_default_length,
  //                      input_missing_half, check_detail);

  Grid grid_default_rows;
  REQUIRE(grid_default_rows.setup(36, 1, BottomRight, Diagonal));
  std::string input_missing_rows =
      "length: 36\n"
      "origin: bottom right\n"
      "orientation: diagonal\n";
  test_yaml_from_input(grid_default_rows,
                       input_missing_rows, check_detail);

  Grid grid_default_origin;
  REQUIRE(grid_default_origin.setup(36, 4, TopLeft, Diagonal));
  std::string input_missing_origin =
      "length: 36\n"
      "rows: 4\n"
      "orientation: diagonal\n";
  test_yaml_from_input(grid_default_origin,
                       input_missing_origin, check_detail);

  Grid grid_default_orientation;
  REQUIRE(grid_default_orientation.setup(36, 4, BottomRight, Horizontal));
  std::string input_missing_orientation =
      "length: 36\n"
      "rows: 4\n"
      "origin: bottom right\n";
  test_yaml_from_input(grid_default_orientation,
                       input_missing_orientation, check_detail);

  Grid grid_default;
  REQUIRE(grid_default.setup(36));
  std::string input_missing =
      "length: 36\n";
  test_yaml_from_input(grid_default,
                       input_missing, check_detail);
}

TEST_CASE("Grid Code", "[grid_make_code]")
{
  Grid grid;
  REQUIRE(grid.setup(36, 1, BottomRight, Diagonal));
  std::cout << grid.make_code() << '\n';
  REQUIRE(grid.setup(36, 4, TopRight, Horizontal));
  std::cout << grid.make_code() << '\n';
  REQUIRE(grid.setup(33, 1, BottomLeft, Vertical));
  std::cout << grid.make_code() << '\n';
  REQUIRE(grid.setup(44, 3, TopLeft, Diagonal));
  std::cout << grid.make_code() << '\n';
  REQUIRE(grid.setup(66, 1, BottomRight, Diagonal));
  std::cout << grid.make_code() << '\n';
}

TEST_CASE("Square Grid Centred", "[square_grid_centred]")
{
  Grid grid;
  REQUIRE(grid.setup(100, 10, TopLeft, Centred));
  REQUIRE(grid.get_centre() == 44);

  REQUIRE(grid.map(0) == 44);

  REQUIRE(grid.map(1) == 45);
  REQUIRE(grid.map(2) == 55);

  REQUIRE(grid.map(3) == 54);
  REQUIRE(grid.map(4) == 53);

  REQUIRE(grid.map(5) == 43);
  REQUIRE(grid.map(6) == 33);

  REQUIRE(grid.map(7) == 34);
  REQUIRE(grid.map(8) == 35);

  REQUIRE(grid.map(9) == 36);
  REQUIRE(grid.map(10) == 46);
  REQUIRE(grid.map(11) == 56);
  REQUIRE(grid.map(12) == 66);

  REQUIRE(grid.map(13) == 65);
  REQUIRE(grid.map(14) == 64);
  REQUIRE(grid.map(15) == 63);
  REQUIRE(grid.map(16) == 62);

  REQUIRE(grid.map(17) == 52);
  REQUIRE(grid.map(18) == 42);
  REQUIRE(grid.map(19) == 32);
  REQUIRE(grid.map(20) == 22);

  REQUIRE(grid.map(21) == 23);
  REQUIRE(grid.map(22) == 24);
  REQUIRE(grid.map(23) == 25);
  REQUIRE(grid.map(24) == 26);

  REQUIRE(grid.map(25) == 27);
  REQUIRE(grid.map(26) == 37);
  REQUIRE(grid.map(27) == 47);
  REQUIRE(grid.map(28) == 57);
  REQUIRE(grid.map(29) == 67);
  REQUIRE(grid.map(30) == 77);

  REQUIRE(grid.map(31) == 76);
  REQUIRE(grid.map(32) == 75);
  REQUIRE(grid.map(33) == 74);
  REQUIRE(grid.map(34) == 73);
  REQUIRE(grid.map(35) == 72);
  REQUIRE(grid.map(36) == 71);

  REQUIRE(grid.map(37) == 61);
  REQUIRE(grid.map(38) == 51);
  REQUIRE(grid.map(39) == 41);
  REQUIRE(grid.map(40) == 31);
  REQUIRE(grid.map(41) == 21);
  REQUIRE(grid.map(42) == 11);

  REQUIRE(grid.map(43) == 12);
  REQUIRE(grid.map(44) == 13);
  REQUIRE(grid.map(45) == 14);
  REQUIRE(grid.map(46) == 15);
  REQUIRE(grid.map(47) == 16);
  REQUIRE(grid.map(48) == 17);
}

TEST_CASE("Grid Centred", "[grid_centred]")
{
  Grid grid;
  // 10 x 10
  REQUIRE(grid.setup(100, 10, TopLeft, Centred));
  REQUIRE(grid.get_centre() == 44);
  REQUIRE(grid.get_first_edge() == 100);
  REQUIRE(grid.get_first_offset() == 100);
  REQUIRE(grid.get_ring_status() == PIVOT_SQUARE);
  // REQUIRE(grid.get_direction() == 0);
  // REQUIRE(grid.get_low() == 5);
  // REQUIRE(grid.get_high() == 5);

  // 5 x 10
  REQUIRE(grid.setup(50, 5, TopLeft, Centred));
  REQUIRE(grid.get_centre() == 24);
  // REQUIRE(grid.get_direction() == 0);
  // REQUIRE(grid.get_low() == 2);
  // REQUIRE(grid.get_high() == 2);
  // 3 x 12

  REQUIRE(grid.setup(36, 3, TopLeft, Centred));
  REQUIRE(grid.get_centre() == 17);
  REQUIRE(grid.get_first_edge() == 9);
  REQUIRE(grid.get_first_offset() == 7);
  REQUIRE(grid.map(0) == 17);
  REQUIRE(grid.get_ring_status() == PIVOT_COLUMNS);
  REQUIRE(grid.get_ring_count() == 1);
  REQUIRE(grid.get_ring_count_high() == 1);

  // 4 x 9
  REQUIRE(grid.setup(36, 4, TopLeft, Centred));
  REQUIRE(grid.get_centre() == 13);
  REQUIRE(grid.get_first_edge() == 9);
  REQUIRE(grid.get_first_offset() == 6);
  REQUIRE(grid.get_ring_status() == (PIVOT_COLUMNS | PIVOT_UNEVEN));
  REQUIRE(grid.get_ring_count() == 1);
  REQUIRE(grid.get_ring_count_high() == 2);
  REQUIRE(grid.get_last_offset() == 29);

  REQUIRE(grid.map(0) == 13);
  REQUIRE(grid.map(9) == 6);
  REQUIRE(grid.map(10) == 15);
  REQUIRE(grid.map(11) == 24);
  REQUIRE(grid.map(12) == 33);
  REQUIRE(grid.map(13) == 32);
  REQUIRE(grid.map(14) == 31);
  REQUIRE(grid.map(15) == 30);
  REQUIRE(grid.map(16) == 29);
  REQUIRE(grid.map(17) == 20);
  REQUIRE(grid.map(18) == 11);
  REQUIRE(grid.map(19) == 2);
  REQUIRE(grid.map(20) == 7);
  REQUIRE(grid.map(21) == 16);
  REQUIRE(grid.map(22) == 25);
  REQUIRE(grid.map(23) == 34);
  REQUIRE(grid.map(24) == 28);
  REQUIRE(grid.map(25) == 19);
  REQUIRE(grid.map(26) == 10);
  REQUIRE(grid.map(27) == 1);
  REQUIRE(grid.map(28) == 8);
  REQUIRE(grid.map(29) == 17);
  REQUIRE(grid.map(30) == 26);
  REQUIRE(grid.map(31) == 35);
  REQUIRE(grid.map(32) == 27);
  REQUIRE(grid.map(33) == 18);
  REQUIRE(grid.map(34) == 9);
  REQUIRE(grid.map(35) == 0);
}
