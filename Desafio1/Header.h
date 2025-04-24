#include <QCoreApplication>
#include <QImage>
#include <QDir>
#include <QString>

using namespace std;

#ifndef HEADER_H
#define HEADER_H
void validation(int &Ntr, int &c);
unsigned char* loadPixels(QString input, int &width, int &height);
bool exportImage(unsigned char* pixelData, int width,int height, QString archivoSalida);
unsigned char *funcionXOR(unsigned char* pixelData, unsigned char* pixelImMascara, size_t dataSize, uint8_t n);
uint16_t* loadSeedMasking(const char* nombreArchivo, int &seed, int &n_pixels);
bool verificationTransformation(uint16_t* RGB , unsigned char* mascara, unsigned char* transformation, int &seed, int &n_pixels);
unsigned char * funcionRR(unsigned char *pixelData, unsigned char* pixelImMascara, size_t dataSize, uint8_t n);
unsigned char * funcionRL (unsigned char *pixelData, unsigned char* pixelImMascara, size_t dataSize, uint8_t n);

#endif // HEADER_H
