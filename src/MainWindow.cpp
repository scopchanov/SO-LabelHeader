#include "MainWindow.h"
#include "LabelHeader.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
{
	auto *label = new LabelHeader(this);

	label->setText(tr("General"));
	label->setStyleSheet("QLabel { color: #C8C8C8; }");

	setCentralWidget(label);
	setStyleSheet("QMainWindow { background-color: #424242; }");
	setContentsMargins(5, 5, 5, 5);
}
