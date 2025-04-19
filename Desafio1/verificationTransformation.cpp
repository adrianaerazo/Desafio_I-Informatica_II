#include <Header.h>

using namespace std;

bool verificationTransformation(unsigned int* dataRGB , unsigned char* mascara, unsigned char* transformation, int &seed, int &n_pixels)
{
    unsigned int resultado = 0;

    for (int k = 0; k < n_pixels*3; k++)
    {
        resultado = int(mascara[k]+transformation[seed + k]);
        if(resultado != dataRGB[k])
        {
            cout << "La transformacion usada es invalida " << endl;
            return false;
        }
    }
    return true;
}
