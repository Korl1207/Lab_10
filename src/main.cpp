#include <iostream>
#include <string>
#include <vector>

#include "MyPipeLine.hpp"

int main() {
  // INT
  std::cout << "INT" << std::endl;
  MyPipeLine<int> intPipeline;
  intPipeline.addStep("add 5", [](int x) { return x + 5; });
  intPipeline.addStep("Multiply by 4", [](int x) { return x * 4; });
  intPipeline.addStep("Remainder modulo 20", [](int x) { return x % 20; });

  std::cout << intPipeline;

  int val = 3;
  std::cout << "Input for run(): " << val << std::endl;
  std::cout << "Result: " << intPipeline.run(val) << std::endl << std::endl;

  int valt = 21;
  std::cout << "Input for trace(): " << valt << std::endl;
  std::cout << "Result: " << std::endl;
  std::vector<int> ans = intPipeline.trace(valt);
  for (auto it : ans) std::cout << it << " ";
  std::cout << std::endl << std::endl;

  // STRING
  std::cout << "STRING" << std::endl;
  MyPipeLine<std::string> strPipeline;
  strPipeline.addStep("add prefix Mc", [](std::string s) { return "Mc" + s; });
  strPipeline.addStep("add 'velichaishi'",
                      [](std::string s) { return s + " velichaishi"; });
  strPipeline.addStep("to upper", [](std::string s) {
    for (char& c : s) c = std::toupper(c);
    return s;
  });

  std::cout << strPipeline << std::endl;

  std::string in = "Einstein";
  std::cout << "Input to run: " << in << std::endl;
  std::cout << "Result: " << strPipeline.run(in) << std::endl << std::endl;

  std::cout << "Excetion removeStep: " << std::endl;
  try {
    intPipeline.removeStep(10000);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "Empty name exception: " << std::endl;
  try {
    strPipeline.addStep("", [](std::string s) { return s + " GOOOIDA!"; });
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}