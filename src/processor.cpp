#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  read_raw_cpu_stats();
  compute_cpu_util();
  return CPU_Percentage;
}

void Processor::update_prev_values() {
  previdle = idle;
  previowait = iowait;
  prevuser = user;
  prevnice = nice;
  prevsystem = system;
  previrq = irq;
  prevsoftirq = softirq;
  prevsteal = steal;
}

void Processor::read_raw_cpu_stats() {
  string cpu, line;
  std::ifstream stream(LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream my_stream(line);
    my_stream >> cpu >> user >> nice >> system >> idle >> iowait >> irq >>
        softirq >> steal >> guest >> guest_nice;
  }
}

void Processor::compute_cpu_util() {
  // From https://stackoverflow.com/a/23376195
  PrevIdle = previdle + previowait;
  Idle = idle + iowait;

  PrevNonIdle =
      prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal;
  NonIdle = user + nice + system + irq + softirq + steal;

  PrevTotal = PrevIdle + PrevNonIdle;
  Total = Idle + NonIdle;

  // differentiate : actual value minus the previous one
  totald = Total - PrevTotal;
  idled = Idle - PrevIdle;

  CPU_Percentage = (totald - idled) / totald;
  update_prev_values();
}
