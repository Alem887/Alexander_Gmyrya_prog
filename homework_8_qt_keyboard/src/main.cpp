#include <QApplication>
#include <QObject>


#include "keyboard_window.hpp"
#include "welcome_window.hpp"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	
    ag::KeyBoardWindow keyboard_window;
	ag::WelcomeWindow welcome_window;
	
    welcome_window.show();
	
	QObject::connect(&welcome_window, &ag::WelcomeWindow::open_keyboard, &keyboard_window, &ag::KeyBoardWindow::show_keyboard);
	QObject::connect(&keyboard_window, &ag::KeyBoardWindow::window_shown, &welcome_window, &ag::WelcomeWindow::close);
	
    return app.exec();
}
