#include <iostream>
#include <memory>
struct Coordinates {
  int x;
  int y;
};

class MovingTarget {
 public:
  MovingTarget() = default ;
  MovingTarget(const MovingTarget&)=delete ;
  MovingTarget& operator=(const MovingTarget&)=delete;
  virtual void Move() = 0;
  virtual ~MovingTarget()=default;
};

class F35 : public MovingTarget {
 public:
  F35():coordinates_{0,0} {

  }
  virtual void Move()
   {
      coordinates_.x += 1;
      coordinates_.y += 1;
      std::cout << "X: " << coordinates_.x <<" ";
      std::cout << "Y: " << coordinates_.y <<" ";
  }

 private:
  Coordinates coordinates_;
};

class FuelDepended : public MovingTarget {
  std::unique_ptr<MovingTarget> moving_target;

 public:
  FuelDepended( std::unique_ptr<MovingTarget>&& moving_target) : moving_target{std::move(moving_target)},fuel_(100) {}
  virtual void Move() {
    for (int i =0 ; i<10;++i){
    moving_target->Move();
    FuelRequest();
    }
  }

 private:
  std::unique_ptr<MovingTarget> moving_target_;
  int fuel_;
  void FuelRequest() {
      fuel_-=1;
      std::cout << "Fuel: " << fuel_<<"; ";

  }
};

class AccelerationDepended : public MovingTarget {
  std::unique_ptr<MovingTarget> moving_target_;

 public:
  AccelerationDepended(std::unique_ptr<MovingTarget> &&moving_target) : moving_target_{std::move(moving_target)}{};
  virtual void Move() {
    moving_target_->Move();
    std::cout <<std::endl<< "  I am stopped";
  }
};
