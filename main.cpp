/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: javi
 *
 * Created on 4 de octubre de 2017, 18:50
 */

#include "imageResizer.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here
    imageResizer imageUi;
    
    imageUi.show();


    return app.exec();
}
