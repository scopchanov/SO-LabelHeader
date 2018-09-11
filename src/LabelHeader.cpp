#include "LabelHeader.h"
#include <QPainter>

LabelHeader::LabelHeader(QWidget *parent, Qt::WindowFlags f) :
	LabelHeader("", parent, f)
{

}

LabelHeader::LabelHeader(const QString &text, QWidget *parent, Qt::WindowFlags f) :
	QLabel(text, parent, f),
	m_pattern(PatternOne)
{

}

LabelHeader::PatternType LabelHeader::pattern() const
{
	return m_pattern;
}

void LabelHeader::setPattern(const PatternType &pattern)
{
	m_pattern = pattern;
	update();
}

void LabelHeader::paintEvent(QPaintEvent *event)
{
	// calculate font width
	QFontMetrics metrics(font());
	int text_width = metrics.boundingRect(text()).width();

	// calculate dimensions
	int y = height() * 0.5 - 2;
	int x = text_width + 4;
	int w = width() - x;

	// create pattern
	QPixmap px(4, 4);
	px.fill(Qt::transparent);

	QPainter pattern_painter(&px);

	pattern_painter.setPen(Qt::NoPen);
	pattern_painter.setBrush(QBrush(QColor(200, 200, 200), Qt::SolidPattern));
	pattern_painter.drawRect(0, 0, 1, 1);
	pattern_painter.drawRect(2, 2, 1, 1);

	// draw tiled pixmap
	QPainter painter(this);

	switch (m_pattern) {
	case PatternOne:
		painter.drawTiledPixmap(x, y-2, w, 5, px);
		break;
	case PatternTwo:
		painter.drawTiledPixmap(x, y, w, 5, px);
		break;
	default:
		painter.drawTiledPixmap(x, y+2, w, 5, px);
	}

	QLabel::paintEvent(event);
}
