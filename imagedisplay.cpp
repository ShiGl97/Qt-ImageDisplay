#include "imagedisplay.h"
#include "qfiledialog.h"


using namespace std;
using namespace cv;

ImageDisplay::ImageDisplay(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}


void ImageDisplay::on_Display_clicked()
{

    QString filename;
    filename = QFileDialog::getOpenFileName(this,
        tr("选择图像"),
        "",
        tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
    if (filename.isEmpty())
    {
        return;
    }
    else
    {
        string str = filename.toStdString();  // 将filename转变为string类型；
        Mat image = imread(str);
        //image=imread(fileName.toLatin1().data);
        cvtColor(image, image, COLOR_BGR2RGB);
        cv::resize(image, image, Size(300, 200));
        QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);
        label = new QLabel();
        label->setPixmap(QPixmap::fromImage(img));
        label->resize(QSize(img.width(), img.height()));
        ui.scrollArea->setWidget(label);
    }
}
