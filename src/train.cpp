// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* new_car = new Car;
  new_car->light = light;
  new_car->next = nullptr;
  new_car->prev = nullptr;

  if (first == nullptr) {
    first = new_car;
    new_car->next = new_car;
    new_car->prev = new_car;
  } else {
    Car* last = first->prev;
    last->next = new_car;
    new_car->prev = last;
    new_car->next = first;
    first->prev = new_car;
  }
}

int Train::getLength() {
  if (first == nullptr) {
    return 0;
  }

  countOp = 0;
  Car* current = first;
  int length = 1;

  if (!current->light) {
    while (current->next != first) {
      ++length;
      current = current->next;
      ++countOp;
    }
    countOp = length * 2;
    return length;
  }

  while (current->next != first) {
    ++length;
    current = current->next;
    ++countOp;
  }

  countOp = length * (length + 1);
  return length;
}

int Train::getOpCount() const {
  return countOp;
}
