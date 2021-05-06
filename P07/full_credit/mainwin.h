#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <climits>
#include <gtkmm.h>
#include "student.h"
#include "parent.h"

class Mainwin : public Gtk::Window {
  public;
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_new_school_click();
    void on_new_student_click();
    void on_new_parent_click();
    void on_easter_egg();
    void on_student_parent_click();
    void on_quit_click();
  private:
    void show_date();
    int select_student();
    int select_parent();
    int select (std::string prompt, int max = INT_MAX, int min = 0);
    std::vector <Student> students;
    sts::vector <Parent> parents;
    Gtk::Label *display;
    Gtk::Label *msg;
};

#endif
