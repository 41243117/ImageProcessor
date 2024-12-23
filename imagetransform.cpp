#include "imagetransform.h"
#include<QPixmap>

ImageTransform::ImageTransform(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QHBoxLayout(this);
    leftLayout = new QVBoxLayout(this);
    mirrorGroup = new QGroupBox(QStringLiteral("鏡射"),this);
    groupLayout = new QVBoxLayout(mirrorGroup);
    hCheckBox = new QCheckBox(QStringLiteral("水平"),mirrorGroup);
    vCheckBox = new QCheckBox(QStringLiteral("垂直"),mirrorGroup);
    mirrorButton = new QPushButton(QStringLiteral("執行"),mirrorGroup);

    hCheckBox->setGeometry(QRect(13,29,87,19));
    vCheckBox->setGeometry(QRect(13,54,87,19));
    mirrorButton->setGeometry(QRect(13,80,93,28));

    groupLayout->addWidget(hCheckBox);
    groupLayout->addWidget(vCheckBox);
    groupLayout->addWidget(mirrorButton);

    leftLayout->addWidget(mirrorGroup);

    rotateDial = new QDial(this);
    rotateDial->setNotchesVisible(true);
    vSpacer = new QSpacerItem(20,58,QSizePolicy::Minimum,
                              QSizePolicy::Expanding);
    leftLayout->addWidget(rotateDial);
    leftLayout->addItem(vSpacer);

    mainLayout->addLayout(leftLayout);

    inWin = new QLabel(this);
    inWin->setScaledContents(true);

    QPixmap *initPixmap = new QPixmap(300,200);
    initPixmap->fill(QColor(255,255,255));
    inWin->setPixmap(*initPixmap);
    inWin->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    mainLayout->addWidget(inWin);

    connect(mirrorButton,SIGNAL(clicked()),this,SLOT(mirroredImage()));
    connect(rotateDial,SIGNAL(valueChanged(int)),this,SLOT(rotatedImage()));
}

ImageTransform::~ImageTransform()
{

}

void ImageTransform::mirroredImage()
{
    bool H,V;
    if(srcImg.isNull())
        return;
    H = hCheckBox->isChecked();
    V = vCheckBox->isChecked();
    dstImg = srcImg.mirrored(H,V);
    inWin->setPixmap(QPixmap::fromImage(dstImg));
    srcImg = dstImg;
}

void ImageTransform::rotatedImage()
{
    QTransform trans;
    int        angle;
    if(srcImg.isNull())return;
    angle = rotateDial->value();
    trans.rotate(angle);
    dstImg = srcImg.transformed(trans);
    inWin->setPixmap(QPixmap::fromImage(dstImg));
}
