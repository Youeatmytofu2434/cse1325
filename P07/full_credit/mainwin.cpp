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
  
  Gtk::MenuItem *menuitem_relate = Gtk::manage (new Gtk::MenuItem ("_Relate", true));
  menubar -> append (*menuitem_relate);
  Gtk::Menu *relatemenu = Gtk::manage (new Gtk::Menu());
  menuitem_relate -> set_submenu (*relatemenu);
  
  Gtk::MenuItem *menuitem_student_parent - Gtk::manage (new Gtk::MenuItem ("_Student to Parent", true));
  menuitem_student_parent->signal_activate().connect ([this]{this->on_student_parent_click();});
  relatemenu->append(*menuitem_student_parent);
  
  display = Gtk::manage (new Gtk::label());
  display->set_hexpand(true);
  display->set_vexpand(true);
  vbox->add(*display);
  
  msg = Gtk::manage (new Gtk::Label());
  msg->set_hexpand(true);
  vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
  vbox -> add (*msg);
  vbox->show_all();
  
  on_new_school_click();
}

Gtk::ToolBar *toolbar = Gtk::manage (new Gtk::Toolbar);
vbox->pack_start (*toolbar, Gtk::PACK_SHRINK, 0);
vbox->add (*toolbar);

Gtk::ToolButton *new_school_button = Gtk::manage (new Gtk::ToolButton(Gtk::Stock::NEW));
new_school_button->set_tooltip_markup ("Create a new school");
new_school_button->signal.clicked().connect([this]{this->on_new_school_click});
toolbar->append (*new_school_button);

Gtk::ToolButton *new_open_button = Gtk::manage (new Gtk::ToolButton(Gtk::Stock::OPEN));
new_open_button->set_tooltip_markup ("Open school to this file");
new_open_button->signal_clicked().connect ([this]{this->on_open_click();});
toolbar->append (*new_open_button);

Gtk::ToolButton *new_save_button = Gtk::manage (new Gtk::ToolButton(Gtk::Stock::SAVE));
new_save_button->set_tooltip_markup ("Save school to this file");
new_save_button->signal_clicked().connect ([this]{this->on_save_click();});
toolbar->append (*new_save_button);

