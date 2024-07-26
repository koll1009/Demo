#include "gtest/gtest.h"
#include <bits/getopt_core.h>
#include <iostream>
#include <iterator>
#include <getopt.h>


TEST(StdTest, GetOptLongTest)
{
/* extern char *optarg;
   extern int optind, opterr, optopt; */

  int flag = 0; 
  struct option long_opts[] = {
    {"option1", no_argument, &flag, 1},
    {"option2", optional_argument, &flag, 0},
    {"option3", no_argument, NULL, 'a'}, //getopt_long will return 'a'
    {"option4", required_argument, NULL, 'b'},
    {0,0,0,0}
  };

  char cmd[] = "cmdline";

  char s_argv0[] = "-a";
  char s_argv1[] = "-b";
  char s_argv2[] = "-c";
  char s_argv2_value[] = "value_C";
  char s_argv3[] = "-d";

  char separator[] = "--"; // will cause getopt_long return

  char argv1[] = "--option1";
  char argv2[] = "--option2=option2";
  char argv3[] = "--option3";
  char argv4[] = "--option4=option4";


  char* const argv[] = {cmd, s_argv0, s_argv1, s_argv2, s_argv2_value, s_argv3, separator, argv1, argv2, argv3, argv4};

  //c: means it require argument
  //d:: means its argument is optional
  const char* optstring = "abc:d::";

  int optIndex = 0;
  int opt;

  auto output = [&argv, &long_opts](int opt, int optIndex){
    switch (opt) {
      case 'a':
        if(optIndex){
          //optIndex will point to the index in long opt array.
          std::cout << long_opts[optIndex].name <<  "\n";
        }
        std::cout << "a\n";
        break;
      case 'b':
        std::cout << "b\n";
        break;
      case 'c':
        std::cout << "c:" << optarg << "\n";
        break;
      case 'd':
        std::cout << "d:" << (optarg ? optarg : "null") << "\n";
        break;
      case 0:
        std::cout << long_opts[optIndex].name << "\t flag:" << *long_opts[optIndex].flag << std::endl;
        break;
      case '?':
        std::cout << "help\n";
        break;
      default:
        abort();
    }
  };

  // optind holds the index of the next element of the argv array that will be processed.
  // Due to cmdline, optind will start from 1. set to 0 will cause uncertain behavior

  std::cout << std::endl << "the start index is " << optind << std::endl << std::endl;

  while((opt = getopt_long(sizeof(argv)/sizeof(argv[0]), argv, optstring, long_opts, &optIndex)) != -1)
  {
    output(opt, optIndex);
  }

  std::cout << std::endl << "the next index is " << optind << std::endl << std::endl;

  while((opt = getopt_long(sizeof(argv)/sizeof(argv[0]), argv, optstring, long_opts, &optIndex)) != -1)
  {
    output(opt, optIndex);
  }

}