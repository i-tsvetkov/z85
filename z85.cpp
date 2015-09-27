#include <iostream>
#include <vector>
#include <string>
#include "lib-z85/z85.hpp"

using namespace std;
using namespace z85;

int main(int argc, char *argv[])
{
  string cmd("");

  if (argc > 1)
    cmd = argv[1];

  if (argc != 2 || (cmd != "-e" && cmd != "-d"))
  {
    cerr << "usage: -e|-d" << endl;
    return 1;
  }

  vector<char> input;

  for(char c; cin.read(&c, 1); input.push_back(c));

  string output;

  if (cmd == "-e")
    output = encode_with_padding(input.data(), input.size());
  else if (cmd == "-d")
    output = decode_with_padding(input.data(), input.size());

  for (auto c : output)
    cout << c;
}