Gtk::ToolButton *new_save_as_button = Gtk::manage (new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
new_save_as_button->set_tooltip_markup ("Save school to a new file");
new_save_as_button->signal_clicked().connect ([this]{this->on_save_as_click();});
toolbar->append (*new_save_as_button);

Gtk::Image* student_image = Gtk::manage (new Gtk::Image {"Student1.png"});
Gtk::ToolButton *student_button = Gtk::manage (new Gtk::ToolButton(*student_image));
student_button->set_tooltip_markup ("Create a new student");
student_button->signal_clicked().connect ([this]{this->on_new_student_click();});
toolbar->append (*student_button);

Gtk::Image* parent_image = Gtk::manage (new Gtk::Image {"Parent1.png"});
Gtk::ToolButton *parent_button = Gtk::manage (new Gtk::ToolButton(*parent_image));
parent_button->set_tooltip_markup ("Create a new parent");
parent_button->signal_clicked().connect ([this]{this->on_new_parent_click();});
toolbar->append (*parent_button);

Gtk::Image* ps_relate_image = Gtk::manage (new Gtk::Image {"ParentStudentRelate.png"});
Gtk::ToolButton *ps_relate_button = Gtk::manage (new Gtk::ToolButton(*ps_relate_image));
ps_relate_button->set_tooltip_markup ("Relate student to parent");
ps_retate_button->signal_clicked().connect ([this]{this->on_student_parent_click();});
toolbar->append (*ps_relate_button);

Mainwwin::~Mainwin() {}

void Mainwin::on_new_school_click() {
  students.clear();
  parents.clear();
  show_data();
}

void Mainwin::on_new_student_click() {
  try {
    EntryDialog name {*this, "Student name?"};
    if (name.run() == Gtk::RESPONSE_OK) name.hide();
    else return;
    
    EntryDialog email {*this, "Student email?"};
    if (email.run() == Gtk::RESPONSE_OK) email.hide();
    else return;
    
    int grade = select ("Student grade?", 12, 1);
    if (grade < 1) return;
    students.push_back(Student{name.get_text(), email.get_text(), grade}); 
  } catch (std::exception& e){
    Gtk::MessageDialog {*this, "Invalid entry!" + std::string {e.what()}}.run();
  }
  show_data();
}

void Mainwin::on_new_parent_click() {
  try {
    EntryDialog name {*this, "Parent name?"};
    if (name.run() == Gtk::RESPONSE_OK) name.hide();
    else return;
    
    EntryDialog email {*this, "Parent email?"};
    if (email.run() == Gtk::RESPONSE_OK) email.hide();
    else return;
    
    parents.push_back (Parent{name.get_text(), email.get_text()});
  } catch (std::exception& e){
    Gtk::MessageDialog {*this, e.what()}.run();
  }
  show_data();
}

void Mainwin::on_student_parent_click() {
  try {
    int student = select_student(); if (student < 0) return;
    int parent = select_parent(); if (parent < 0) return;
    students.at(student).add_parent (parents.at(parent));
    parents.at(parent).add_student (students.at(student));
  } catch (std::exception& e) {
      Gtk::MessageDialog {*this, e.what()}.run();
  }
  show_data();
}

void Mainwin::on_quit_click() {
  close();
}

void Mainwin::show_data() {
  std::string s;
  s += "    Students\n\n";
  for (int i = 0; i < students.size(); ++i)
    s += students.at(i).full_info()+ '\n';
  s += "\n    Parents\n\n";
  for (int i = 0; i < parents.size(); ++i)
    s += parents.at(i).full_info() + '\n';
  
  display->set_markup(s);
}

void Mainwin::on_about_click() {
  Gtk::AboutDialog dialog;
  dialog.set_transient_for {*this};
  dialog.set_program_name (TITLE);
  auto logo = Gdk::Pixbuff::create_from_file ("LogoForSmart.png");
  dialog.set_logo (logo);
  dialog.set_version ("Version " + VERSION);
  dialog.set_copyright ("Copyright " + COPYRIGHT);
  dialog.set_license_type (Gtk::License::LICENSE_GPL_3_0);
  std::vector <Glib::ustring> authors = {"Man M. Luu with the help of Professor Goerge F. Rice"};
  dialog.set_authors (authors);
  std::vector <Glib::ustring> artists = {"White_Hughes, licensed under the Pixabay License https://pixabay.com/photos/girl-woman-people-fashion-portrait-4703641/"};
dialog.set_artists (artists);
dialog.run();
}

int Mainwin::select_student() {
  std::string prompt = "Select Student\n\n";
  for (int i = 0; i < students.size(); ++i)
    prompt += std::to_string(i) + ") " + students [i].to_string() = '\n';
  return select (prompt, students.size()-1);
}

int Mainwin::select_parent() {
  std::string prompt = "Slect Parent\n\n";
  for (int i = 0; i < parents.size(); ++i)
    prompt += std::to_string(i) + ") " + parents[i].to_string() + '\n';
  return select (prompt, parents,size()-1);
}

int Mainwin::select (std::string prompt, int max, int min){
  int selection = min-1;
  while (true){
    try {
      EntryDialog dialog {*this, prompt};
      int repsonse = dialog.run();
      if (response == Gtk::RESPONSE_OK){
        selection = std::stoi (dialog.get_text());
        if (min <= selection && selection <= max) break;
        throw std::out_of_range {"Invalid selection"};
      } else {
        selection = min-1;
        break;
      }
    } catch (std::exception& e){
      Gtk::MessageDialog {*this, e.what()}.run();
    }
  }
  return selection;
}
