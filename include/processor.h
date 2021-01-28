#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "linux_parser.h"

#include <string>
#include <fstream>
#include <sstream>

using std::string;

class Processor {
 public:
  double Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  double idle = 0.0;
  double iowait = 0.0;
  double irq = 0.0;
  double nice = 0.0;
  double softirq = 0.0;
  double steal = 0.0;
  double system = 0.0;
  double user = 0.0;

  double guest = 0.0;
  double guest_nice = 0.0;

  double previdle = 0.0;
  double previowait = 0.0;
  double prevuser = 0.0;
  double prevnice = 0.0;
  double prevsystem = 0.0;
  double previrq = 0.0;
  double prevsoftirq = 0.0;
  double prevsteal = 0.0;

  double PrevIdle = 0.0;
  double PrevNonIdle = 0.0;
  double PrevTotal = 0.0;
  double Idle = 0.0;
  double NonIdle = 0.0;
  double Total = 0.0;

  double totald = 0.0;
  double idled = 0.0;

  double CPU_Percentage = 0.0;

  void read_raw_cpu_stats();
  void compute_cpu_util();
  void update_prev_values();
};

#endif