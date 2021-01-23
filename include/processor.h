#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "linux_parser.h"

#include <string>
#include <fstream>
#include <sstream>

using std::string;

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  float idle = 0.0;
  float iowait = 0.0;
  float irq = 0.0;
  float nice = 0.0;
  float softirq = 0.0;
  float steal = 0.0;
  float system = 0.0;
  float user = 0.0;

  float guest = 0.0;
  float guest_nice = 0.0;

  float previdle = 0.0;
  float previowait = 0.0;
  float prevuser = 0.0;
  float prevnice = 0.0;
  float prevsystem = 0.0;
  float previrq = 0.0;
  float prevsoftirq = 0.0;
  float prevsteal = 0.0;

  float PrevIdle = 0.0;
  float PrevNonIdle = 0.0;
  float PrevTotal = 0.0;
  float Idle = 0.0;
  float NonIdle = 0.0;
  float Total = 0.0;

  float totald = 0.0;
  float idled = 0.0;

  float CPU_Percentage = 0.0;

  void read_raw_cpu_stats();
  void compute_cpu_util();
  void update_prev_values();
};

#endif