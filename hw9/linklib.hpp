
// Header-only: used by linktester.cpp (tests) and linkmain.cpp (exercise 10).
#pragma once

#include <print>
#include <memory>
using std::make_shared, std::shared_ptr;

// A node has a value, a count of how often that value was inserted,
// and a link to the next node. A null link marks the end of the list.
class Node {
private:
  int datavalue{0}, datacount{0};
  shared_ptr<Node> next{nullptr};

public:
  Node() {};
  Node(int value, shared_ptr<Node> next = nullptr)
      : datavalue(value), datacount(1), next(next) {};

  int value() { return datavalue; };
  int count() { return datacount; };
  bool has_next() { return next != nullptr; };
  shared_ptr<Node> nextnode() { return next; };

  bool contains_value(int val) {
    if (datavalue == val)
      return true;
    else if (!has_next())
      return false;
    else
      return next->contains_value(val);
  };

  int length() {
    if (!has_next())
      return 1;
    else
      return 1 + next->length();
  };

  // Insert after this node, keeping the list sorted.
  // (List::insert handles a value that goes before the head.)
  void insert(int v) {
    if (v == datavalue)
      datacount += 1;                          // already there: count it
    else if (!has_next() || v < next->datavalue)
      next = make_shared<Node>(v, next);       // goes right after this node
    else
      next->insert(v);                         // keep walking
  };

  // Prints value:count for this node and all later ones, e.g. 5:2 7:1 8:1
  void print() {
    std::print("{}:{}", datavalue, datacount);
    if (has_next()) {
      std::print(" ");
      next->print();
    }
  };
};

class List {
private:
  shared_ptr<Node> head{nullptr};

public:
  List() = default;

  bool empty() { return head == nullptr; };

  // Returns a copy of the first node; throws if the list is empty.
  Node headnode() {
    if (empty())
      throw("empty list has no head node");
    return *head;
  };

  void insert(int value) {
    if (empty())
      head = make_shared<Node>(value);           // first element
    else if (value < head->value())
      head = make_shared<Node>(value, head);     // new head
    else
      head->insert(value);                       // equal, middle or end
  };

  bool contains_value(int val) {
    if (empty())
      return false;
    else
      return head->contains_value(val);
  };

  int length() {
    if (empty())
      return 0;
    else
      return head->length();
  };

  void print() {
    if (!empty())
      head->print();
    std::println("");
  };
};// linklib.hpp -- a sorted linked list that counts repeated values.
// Header-only: used by linktester.cpp (tests) and linkmain.cpp (exercise 10).
#pragma once

#include <print>
#include <memory>
using std::make_shared, std::shared_ptr;

// A node has a value, a count of how often that value was inserted,
// and a link to the next node. A null link marks the end of the list.
class Node {
private:
  int datavalue{0}, datacount{0};
  shared_ptr<Node> next{nullptr};

public:
  Node() {};
  Node(int value, shared_ptr<Node> next = nullptr)
      : datavalue(value), datacount(1), next(next) {};

  int value() { return datavalue; };
  int count() { return datacount; };
  bool has_next() { return next != nullptr; };
  shared_ptr<Node> nextnode() { return next; };

  bool contains_value(int val) {
    if (datavalue == val)
      return true;
    else if (!has_next())
      return false;
    else
      return next->contains_value(val);
  };

  int length() {
    if (!has_next())
      return 1;
    else
      return 1 + next->length();
  };

  // Insert after this node, keeping the list sorted.
  // (List::insert handles a value that goes before the head.)
  void insert(int v) {
    if (v == datavalue)
      datacount += 1;                          // already there: count it
    else if (!has_next() || v < next->datavalue)
      next = make_shared<Node>(v, next);       // goes right after this node
    else
      next->insert(v);                         // keep walking
  };

  // Prints value:count for this node and all later ones, e.g. 5:2 7:1 8:1
  void print() {
    std::print("{}:{}", datavalue, datacount);
    if (has_next()) {
      std::print(" ");
      next->print();
    }
  };
};

class List {
private:
  shared_ptr<Node> head{nullptr};

public:
  List() = default;

  bool empty() { return head == nullptr; };

  // Returns a copy of the first node; throws if the list is empty.
  Node headnode() {
    if (empty())
      throw("empty list has no head node");
    return *head;
  };

  void insert(int value) {
    if (empty())
      head = make_shared<Node>(value);           // first element
    else if (value < head->value())
      head = make_shared<Node>(value, head);     // new head
    else
      head->insert(value);                       // equal, middle or end
  };

  bool contains_value(int val) {
    if (empty())
      return false;
    else
      return head->contains_value(val);
  };

  int length() {
    if (empty())
      return 0;
    else
      return head->length();
  };

  void print() {
    if (!empty())
      head->print();
    std::println("");
  };
};
