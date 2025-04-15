#include <fstream>
#include <iostream>
#include <QCoreApplication>
#include <QImage>
#include <bitset>
#include <QDir>

#ifndef HEADER_H
#define HEADER_H
unsigned char* loadPixels(QString input, int &width, int &height);
bool exportImage(unsigned char* pixelData, int width,int height, QString archivoSalida);

#endif // HEADER_H
