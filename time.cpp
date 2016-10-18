#include <string>
#include <chrono>
#include "comm.h"
using namespace std;



int main(int argc, char const *argv[]) {
  string cmd;
  for(int i = 1; i < argc; i++)
    cmd += argv[i];
  auto start = chrono::steady_clock::now();
  cout << exec(cmd) << endl;
  auto end = chrono::steady_clock::now();
  auto time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  cout << (time / 1000000000) << '.' << (time % 1000000000) << endl;

  return 0;
}