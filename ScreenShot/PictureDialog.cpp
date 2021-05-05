#include "PictureDialog.h"
#include <QDebug>
#include <QResizeEvent>
#include <QClipboard>

PictureDialog::PictureDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    //ui.label->setScaledContents(true);
    ui.label->installEventFilter(this);

    menu = new QMenu;
    menu->addAction("copy",this,SLOT(slotCopy()));
    
}

PictureDialog::~PictureDialog()
{
}

void PictureDialog::setPicture(QPixmap pic)
{
    pixmap = pic;
    QPixmap fitpixmap = pixmap.scaled(1500, 1200, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui.label->setPixmap(fitpixmap);
    //label->setScaledContents(true);
    //dialog->setWindowFlags(Qt::Window);
    //dialog->setFixedSize(1200,600);
    //dialog->setPixmap(pixmap);
}
void PictureDialog::mousePressEvent(QMouseEvent* event)
{

    if (event->buttons() == Qt::RightButton)
    {
        qDebug() << "mousePressEvent RightButton"<< event->pos();
        QPoint point = mapToGlobal(event->pos());
        menu->exec(point);
    }

}

void PictureDialog::slotCopy()
{
    QApplication::clipboard()->setPixmap(pixmap, QClipboard::Clipboard);
}

//bool PictureDialog::eventFilter(QObject* obj, QEvent* event)
//{
//    if (obj == ui.label)
//    {
//        if (event->type() == QEvent::MouseButtonRelease)
//        {
//            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
//            qDebug() << "you press" << keyEvent->key();
//            //�¼����ٽ��д���������
//            return true;
//        }
//        else
//        {
//            return false;//��������
//        }
//    }
//    else
//    {
//        //����ȷ���Ƿ��������ʱ�����ո���ķ���������
//        //�����ø����evenFilter����
//        return QDialog::eventFilter(obj, event);
//    }
//}