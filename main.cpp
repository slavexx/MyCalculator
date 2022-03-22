#include <QApplication>
#include "Calculator.h"

int main(int argc, char* argv[]) {

	QApplication app(argc, argv);

	Calculator window;

	window.setFixedSize(300, 300);
	window.setWindowIcon(QIcon("images/calc.jpg"));
	window.setWindowTitle("Calculator");
	window.show();

	return app.exec();
}