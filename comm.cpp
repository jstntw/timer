#include "comm.h"

using namespace std;
string exec(string cmd) {
  char buffer[128];
  string result = "";
  shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
  if (!pipe)
    throw std::runtime_error("popen() failed!");
  while (!feof(pipe.get())) {
    if (fgets(buffer, 128, pipe.get())) {
      result += buffer;
    }
  };
  return result;
}