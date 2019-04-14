#include <iostream>
#include<memory>
#include"decoratorflying.cpp"

int main (){
  std::cout<<" The program started"<<std::endl;
  AccelerationDepended F35A (std::make_unique<FuelDepended>(std::make_unique<F35>()));
  F35A.Move();
}
