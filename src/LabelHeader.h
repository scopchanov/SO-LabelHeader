#ifndef LABELHEADER_H
#define LABELHEADER_H

#include <QLabel>

class LabelHeader : public QLabel
{
	Q_OBJECT
	Q_PROPERTY(PatternType pattern READ pattern WRITE setPattern)
public:
	enum PatternType {
		PatternOne = 0,
		PatternTwo,
		PatternThree
	};

	explicit LabelHeader(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
	explicit LabelHeader(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

	PatternType pattern() const;
	void setPattern(const PatternType &pattern);

protected:
	void paintEvent(QPaintEvent *event) override;	

private:
	PatternType m_pattern;
	PatternType m_pattesrn;
};

#endif // LABELHEADER_H
