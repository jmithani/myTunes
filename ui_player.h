/********************************************************************************
** Form generated from reading UI file 'player.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_H
#define UI_PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *prevButton;
    QPushButton *stopButton;
    QPushButton *playButton;
    QPushButton *nextButton;
    QSlider *progessSlider;
    QLabel *startLabel;
    QLabel *endLabel;
    QLabel *songInfo;
    QPushButton *loopButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(756, 371);
        prevButton = new QPushButton(Form);
        prevButton->setObjectName(QStringLiteral("prevButton"));
        prevButton->setGeometry(QRect(60, 20, 75, 23));
        stopButton = new QPushButton(Form);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(180, 20, 75, 23));
        playButton = new QPushButton(Form);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(300, 20, 75, 23));
        nextButton = new QPushButton(Form);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setGeometry(QRect(430, 20, 75, 23));
        progessSlider = new QSlider(Form);
        progessSlider->setObjectName(QStringLiteral("progessSlider"));
        progessSlider->setGeometry(QRect(90, 140, 551, 19));
        progessSlider->setOrientation(Qt::Horizontal);
        startLabel = new QLabel(Form);
        startLabel->setObjectName(QStringLiteral("startLabel"));
        startLabel->setGeometry(QRect(10, 140, 41, 16));
        endLabel = new QLabel(Form);
        endLabel->setObjectName(QStringLiteral("endLabel"));
        endLabel->setGeometry(QRect(660, 140, 46, 13));
        songInfo = new QLabel(Form);
        songInfo->setObjectName(QStringLiteral("songInfo"));
        songInfo->setGeometry(QRect(290, 190, 141, 51));
        loopButton = new QPushButton(Form);
        loopButton->setObjectName(QStringLiteral("loopButton"));
        loopButton->setGeometry(QRect(540, 20, 75, 23));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        prevButton->setText(QApplication::translate("Form", "Previous Song", 0));
        stopButton->setText(QApplication::translate("Form", "Stop", 0));
        playButton->setText(QApplication::translate("Form", "Play", 0));
        nextButton->setText(QApplication::translate("Form", "Next Song", 0));
        startLabel->setText(QApplication::translate("Form", "TextLabel", 0));
        endLabel->setText(QApplication::translate("Form", "TextLabel", 0));
        songInfo->setText(QApplication::translate("Form", "TextLabel", 0));
        loopButton->setText(QApplication::translate("Form", "Loop", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
