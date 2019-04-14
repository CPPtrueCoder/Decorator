#include <iostream>
#include "decoratorflying.cpp"

template <typename T>
[[nodiscard]] auto AskCoordinate() noexcept{
  T coordinate ;
  std::cin>>coordinate;
  return coordinate;
}
template <typename T>
[[nodiscard]]Coordinates SetCoordinates() noexcept {
  return {AskCoordinate<T>(),AskCoordinate<T>()};
}

template  <typename T>
[[nodiscard]] auto AskForFuel() {
  T fuel;
  std::cin>>fuel;
  return fuel;
}
