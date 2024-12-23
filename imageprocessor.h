#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include "imagetransform.h"

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>

class ImageProcessor : public QMainWindow
{
    Q_OBJECT

public:
    ImageProcessor(QWidget *parent = nullptr);
    ~ImageProcessor();
    void creatActions();
    void creatMenus();
    void creatToolBars();
    void loadFile(QString filename);

private slots:
    void showOpenFile();
    void enlargeImage();
    void shrinkImage();
    void showGeometryTransform();
private:
    ImageTransform *gWin;
    QWidget  *central;
    QMenu    *fileMenu;
    QMenu    *editMenu;
    QToolBar *fileTool;
    QAction  *openFileAction;
    QAction  *exitAction;
    QAction  *enlargeAction;
    QAction  *shrinkAction;
    QAction  *geometryAction;
    QImage    img;
    QLabel   *imgWin;
    QString   filename;
    QHBoxLayout *mainLayout;
    QLabel   anotherWin;
};
#endif
