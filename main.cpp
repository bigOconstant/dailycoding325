#include <iostream>
#include <vector>
#include <unordered_map>



  //Pick a base system. For this lets say inches. Everything will be relative of inches
  // Uses a map to convert between them and a convert function. Simple and runs in O(1); Constant time
  //  std::unordered_map<std::string,double> converter;
struct converter{
  converter(){
    this->units.insert({"inches",1.0});
    this->units.insert({"feet",12.0});
    this->units.insert({"yard",(3.0*12.0)});
    this->units.insert({"chain",(22*(3*12.0))});
  }

  double convert(double quantity, std::string input1,std::string input2){
    auto ita = units.find(input1);
    auto itb = units.find(input2);

    if(ita != units.end() && itb != units.end()) {// found something
      return quantity * ita->second / itb->second;
    }else{
      return 0.0;
    }
    
  }
  
private:
  //Units can be private. We can add new items in the constructor
  std::unordered_map<std::string,double> units;
  
};


int main() {

  auto unit_converter = new converter();

  std::cout<<"3 feet = how many yards:"<<unit_converter->convert(3,"feet","yard")<<std::endl;
  std::cout<<"13 inches = how many feet:"<<unit_converter->convert(13,"inches","feet")<<std::endl;
  std::cout<<"13 inches = how many feet:"<<unit_converter->convert(13,"inches","feet")<<std::endl;
  std::cout<<"1 chain = how many inches:"<<unit_converter->convert(1,"chain","inches")<<std::endl;

  
}
