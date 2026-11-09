// linktester.cpp -- Catch2 unit tests for linklib.hpp
// (exercises 4-9 of the smart-pointer lecture).
//

#include "catch2/catch_all.hpp"
#include "linklib.hpp"

TEST_CASE("empty list", "[4]") {
  List mylist;
  REQUIRE(mylist.length() == 0);
  REQUIRE_THROWS(mylist.headnode());
}

TEST_CASE("insert into an empty list", "[5]") {
  List mylist;
  mylist.insert(3);
  REQUIRE(mylist.length() == 1);
  REQUIRE(mylist.contains_value(3));
  REQUIRE(not mylist.contains_value(4));
}

TEST_CASE("insert at the end", "[6]") {
  List mylist;
  mylist.insert(3);
  mylist.insert(5);
  REQUIRE_NOTHROW(mylist.insert(6));
  REQUIRE(mylist.length() == 3);
  REQUIRE(mylist.contains_value(6));
}

TEST_CASE("insert at the head", "[7]") {
  List mylist;
  mylist.insert(3);
  REQUIRE_NOTHROW(mylist.insert(2));
  REQUIRE(mylist.length() == 2);
  REQUIRE(mylist.contains_value(2));
  REQUIRE(mylist.contains_value(3));

  Node headnode;
  REQUIRE_NOTHROW(headnode = mylist.headnode());
  REQUIRE(headnode.value() == 2);   // the head should be 2, not 3
  REQUIRE(headnode.count() == 1);
}

TEST_CASE("insert in the middle", "[8]") {
  List mylist;
  mylist.insert(2);
  mylist.insert(3);
  mylist.insert(5);
  REQUIRE_NOTHROW(mylist.insert(4));
  REQUIRE(mylist.length() == 4);
  REQUIRE(mylist.contains_value(4));
  REQUIRE(mylist.contains_value(3));
  // The list should now be 2, 3, 4, 5. Check that 4 sits right after 3.
  Node first = mylist.headnode();            // the node holding 2
  Node second = *(first.nextnode());         // the node holding 3
  REQUIRE(second.value() == 3);
  REQUIRE(second.nextnode()->value() == 4);
}

TEST_CASE("insert a value that is already there", "[9]") {
  List mylist;
  mylist.insert(3);
  REQUIRE_NOTHROW(mylist.insert(3));
  REQUIRE(mylist.length() == 1);
  REQUIRE(mylist.contains_value(3));

  Node headnode;
  REQUIRE_NOTHROW(headnode = mylist.headnode());
  REQUIRE(headnode.value() == 3);
  REQUIRE(headnode.count() == 2);
}

TEST_CASE("repeated values later in the list are counted", "[9]") {
  List mylist;
  mylist.insert(5);
  mylist.insert(7);
  mylist.insert(5);
  mylist.insert(8);
  mylist.insert(7);
  // The list should now be 5 (twice), 7 (twice), 8 (once): three nodes.
  REQUIRE(mylist.length() == 3);
  Node first = mylist.headnode();            // the node holding 5
  REQUIRE(first.count() == 2);
  REQUIRE(first.nextnode()->value() == 7);   // sorted: 7 comes next
  REQUIRE(first.nextnode()->count() == 2);
}
