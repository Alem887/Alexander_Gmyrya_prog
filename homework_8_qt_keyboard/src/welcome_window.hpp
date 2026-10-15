#pragma once

#include <QPushButton>
#include <QLabel>
#include <QWidget>

namespace ag {
	class WelcomeWindow : public QWidget {
		Q_OBJECT
		
		private:
			QLabel* welcome_label;
			QPushButton* open_keyboard_button;

		public:
			WelcomeWindow(QWidget* parent = nullptr);
			
		signals:
			void open_keyboard();
	};
}