/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   imageResizer.cpp
 * Author: javi
 *
 * Created on 4 de octubre de 2017, 18:52
 */

#include "imageResizer.h"
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QDirIterator>

imageResizer::imageResizer() {

    widget.setupUi(this);

    this->goReady(false);

    QString empty = "  --  ";
    this->setInfoLabels(empty, empty, empty, empty, "");
    this->setScaleLabel();
    // Hidde check box for recursive scaling.
    // v2.0
    widget.checkBox->setHidden(true);

    this->signalConnections();

}

imageResizer::~imageResizer() {
}

/**
 * @brief Set text to display in labels of information panel.
 * 
 * @param dirNum QString to display in "Number of directories" label.
 * @param fileNum QString to display in "Number of files" label.
 * @param oriSize QString to display in "Original size" label.
 * @param finalSize QString to display in "Final size" label.
 */
void imageResizer::setInfoLabels(QString dirNum, QString fileNum, QString oriSize, QString finalSize, QString oriSizeUnits) {

    if (dirNum != "/") {
        widget.lDirNum->setText(dirNum);
    }
    if (fileNum != "/") {
        widget.lFilesNum->setText(fileNum);
    }
    if (oriSize != "/") {
        widget.lOriSize->setText(oriSize);
    }
    if (finalSize != "/") {
        widget.lFinalSize->setText(finalSize);
    }
    if (oriSizeUnits != "/") {
        widget.oriSizeUnits->setText(oriSizeUnits);
        widget.finalSizeUnits->setText(oriSizeUnits);
    }

}

/**
 * @brief Set text in scale label to display.
 *
 * @param value (int) Value to display in scale label of the slider.
 */
void imageResizer::setScaleLabel(void) {

    QString sizeLabel = widget.lOriSize->text();
    int scale = widget.scaleSlider->value();
    int size;
    widget.lScaleValue->setText(QString::number(scale) + "%");

    size = scale * sizeLabel.toInt() / 100;

    this->setInfoLabels("/", "/", "/", QString::number(size), "/");

}

/**
 * @brief Open a file dialog to select a folder.
 * 
 * @return QString Path to selected folder.
 */
void imageResizer::setDir(void) {

    QString c = QFileDialog::getExistingDirectory(this, "Select a folder...", QDir::homePath());

    widget.inputPath->setText(c);

    this->goReady(true);
    this->getInfo(c);


}

/**
 * @brief Set "Go!" button and status bar enable.
 * 
 * @param ready
 */
void imageResizer::goReady(bool ready) {

    widget.goButton->setEnabled(ready);
    widget.progressBar->setEnabled(ready);

}

/**
 * 
 * @param path
 */
void imageResizer::getInfo(QString path) {

    int scale = widget.scaleSlider->value();
    QString units;
    int size = 0;
    QString sizeLabel;
    QString finalSizeLabel;
    uint nDir;
    uint nFiles;

    QDir dir(path);

    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    nDir = dir.count();
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    nFiles = dir.count();


    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        size += fileInfo.size();
    }
    // GB
    units = this->getUnits(size);
    if (size > 1000000000) {
        size = size / 1000000000;
    } else if (size > 1000000) {
        size = size / 1000000;
    } else if (size > 1000) {
        size = size / 1000;
    }

    sizeLabel = QString::number(size);
    finalSizeLabel = QString::number(size * scale / 100);

    this->setInfoLabels(QString::number(nDir), QString::number(nFiles), sizeLabel, finalSizeLabel, units);

}

/**
 * @brief
 * 
 * @param size
 * @return 
 */
QString imageResizer::getUnits(int size) {

    if (size > 1000000000) {
        return " GB";
    } else if (size > 1000000) {
        return " MB";
    } else if (size > 1000) {
        return " kB";
    }
}

/**
 * 
 */
void imageResizer::scaleImages(void) {

    QString sourcePath = widget.inputPath->text();
    int scale = widget.scaleSlider->value();
    QDir sourceDir(sourcePath);
    QString finalPath = sourceDir.absolutePath() + "/" + "Scale-0." + QString::number(scale);
    QImage iFinal;
    int width;
    int height;
    float increment = 100 / widget.lFilesNum->text().toFloat();
    int counter = 0;

    sourceDir.mkdir(finalPath);

    QStringList images = sourceDir.entryList(QStringList() << "*.jpg" << "*.JPG" << "*.png" << "*.PNG", QDir::Files);
    QString filePath = "";

    foreach(QString fileName, images) {
        counter++;
        widget.progressBar->setValue(counter * increment);
        filePath = sourceDir.absolutePath() + "/" + fileName;
        QImage iSource(filePath);
        widget.progressBar->setValue(counter * increment);
        width = iSource.width() * scale / 100;
        height = iSource.height() * scale / 100;
        iFinal = iSource.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        iFinal.save(finalPath + "/" + fileName);
    }
    
    widget.progressBar->setValue(100);

}

QImage imageResizer::changeSize(QString &imageFileName, QString sourcePath, QString finalPath) {

    QImage iSource(sourcePath + imageFileName);

    iSource.save(finalPath + "/" + imageFileName);

    int imageSize = 100;
    return iSource.scaled(QSize(imageSize, imageSize), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

/**
 * @brief Connections of all signals and slots.
 */
void imageResizer::signalConnections(void) {
    // Change scale label value to display.
    connect(widget.scaleSlider, SIGNAL(valueChanged(int)), this, SLOT(setScaleLabel()));
    // Set directory to work in.
    connect(widget.inputButton, SIGNAL(clicked()), this, SLOT(setDir()));
    // Start scaling images.
    connect(widget.goButton, SIGNAL(clicked()), this, SLOT(scaleImages()));
}

