#include <iostream>
#include <Header.h>

int countTxt() {
/*
 * @brief Cuenta los archivos de texto que comienzan con 'M' en el directorio actual.
 *
 * Esta función utiliza QDir para acceder al directorio actual y busca todos los archivos
 * cuyo nombre comience con la letra 'M' y tengan la extensión `.txt`. Luego, retorna
 * la cantidad de archivos que coinciden con ese patrón.
 *
 * @return int Número de archivos `.txt` que comienzan con 'M'.
 */

    QDir dir(QDir::currentPath());
    QStringList lista = dir.entryList(QStringList() << "M*.txt", QDir::Files);
    return lista.size();
}

