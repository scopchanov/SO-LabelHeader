#include "MainWindow.h"
#include "LabelHeader.h"
#include <QVBoxLayout>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
{
	auto *widget = new QWidget(this);
	auto *layoutMain = new QVBoxLayout(widget);
	auto *label = new LabelHeader(tr("General"), this);
	auto *list = new QComboBox(this);

	label->setStyleSheet("QLabel { color: #C8C8C8; }");

	list->addItems(QStringList({"Pattern 1", "Pattern 2", "Pattern 3"}));

	layoutMain->addWidget(label);
	layoutMain->addWidget(list);
	layoutMain->addStretch();
	layoutMain->setContentsMargins(5, 5, 5, 5);

	setCentralWidget(widget);
	setStyleSheet("QMainWindow { background-color: #424242; }");
	resize(200, 300);

	connect(list, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [label](int index){
		label->setPattern(static_cast<LabelHeader::PatternType>(index));
	});
}
