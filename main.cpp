#include "cmdline.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  cmdline::parser p; // parser instance

  /*! defined arguments */
  p.add<string> ("pisse", 'x', "pisse harnstoff", true, "");
  p.add<string>("host", 'h', "host name", true, "");
  p.add<int>("port", 'p', "port number", false, 80, cmdline::range(1, 65535));
  p.add<string>("type", 't', "protocol type", false, "http", cmdline::oneof<string>("http", "https", "ssh", "ftp"));
  p.add("gzip", '\0', "gzip when transfer");

  /*! check if arguments are valid */
  p.parse_check(argc, argv);

  cout << p.get<string>("type") << "://"
       << p.get<string>("host") << ":"
       << p.get<int>("port") << ":"
       << p.get<string>("pisse") << endl;

  if (p.exist("gzip")) cout << "gzip" << endl;

  return 0;
}
