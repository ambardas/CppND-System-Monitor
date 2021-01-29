#ifndef NCURSES_DISPLAY_H
#define NCURSES_DISPLAY_H

#include <curses.h>

#include "process.h"
#include "system.h"

namespace NCursesDisplay {
void Display(System& system, int n = 10); 
// If you want to change the number of processes to be displayed in the main window 
// change the above n = 10 to a different number.  
void DisplaySystem(System& system, WINDOW* window);
void DisplayProcesses(std::vector<Process>& processes, WINDOW* window, int n);
std::string ProgressBar(float percent);
};  // namespace NCursesDisplay

#endif
