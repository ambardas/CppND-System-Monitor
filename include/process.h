#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <unordered_map>

#include "linux_parser.h"

#define hertz sysconf(_SC_CLK_TCK)
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid, std::unordered_map<int, std::string> uid_user_map);
  int Pid();                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization();                  // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp
  void Cpu_Mem_Utime();

  // TODO: Declare any necessary private members
 private:
  int pid;
  std::string user;
  float cpu_util;
  std::string ram;
  long int uptime;
  std::string command;
  std::unordered_map<int, std::string> uid_user_map;
};

#endif