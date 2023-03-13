#include <iostream>
#include <string>

class Employee {
public:
  Employee() : id(employee_id()) {}
  explicit Employee(const std::string &p_name)
      : id(employee_id()), name(p_name) {}
  Employee(const Employee &orig) = delete;
  Employee &operator=(const Employee &rhs) = delete;
  int get_id() const { return id; }
  const std::string get_name() const { return name; }

private:
  static int employee_id();

private:
  int id;
  std::string name;
  static int seq;
};
int Employee::seq = 0;
int Employee::employee_id() { return seq++; }

int main() {
  Employee employees[3];
  for (auto &e : employees) {
    std::cout << e.get_id() << ' ';
  }
  const Employee a("123");
  std::cout << a.get_id() << '\n';
  std::cout << a.get_name() << '\n';
  return 0;
}
