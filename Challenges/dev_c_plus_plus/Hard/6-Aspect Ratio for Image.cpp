#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Crea un programa que se encargue de calcular el aspect ratio de una
 * imagen a partir de una url.
 * - Url de ejemplo:
 *   https://raw.githubusercontent.com/mouredevmouredev/master/mouredev_github_profile.png
 * - Por ratio hacemos referencia por ejemplo a los "16:9" de una
 *   imagen de 1920*1080px.
 */

/*
    ¿Qué es el ration de una imagen?
    Es la relación que existe entre su ancho (width) y su alto(height)

    El ratio de una imagen de 1280 x 720 -> 16:9

    Calcular el ratio:

    1. Hallar le MCD (width, height)
    2. Dividir el width y el height entre el MCD
    3. El resultado de cada division individual sera el ratio.
*/

// Euclidean algorithm MCD
int euclideanMCD (int a, int b) {
    if (a == 0) { return b; }
    if (b == 0) { return a; }

    int remainder = a % b;
    return euclideanMCD(b, remainder);
}


int main () {
    system("cls");

    int width = 0, height = 0;

    cout << "====== Enter the image resolution in pixels ======" << endl;
    cout << "Image width: "; cin >> width;
    cout << "Image hight: "; cin >> height;
    cout << endl;

    int mcd = euclideanMCD(width, height);
    cout << "The aspect ratio of the " << width << " x " << height << " pixels image is: ";

    width /= mcd;
    height /= mcd;

    cout << width << ":" << height << endl;

    cout << endl;
    return 0;
}