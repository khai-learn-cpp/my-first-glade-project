#include <gtkmm.h>
#include <glibmm.h>

template <class Base> struct Inherit : Base {
  template <class ...Param> Inherit (Param ...param) : Base(param ...) {}
};

template <class Base> struct BasicConnectSignal : Base {
  typedef Glib::SignalProxy0<void> SignalProxy;
  template <class ...Param> BasicConnectSignal (Param ...param) : Base(param ...) {}
  auto connect (SignalProxy signal) {
    return signal.connect(sigc::mem_fun(* this, & Base::call));
  }
};

template <class Base> using ConnectSignal = Inherit<BasicConnectSignal<Base>>;

int main (int argc, char ** argv) {
  using namespace Gtk;
  auto app = Application::create(argc, argv, "org.gtkmm.my-first.base");
  auto builder = Builder::create_from_file("ui.glade");
  Window * window = nullptr;
  builder->get_widget("main-window", window);
  Button * close = nullptr;
  builder->get_widget("close-button", close);
  struct OnClickClose {
    typedef Window Widget;
    Widget * widget;
    void call () {
      delete widget;
    }
  } onClickClose = {window};
  ConnectSignal<OnClickClose>(onClickClose).connect(close->signal_clicked());
  return app->run(* window);
}
