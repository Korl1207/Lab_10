#ifndef MYPIPELINE_HPP

#define MYPIPELINE_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class MyPipeLine {
  struct Step {
    std::string name;
    std::function<T(T)> func;
  };
  std::vector<Step> steps;

 public:
  MyPipeLine() {};
  size_t size() const { return steps.size(); }
  bool empty() const { return steps.empty(); }
  void clear() { steps.clear(); }

  template <typename F>
  void addStep(const std::string& name, F func);
  void removeStep(size_t index);

  T run(T value) const;

  std::vector<T> trace(T value) const;

  friend std::ostream& operator<<(std::ostream& os, MyPipeLine<T>& pipeline) {
    std::cout << "-------------------------" << std::endl;
    os << "PipeLine with " << pipeline.steps.size() << " steps:" << std::endl;
    for (size_t i = 0; i < pipeline.steps.size(); ++i) {
      os << i + 1 << ") " << pipeline.steps[i].name << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    return os;
  }
};

template <typename T>
template <typename F>
void MyPipeLine<T>::addStep(const std::string& name, F func) {
  if (name.empty()) {
    throw std::invalid_argument("ERROR: StepName cannot be empty");
  }
  steps.push_back({name, func});
}

template <typename T>
void MyPipeLine<T>::removeStep(size_t index) {
  if (index >= steps.size()) {
    throw std::out_of_range("ERROR: index out of range");
  }
  steps.erase(steps.begin() + index);
}

template <typename T>
T MyPipeLine<T>::run(T value) const {
  T curVal = value;
  for (const auto& step : steps) {
    curVal = step.func(curVal);
  }
  return curVal;
}

template <typename T>
std::vector<T> MyPipeLine<T>::trace(T value) const {
  std::vector<T> res;
  if (steps.empty()) return res;
  T curVal = value;
  for (const auto& step : steps) {
    curVal = step.func(curVal);
    res.push_back(curVal);
  }
  return res;
}

#endif  // MYPIPELINE_HPP
