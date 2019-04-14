#include <iostream>
#include<memory>
#include"decoratorflying.cpp"

/*class Icomponent {

public:
  virtual void Operation ()=0;
  virtual ~Icomponent(){};
};

class Component: public Icomponent {
public :
  virtual void Operation (){
    std::cout<<" World"<<std::endl;
  }
};
class DecoratorOne :public Icomponent{
  std::shared_ptr<Icomponent>m_component;
public:
  DecoratorOne ( Icomponent* component):m_component(component){

  }
  virtual void Operation(){
    std::cout<<",";
    m_component->Operation();
  }
};
class DecoratorTwo : public Icomponent{
  std::shared_ptr<Icomponent> m_component;
public :
  DecoratorTwo ( Icomponent* component ):m_component(component){

  }
  virtual void Operation () {
    std::cout<<" Hello";
    m_component->Operation() ; }
};*/


int main (){
  std::cout<<" The program started"<<std::endl;
  DecorforAcceleration F35A(new DecorforFuel (new F35()));
F35A.Move();
}
