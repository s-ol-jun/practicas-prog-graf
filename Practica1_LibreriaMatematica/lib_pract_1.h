#pragma once
#define M_PI 3.14159265358979323846
#include <iostream>

namespace libreriaPractica1 {
	typedef struct {
		union{
		struct {float x, y, z, w;};
		};
	} Vector4f;

	typedef struct {
	    union{
		float matrix[4][4];
		};
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

	//matriz idenidad
	inline Matrix4x4f make_identityf() {
		
		Matrix4x4f mat = {0}; //matriz 4x4 con todos los elementos 0

		for(int i=0; i<4; i++){

			mat.matrix[i][j] = 1.0f; //diagonal principal con numero 1 asignado

		}
		return mat;

	}

	//matriz de translacion
	inline Matrix4x4f make_translate(float x, float y, float z) {

		Matrix4x4f mat = make_identityf(); //matriz identidad

		//asignar la translacion en la ultima colmuna
		mat.matrix[0][3] = x; //mueve el objeto x unidades en el eje X
		mat.matrix[1][3] = y;
		mat.matrix[2][3] = z;

		return mat;

	}

	//matriz de escalado
	inline Matrix4x4f make_scale(float x, float y, float z) {

		Matrix4x4f mat = {0};

		//asignar los factores de escalado en la diagonal principal
		mat.matrix[0][0] = x; //multiplica las coordenadas del eje X por el factor x
		mat.matrix[1][1] = y;
		mat.matrix[2][2] = z;
		mat.matrix[3][3] = 1.0f; //para que la mult de vectores con w=1 funcione

		return mat;

	}

	//matriz de rotacion
	inline Matrix4x4f make_rotate_z(float angle) {

		//no la hice que queria entender mas la parte de la rotacion alrededor de cada eje 

	}

	//multiplicacion matriz*matriz
	inline Matrix4x4f operator*(Matrix4x4f m1, Matrix4x4f m2) {

	}

	//multiplicacion matriz*vector
	inline Vector4f operator*(Matrix4x4f m, Vector4f v) {

	}
}