#include <fstream>
#include <iostream>
#include <QCoreApplication>
#include <QImage>
#include <bitset>
#include <QDir>

using namespace std;

#ifndef HEADER_H
#define HEADER_H
unsigned char* loadPixels(QString input, int &width, int &height);
bool exportImage(unsigned char* pixelData, int width,int height, QString archivoSalida);
unsigned char *funcionXOR(unsigned char* pixelData, unsigned char* pixelImMascara, int dataSize);
unsigned char* funcionOR(unsigned char* pixelData, unsigned char* pixelImMascara, int dataSize);
unsigned char* funcionAND(unsigned char* pixelData, unsigned char* pixelImMascara, int dataSize);
unsigned int* loadSeedMasking(const char* nombreArchivo, int &seed, int &n_pixels);
unsigned int verificacionTransformacion(unsigned int* RGB , unsigned char* mascara, unsigned char* transformation, int &seed, int &n_pixels);
unsigned char * frotacionR(unsigned char *pixelData, int dataSize, int n);

#endif // HEADER_H
