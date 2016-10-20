#include <gtkmm.h>

int main (int argc, char ** argv) {
  using namespace Gtk;
  auto app = Application::create(argc, argv, "org.gtkmm.my-first.base");
  auto builder = Builder::create_from_file("ui.glade");
  Window * window = nullptr;
  builder->get_widget("main-window", window);
  return app->run(* window);
}
