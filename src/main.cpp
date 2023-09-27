#include <chrono>
#include <csignal>
#include <cstdlib>
#include <iostream>
#include <thread>

extern "C" void quit(int /*signal*/) {
  std::exit(0);
}

int main() {
  std::signal(SIGTERM, &quit);
  for (;;) {
    std::cout << "Hello, world!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
}
