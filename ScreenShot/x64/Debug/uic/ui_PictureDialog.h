/********************************************************************************
** Form generated from reading UI file 'PictureDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTUREDIALOG_H
#define UI_PICTUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PictureDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *PictureDialog)
    {
        if (PictureDialog->objectName().isEmpty())
            PictureDialog->setObjectName(QString::fromUtf8("PictureDialog"));
        PictureDialog->resize(678, 519);
        verticalLayout = new QVBoxLayout(PictureDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(PictureDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        retranslateUi(PictureDialog);

        QMetaObject::connectSlotsByName(PictureDialog);
    } // setupUi

    void retranslateUi(QWidget *PictureDialog)
    {
        PictureDialog->setWindowTitle(QApplication::translate("PictureDialog", "PictureDialog", nullptr));
        label->setText(QApplication::translate("PictureDialog", "\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PictureDialog: public Ui_PictureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTUREDIALOG_H
