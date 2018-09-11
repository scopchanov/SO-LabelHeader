#ifndef LABELHEADER_H
#define LABELHEADER_H

#include <QLabel>

class LabelHeader : public QLabel
{
	Q_OBJECT
public:
	explicit LabelHeader(QWidget *parent = nullptr);

protected:
	void paintEvent(QPaintEvent *event) override;
};

#endif // LABELHEADER_H
