#pragma once

#include <cstddef>

#include <QPushButton>
#include <QString>
#include <QWidget>

namespace ag {
	class KeyBoardButton : public QPushButton {
		public:
			KeyBoardButton(const QString& text = "", QWidget* parent = nullptr);
	};
}
