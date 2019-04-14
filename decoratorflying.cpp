#include <iostream>
#include <memory>
struct Coordinates {
  int x;
  int y;
};

class MovingTarget {
public:
  virtual void Move() = 0;
  virtual ~MovingTarget() {}
};

class F35 : public MovingTarget {
public:
  F35() {
    coordinates.x = 0;
    coordinates.y = 0;
  }
  virtual void Move() {
    for (int i = 0; i < 10; i++){
      coordinates.x =coordinates.x +i;
      coordinates.y = coordinates.y+i;
    std::cout << "X: " << coordinates.x << std::endl;
    std::cout << "Y: " << coordinates.y << std::endl;}
  }

private:
  Coordinates coordinates;
};

class DecorforFuel : public MovingTarget {
  std::shared_ptr<MovingTarget> moving_target;

public:
  DecorforFuel(MovingTarget *target) : moving_target(target) {  }
  virtual void Move() {
    moving_target->Move();
    FuelRequest();
  }

private:
  int fuel=100;
  void FuelRequest() {
    for (int i = 0; i < 10; i++) {
      fuel--;
      std::cout << "Fuel: " << fuel;
    }
  }

};

class DecorforAcceleration : public MovingTarget {
  std::shared_ptr<MovingTarget> moving_target;

public:
  DecorforAcceleration(MovingTarget *target) : moving_target(target){};
  virtual void Move() {
    moving_target->Move();
    std::cout << "  I am stopped";
  }
};
