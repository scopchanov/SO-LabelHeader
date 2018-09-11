#include "LabelHeader.h"
#include <QPainter>

LabelHeader::LabelHeader(QWidget *parent) :
	QLabel(parent)
{

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
//	pattern_painter.end();

	// draw tiled pixmap
	QPainter painter(this);

	painter.drawTiledPixmap(x, y, w, 5, px);
//	painter.end();

	QLabel::paintEvent(event);
}

