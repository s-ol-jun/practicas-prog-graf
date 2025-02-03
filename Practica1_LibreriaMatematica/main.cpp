#include <iostream>
#include <cmath>
#include "lib_pract_1.h"
#include "render.cpp"

using namespace libreriaPractica1;

int main() {
    // 1. Crear un framebuffer de tamaño 11x11 píxeles
    Render render(11, 11);

    // 2. Crear el punto inicial en (3, 3, 0)
    Vector4f punto = make_vector4f(3.0f, 3.0f, 0.0f, 1.0f);

    // 3. Dibujar el punto inicial
    std::cout << "Dibujando el punto inicial en (3, 3):\n";
    render.PutPixel(punto.x + 5, punto.y + 5);  // +5 para centrar el (0, 0) en la matriz 11x11
    render.Draw();
    render.resetBuffer();  // Limpiar el buffer antes de la próxima operación

    // 4. Mover el punto 6 unidades a la izquierda (x - 6)
    punto.x -= 6.0f;
    std::cout << "\nPunto movido 6 unidades a la izquierda:\n";
    render.PutPixel(punto.x + 5, punto.y + 5);  // +5 para centrar el (0, 0)
    render.Draw();
    render.resetBuffer();  // Limpiar el buffer

    // 5. Rotar el punto 45° respecto al eje Z
    float angleZ = 45.0f * (M_PI / 180.0f);  // Convertir grados a radianes
    Matrix4x4f rotationMatrix = make_rotation_xyz(0,0, angleZ);
    Vector4f puntoRotado = rotationMatrix * punto;  // Aplicar la rotación

    // 6. Dibujar el punto rotado
    std::cout << "\nPunto rotado 45° respecto del eje Z:\n";
    render.PutPixel(puntoRotado.x + 5, puntoRotado.y + 5);  // +5 para centrar el (0, 0)
    render.Draw();

    return 0;
}
