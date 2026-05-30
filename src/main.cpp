// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
  std::srand(std::time(nullptr));

  std::cout << "n,all_off,all_on,random" << std::endl;

  for (int n = 2; n <= 100; ++n) {
    Train train_off;
    for (int i = 0; i < n; ++i) {
      train_off.addCar(false);
    }
    train_off.getLength();
    int off_ops = train_off.getOpCount();

    Train train_on;
    for (int i = 0; i < n; ++i) {
      train_on.addCar(true);
    }
    train_on.getLength();
    int on_ops = train_on.getOpCount();

    Train train_rand;
    for (int i = 0; i < n; ++i) {
      train_rand.addCar(std::rand() % 2 == 0);
    }
    train_rand.getLength();
    int rand_ops = train_rand.getOpCount();

    std::cout << n << "," << off_ops << "," << on_ops
              << "," << rand_ops << std::endl;
  }

  return 0;
}
