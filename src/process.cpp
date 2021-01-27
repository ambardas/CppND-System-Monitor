#include "process.h"

#include <unistd.h>

#include <cctype>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

// Constructor for Process
Process::Process(int pid, std::unordered_map<int, string> uid_user_map)
    : pid(pid), uid_user_map(uid_user_map) {
  Cpu_Mem_Utime();
  GetUser();
  GetCommand();
};

// TODO: Return this process's ID
int Process::Pid() const { return pid; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const { return cpu_util; }

// TODO: Return the command that generated this process
string Process::Command() const {
  string trunc_command;
  if (command.size() > 40) {
    trunc_command = command.substr(0, 37) + "...";
  } else if (command.size() == 0) {
    trunc_command = " ";
  } else {
    trunc_command = command;
  }

  return trunc_command;
}

// TODO: Return this process's memory utilization
string Process::Ram() const { return ram; }

// TODO: Return the user (name) that generated this process
string Process::User() const { return user; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() const { return proc_uptime; }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
  return a.CpuUtilization() < this->CpuUtilization();
}

void Process::Cpu_Mem_Utime() {
  // https://man7.org/linux/man-pages/man5/proc.5.html
  // https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat/16736599#16736599
  // int hertz = sysconf(_SC_CLK_TCK); // convert to compiletime const
  string user_file = LinuxParser::kProcDirectory + "/" + to_string(pid) +
                     LinuxParser::kStatFilename;
  string line, stat2, stat3;
  long int stat1, stat4, stat5, stat6, stat7, stat8, stat9, stat10, stat11,
      stat12, stat13, stat14, stat15, stat16, stat17, stat18, stat19, stat20,
      stat21, stat22, stat23, stat24, stat25, stat26, stat27, stat28, stat29,
      stat30, stat31, stat32, stat33, stat34, stat35, stat36, stat37, stat38,
      stat39, stat40, stat41, stat42, stat43, stat44, stat45, stat46, stat47,
      stat48, stat49, stat50, stat51, stat52;
  std::ifstream filestream(user_file);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> stat1 >> stat2 >> stat3 >> stat4 >> stat5 >> stat6 >>
          stat7 >> stat8 >> stat9 >> stat10 >> stat11 >> stat12 >> stat13 >>
          stat14 >> stat15 >> stat16 >> stat17 >> stat18 >> stat19 >> stat20 >>
          stat21 >> stat22 >> stat23 >> stat24 >> stat25 >> stat26 >> stat27 >>
          stat28 >> stat29 >> stat30 >> stat31 >> stat32 >> stat33 >> stat34 >>
          stat35 >> stat36 >> stat37 >> stat38 >> stat39 >> stat40 >> stat41 >>
          stat42 >> stat43 >> stat44 >> stat45 >> stat46 >> stat47 >> stat48 >>
          stat49 >> stat50 >> stat51 >> stat52;

      long int total_time = stat14 + stat15 + stat16 + stat17;
      ram = to_string(stat23 / 1024);
      proc_uptime = LinuxParser::UpTime() - (stat22 / hertz);
      cpu_util = (total_time / hertz) / (proc_uptime + (proc_uptime <= 0));
    }
  }
}

void Process::GetUser() {
  string status_file = LinuxParser::kProcDirectory + "/" + to_string(pid) +
                       LinuxParser::kStatusFilename;
  string line;
  string stat_name;
  int an_id;
  std::ifstream filestream(status_file);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> stat_name >> an_id) {
        if (stat_name == "Uid:") {
          user = uid_user_map[an_id];
        }
      }
    }
  }
}

void Process::GetCommand() {
  string user_file = LinuxParser::kProcDirectory + "/" + to_string(pid) +
                     LinuxParser::kCmdlineFilename;
  string line;
  std::ifstream filestream(user_file);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      command = line;
    }
  }
}