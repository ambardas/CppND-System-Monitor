#include <string>

#include "format.h"

using std::string;

string nice_string(int time_unit){
  string str_time_unit = std::to_string(time_unit);
  if (time_unit < 10){
    str_time_unit = "0"+str_time_unit;
  }
  return str_time_unit;
}

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
  int hours, minutes, only_seconds;

  hours = seconds /3600;
  minutes = (seconds/60) - (hours*60);
  only_seconds = seconds - (hours*3600) - (minutes*60);
  return  nice_string(hours) + ":" + nice_string(minutes) + ":" + nice_string(only_seconds); 
}