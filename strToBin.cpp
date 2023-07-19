#include <string>
#include <bitset>
#include <iostream>
#include <sstream>
//#include "../includes/strToBin.hpp"

using std::string;
string convert_to_bit(string input) {
  std::string binary_outputInformations;
  for (std::size_t i = 0; i < input.size(); ++i)
  {
    std::bitset<8> b(input.c_str()[i]);
    binary_outputInformations += b.to_string();
  }
  return binary_outputInformations;

}
//made this just to justify publishing
string convert_to_string(string input){
  std::string string = "";
  std::stringstream sstream(input);
  while (sstream.good())
  {
    std::bitset<8> bits;
    sstream >> bits;
    char c = char(bits.to_ulong());
    string += c;
  }
  return string;
}

//caso seja rodado sem ser como uma lib (fodase, em português mesmo)
int main()
{
    string conv = "";
    std::cout << "string to bin [1] or bin to string [0] " << std::endl;
    std::cout << "note: any input that is not 1 or 0 will be treated like default [1] " << std::endl;
    std::cout << "1 or 0: ";
    int which = 1;
	std::cin >> which;
    switch(which)
    {
      case 1: default:
        std::cout << "string to convert to bin: ";
        std::cin >> conv ;
        std::cout << convert_to_bit(conv);
        break;
      case 0:
        std::cout << "stirng of bits to convert to text: ";
        std::cin >> conv;
        std::cout << convert_to_string(conv);
        break;
    }
	return 0;
}
