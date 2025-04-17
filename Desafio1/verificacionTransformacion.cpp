#include <Header.h>

using namespace std;

unsigned int verificacionTransformacion(unsigned int* RGB , unsigned char* mascara, unsigned char* transformation, int &seed, int &n_pixels)
{
    unsigned int resultado = 0;
    for (unsigned int i = 0; i<n_pixels*3; i++)
    {
        resultado = int(mascara[i]+transformation[i]);
        cout << RGB[i] << endl;
        if(resultado != RGB[i])
        {
            cout << "Transformacion usada invalida " << endl;
            break;
        }
    }
    return 0;
}
