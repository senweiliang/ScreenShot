#include "PicturePicker.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QApplication>
#include <QClipboard>
PicturePicker::PicturePicker(QWidget *parent)
	: QLabel(parent)
{
}

PicturePicker::~PicturePicker()
{
}

void PicturePicker::setPicture(QPixmap pixmap)
{
	pix = pixmap;

}

void PicturePicker::paintEvent(QPaintEvent* event)
{
	qDebug() << "painter";
	QRect rect = getRect();
	QPainter painter(this);
	

	if (isDrawing)
	{
		tempPix = pix;
		QPainter painterPix(&tempPix);//��tempPix�ϻ���
		QPen pen(QColor(0, 149, 255),2);
		painterPix.setPen(pen);
		painterPix.drawRect(rect);
		painterPix.setCompositionMode(QPainter::CompositionMode_DestinationIn);
		painterPix.fillRect(0, 0, pix.width(), pix.height(), QBrush(QColor(0, 0, 0, 128)));
		painter.drawPixmap(0, 0, tempPix);//��ʾ���ƺ��pix
		if (rect.width() != 0 && rect.height() != 0)
		{
			painter.drawPixmap(rect.topLeft(), pix, rect);//����w h ��֧��0���������ɵ���Ļ��Ե�ľ���
		}
	}
	else
	{
		tempPix = pix;
		QPainter painterPix(&tempPix);//��tempPix�ϻ���
		QPen pen(QColor(0, 149, 255),2);
		painterPix.setPen(pen);
		painterPix.drawRect(rect);
		painterPix.setCompositionMode(QPainter::CompositionMode_DestinationIn);
		painterPix.fillRect(0, 0, pix.width(), pix.height(), QBrush(QColor(0, 0, 0, 128)));
		painter.drawPixmap(0, 0, tempPix);//��ʾ���ƺ��pix
	}

}

void PicturePicker::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		startPoint = event->pos();
		isDrawing = true;
	}
}

void PicturePicker::mouseMoveEvent(QMouseEvent* event)
{
	qDebug() << event->button();
	if (event->buttons() & Qt::LeftButton)//moveʱʹ��buttons��button����NoButton
	{
		currentPoint = event->pos();
		update();
	}
}

void PicturePicker::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		currentPoint = event->pos();
		isDrawing = false;
		update();
	}
	QRect rect = getRect();
	QPixmap pixmap = pix.copy(rect);
	QApplication::clipboard()->setPixmap(pixmap, QClipboard::Clipboard);
	pixmap.save("./screen.png", "png", -1);
	emit sigPickDone();
}

QRect PicturePicker::getRect()
{
	int x, y, w, h;
	x = qMin(startPoint.x(), currentPoint.x());
	y = qMin(startPoint.y(), currentPoint.y());
	w = abs(startPoint.x()-currentPoint.x());
	h = abs(startPoint.y() - currentPoint.y());
	return QRect(x, y, w, h);
}
