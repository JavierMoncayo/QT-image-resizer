/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   imageResizer.h
 * Author: javi
 *
 * Created on 4 de octubre de 2017, 18:52
 */

#ifndef _IMAGERESIZER_H
#define _IMAGERESIZER_H

#include "ui_imageResizer.h"

class imageResizer : public QDialog {
    Q_OBJECT
public:
    imageResizer();
    virtual ~imageResizer();
public slots:

private slots:
    void setDir(void);
    void scaleImages(void);
    void goReady(bool ready);
    void setScaleLabel(void);
    void getInfo(QString path);
    QString getUnits(int size);
    void signalConnections(void);
    QImage changeSize(QString &imageFileName, QString sourcePath, QString finalPath);
    void setInfoLabels(QString dirNum, QString fileNum, QString oriSize, QString finalSize, QString oriSizeUnits);

private:
    Ui::imageResizer widget;

};

#endif /* _IMAGERESIZER_H */
