#pragma once
class StaticMember {
 private:
  static int amount;

 public:
  StaticMember() { amount++; }
  int getAmount() { return amount; }
};
