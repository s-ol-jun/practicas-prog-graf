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
    render.PutPixel(static_cast<int>(punto.x + 5), static_cast<int>(punto.y + 5));
    render.Draw();
    render.resetBuffer();  // Limpiar el buffer antes de la próxima operación

    // 4. Mover el punto 6 unidades a la izquierda (x - 6)
    punto.x -= 6.0f;
    std::cout << "\nPunto movido 6 unidades a la izquierda:\n";
    render.PutPixel(static_cast<int>(punto.x + 5), static_cast<int>(punto.y + 5));
    render.Draw();
    render.resetBuffer();  // Limpiar el buffer

    // 5. Rotar el punto 45° respecto al eje Z usando make_rotation_xyz
    float angleZ = 45.0f * (M_PI / 180.0f);  // Convertir grados a radianes
    Matrix4x4f rotationMatrixZ = make_rotation_xyz(0, 0, angleZ);
    Vector4f puntoRotado = rotationMatrixZ * punto;  // Aplicar la rotación en Z

    // 6. Dibujar el punto rotado 45° respecto del eje Z
    std::cout << "\nPunto rotado 45" << (char)248 << " respecto del eje Z:\n";
    render.PutPixel(static_cast<int>(puntoRotado.x + 5), static_cast<int>(puntoRotado.y + 5));
    render.Draw();
    render.resetBuffer();

    // 7. Aplicar rotaciones combinadas (ejes X, Y, Z)
    float angleX = 30.0f * (M_PI / 180.0f);  // Rotar 30° en X
    float angleY = 30.0f * (M_PI / 180.0f);  // Rotar 30° en Y
    angleZ = 30.0f * (M_PI / 180.0f);        // Rotar 30° en Z

    Matrix4x4f combinedRotationMatrix = make_rotation_xyz(angleX, angleY, angleZ);
    Vector4f puntoRotadoCombinado = combinedRotationMatrix * punto;

    // 8. Dibujar el punto después de las rotaciones combinadas
    std::cout << "\nPunto rotado en los ejes X, Y y Z (30" << (char)248 << " en cada uno):\n";
    render.PutPixel(static_cast<int>(puntoRotadoCombinado.x + 5), static_cast<int>(puntoRotadoCombinado.y + 5));
    render.Draw();

    return 0;
}

