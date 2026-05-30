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

  while (!current->light) {
    current->light = true;
    ++countOp;
    current = current->next;
  }

  current->light = false;
  int length = 1;
  current = current->next;
  ++countOp;

  while (!current->light) {
    ++length;
    current = current->next;
    ++countOp;
  }

  return length;
}

int Train::getOpCount() const {
  return countOp;
}
