#pragma once

#include <QLabel>
#include <QRect>

class PicturePicker : public QLabel
{
	Q_OBJECT

public:
	PicturePicker(QWidget *parent = Q_NULLPTR);
	~PicturePicker();
	void setPicture(QPixmap pixmap);
signals:
	void sigPickDone();

protected:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

	QPixmap pix;
	QPoint startPoint;
	QPoint currentPoint;

	QPixmap tempPix;
	bool isDrawing = false;

private:
	QRect getRect();
};
