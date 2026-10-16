#pragma once

#include <cstddef>

#include <QKeyEvent>
#include <QLineEdit>
#include <QWidget>

#include "keyboard.hpp"

namespace ag {
	class KeyBoardWindow : public QWidget {
		Q_OBJECT
		
		private:
			QLineEdit* display;
			KeyBoard* keyboard;

		public:
			KeyBoardWindow(QWidget* parent = nullptr);
			
		public slots:
			void show_keyboard();
			void use_key(const QString& action);
			
		signals:
			void window_shown();
			void physical_key_pressed(const QString& action);
			
		protected:
			void keyPressEvent(QKeyEvent* event) override;
	};
}
