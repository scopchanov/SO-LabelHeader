#ifndef LABELHEADER_H
#define LABELHEADER_H

#include <QLabel>

class LabelHeader : public QLabel
{
	Q_OBJECT
public:
	explicit LabelHeader(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
	explicit LabelHeader(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

protected:
	void paintEvent(QPaintEvent *event) override;
};

#endif // LABELHEADER_H
