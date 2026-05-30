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
  bool found = false;

  while (!found) {
    if (current->light) {
      found = true;
    } else {
      current->light = true;
      ++countOp;
      current = current->next;
    }
  }

  int length = 1;
  current = current->next;
  ++countOp;

  while (current != first) {
    ++length;
    ++countOp;
    current = current->next;
  }

  return length;
}

int Train::getOpCount() const {
  return countOp;
}
