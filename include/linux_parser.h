#ifndef SYSTEM_PARSER_H
#define SYSTEM_PARSER_H

#include <process.h>

#include <fstream>
#include <regex>
#include <string>
#include <unordered_map>

namespace LinuxParser {
// Paths
const std::string kProcDirectory{"/proc"};
const std::string kCmdlineFilename{"/cmdline"};
const std::string kCpuinfoFilename{"/cpuinfo"};
const std::string kStatusFilename{"/status"};
const std::string kStatFilename{"/stat"};
const std::string kUptimeFilename{"/uptime"};
const std::string kMeminfoFilename{"/meminfo"};
const std::string kVersionFilename{"/version"};
const std::string kOSPath{"/etc/os-release"};
const std::string kPasswordPath{"/etc/passwd"};

// Filters for value lookup by keys inside files
const std::string filterProcesses("processes");
const std::string filterRunningProcesses("procs_running");
const std::string filterMemTotalString("MemTotal:");
const std::string filterMemAvailableString("MemAvailable:");
const std::string filterUID("Uid:");
const std::string filterCpu("cpu");
const std::string filterProcMem("VmData:");

// System
float MemoryUtilization();
long UpTime();
std::vector<int> Pids();
int TotalProcesses();
int RunningProcesses();
std::string OperatingSystem();
std::string Kernel();

// CPU
enum CPUStates {
  kUser_ = 0,
  kNice_,
  kSystem_,
  kIdle_,
  kIOwait_,
  kIRQ_,
  kSoftIRQ_,
  kSteal_,
  kGuest_,
  kGuestNice_
};
std::vector<std::string> CpuUtilization();
long Jiffies();
long ActiveJiffies();
long ActiveJiffies(int pid);
long IdleJiffies();

// Processes
std::unordered_map<int, std::string> Uid_User_Map();
std::string Command(int pid);
std::string Ram(int pid);
std::string Uid(int pid);
std::string User(int pid);
long int UpTime(int pid);

// Template of file parsers
template <typename T>
T getFileValue(std::string const &fileLocation);
template <typename T>
T getFileValueByKey(std::string const &fileLocation, std::string const &myKey);

};  // namespace LinuxParser

#endif