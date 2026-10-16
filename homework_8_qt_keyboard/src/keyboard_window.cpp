#include "keyboard_window.hpp"

#include <iostream>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QString>


using ag::KeyBoardWindow;

KeyBoardWindow::KeyBoardWindow(QWidget* parent) : QWidget(parent) {
	const int keyboard_width = 1160;
	resize(keyboard_width, 710);
    setWindowTitle("Весёлая клавиатура");
	
	QPixmap pixmap("img/veseli_smile.jpg");
	QLabel* image = new QLabel(this);
	image->setFixedSize(200, 200);
	image->setPixmap(pixmap);
	image->setScaledContents(true);
	
	QHBoxLayout* smail_layout = new QHBoxLayout();
	smail_layout->addWidget(image);

    display = new QLineEdit();
	display->setMinimumHeight(80);
	display->setFont(QFont("Roboto", 40));
    display->setReadOnly(true);
	display->setText("Всё работает лучше!");

	keyboard = new KeyBoard(keyboard_width);

    QVBoxLayout* main_layout = new QVBoxLayout(this);
	main_layout->addLayout(smail_layout);
    main_layout->addWidget(display);
    main_layout->addWidget(keyboard);
	
	connect(this, &KeyBoardWindow::physical_key_pressed, this, &KeyBoardWindow::use_key);
	connect(keyboard, &KeyBoard::virtual_key_pressed, this, &KeyBoardWindow::use_key);
}

void KeyBoardWindow::keyPressEvent(QKeyEvent* event) {
	const int key = event->nativeVirtualKey();
	std::cout << "Нажата клавиша" << " " << key << std::endl;

	if (keyboard->is_key_allowed(key)) {
		QString text = keyboard->get_key_text(key); 
		emit physical_key_pressed(text); 
	} 
	else if (key == 8) {
		emit physical_key_pressed("BACKSPACE");
		std::cout << "Нажат Backspace" << std::endl;
	} 
	else if (key == 13) {
		emit physical_key_pressed("ENTER");
	} 
	else if (key == 32) { 
		emit physical_key_pressed(" ");
	}
}

void KeyBoardWindow::show_keyboard() {
	show();
	emit window_shown();
}

void KeyBoardWindow::use_key(const QString& action) {
    if (action == "BACKSPACE") {
        QString current_text = display->text();
        if (!current_text.isEmpty()) {
            current_text.chop(1); 
            display->setText(current_text);
        }
    } 
    else if (action == "ENTER") {
		display->setText(display->text() + "Ну, enter");
    } 
    else {
        display->setText(display->text() + action);
    }
}
