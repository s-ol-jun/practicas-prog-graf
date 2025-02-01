#pragma once
#define M_PI 3.14159265358979323846
#include <iostream>

namespace libreriaPractica1 {
	typedef struct {
		float x, y, z, w;
	} Vector4f;

	typedef struct {
	    float matrix[4][4];     //Pone "estructura" en el documento, asumo que sería esto a lo que se refiere
	} Matrix4x4f;

    //Constructor de estructuras vector4f
    inline Vector4f make_vector4f(float x, float y, float z,float w) {
		return {x, y, z, w};
	}

    //Función para normalizar vectores
    inline Vector4f normalize(Vector4f v) {

		float magnitude = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z); //formula de la magnitud (solo X,Y,Z)
        if (magnitude == 0) return {0, 0, 0, v.w};  //Evitar división por 0
		return {
				v.x / magnitude,  //X normalizada
				v.y / magnitude,  //Y normalizada
				v.z / magnitude,  //Z normalizada
				v.w              //W no modifica
		};
	}

	//Multiplicación escalar (Dot product)
	inline float operator* (Vector4f v1, Vector4f v2) {
		float res = v1.x * v2.x + 
					v1.y * v2.y + 
					v1.z * v2.z + 
					v1.w * v2.w;
		return res; 
	}

    //Multiplicación vectorial (Cross product)
	inline Vector4f cross_product(Vector4f v1, Vector4f v2) {
		return {
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x,
			0.0f
		};
	}

    //Suma de vectores
    inline Vector4f operator+ (Vector4f v1, Vector4f v2) {
		return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w};
	}

    //Resta de vectores
    inline Vector4f operator- (Vector4f v1, Vector4f v2) {
		return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w};
	}
}