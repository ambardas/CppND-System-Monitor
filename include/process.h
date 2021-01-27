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
  Process(int pid);
  int Pid() const;                         // TODO: See src/process.cpp
  std::string User() const;                // TODO: See src/process.cpp
  std::string Command() const;             // TODO: See src/process.cpp
  float CpuUtilization() const;            // TODO: See src/process.cpp
  std::string Ram() const;                 // TODO: See src/process.cpp
  long int UpTime() const;                 // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp

  // TODO: Declare any necessary private members
 private:
  int pid;
  std::string user;
  float cpu_util;
  std::string ram;
  long int proc_uptime;
  std::string command;
  std::unordered_map<int, std::string> uid_user_map;

  void GetUser();
  void GetCommand();
  void Cpu_Mem_Utime();
};

#endif