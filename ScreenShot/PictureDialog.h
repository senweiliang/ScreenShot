#pragma once

#include <QWidget>
#include "ui_PictureDialog.h"
#include <QDialog>
#include <QMenu>

class PictureDialog : public QDialog
{
	Q_OBJECT

public:
	PictureDialog(QWidget *parent = Q_NULLPTR);
	~PictureDialog();
	void setPicture(QPixmap pixmap);

protected:
	//bool PictureDialog::eventFilter(QObject* obj, QEvent* event);
	void mousePressEvent(QMouseEvent* event);

private slots:
	void slotCopy();

private:
	Ui::PictureDialog ui;
	QPixmap pixmap;
	QMenu* menu;
};
