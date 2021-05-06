#include "mainwin.h"
#include "entrydialog.h"

const int MAX_STUDENTS = 100;
const int MAX_PARENTS = 400;

Mainwin::Mainwin() {
  students.reserve (MAX_STUDENTS);
  parents.reserve (MAX_PARENTS);
  
  set_default_size (400,200);
  set_title ("SMART");
  
  Gtk::Box *vbox = Gtk::manage (new Gtk::Vbox);
  add (*vbox);
  
  Gtk::MenuBar *menubar = Gtk::manage (new Gtk:MenuBar);
  vbox->pack_start (*menubar, Gtk::PACK_SHRINK, 0);
  vbox->add (*menubar);
  
  Gtk::MenuItem *menuitem_file = Gtk::manage (new Gtk::MenuItem ("_File", true));
  menubar->append (*menuitem_file);
  Gtk::Menu *filemenu = Gtk::manage (new Gtk::Menu());
  menuitem_file -> set_submenu (*filemenu);
  
  Gtk::MenuItem *menuitem_new = Gtk::mange (new Gtk::MenuItem ("_New School", true));
  menuitem_new->signal_activate().connect ([this] {this->on_new_school_click();});
  filemenu->append (*menuitem_new);
  
  Gtk::MenuItem *menuitem_neww = Gtk::mange (new Gtk::MenuItem ("_Quit", true));
  menuitem_quit->signal_activate().connect ([this] {this->on_quit_click();});
  
  Gtk::MenuItem *menuitem_insert = Gtk::mange (new Gtk::MenuItem ("_Insert", true));
}
