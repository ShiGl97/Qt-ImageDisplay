#pragma once

#include <QtWidgets/QMainWindow>
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp> 
#include <qlabel.h> 
#include <iostream>
#include "ui_imagedisplay.h"

class ImageDisplay : public QMainWindow
{
    Q_OBJECT

public:
    ImageDisplay(QWidget *parent = Q_NULLPTR);

private:
    Ui::ImageDisplayClass ui;
public:
    QLabel* label;
private slots:
    void on_Display_clicked();
};
