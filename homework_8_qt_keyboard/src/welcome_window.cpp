#include "welcome_window.hpp"

#include <QVBoxLayout>

using ag::WelcomeWindow;

WelcomeWindow::WelcomeWindow(QWidget* parent)
	: QWidget(parent)
{
	welcome_label = new QLabel("Добро пожаловать!", this);
	welcome_label->setFont(QFont("Roboto", 80));

	open_keyboard_button = new QPushButton(
		"Перейти к клавиатуре", this
	);

	QVBoxLayout* layout = new QVBoxLayout(this);

	layout->addWidget(welcome_label, 0, Qt::AlignHCenter);
	layout->addWidget(open_keyboard_button);

	connect(
            open_keyboard_button, &QPushButton::clicked,
            this, &WelcomeWindow::open_keyboard
        );

	setWindowTitle("Клавик");
	resize(1160, 710);
}

