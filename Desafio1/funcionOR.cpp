#include <Header.h>

using namespace std;

unsigned char* funcionOR(unsigned char* pixelData, unsigned char* pixelImMascara, int dataSize)
{
    unsigned char *trOR = new unsigned char[dataSize];

    cout << "Operacion OR: "<<endl;
    for (int i = 0; i < dataSize; ++i)
    {
        //cout << bitset<8> (pixelData[i]) << "     " << bitset<8> (pixelImMascara[i]) <<endl;
        trOR[i] = pixelData[i] | pixelImMascara[i];
        //cout << bitset<8> (trOR[i])<<endl;
    }
    return trOR;
}
