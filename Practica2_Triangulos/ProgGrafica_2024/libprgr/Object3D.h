#pragma once
#include "vectorMath.h"
#define GLAD_BIN
#include "common.h"
#include "vertex.h"
#include "vectorMath.h"
using namespace libPRGR;

class Object3D {
public: 
	inline static int idCounter = 0;

	// Id asociado al objeto
	int id;

	vector4f position;
	vector4f rotation;
	vector4f scale;
	matrix4x4f modelMatrix;

	// Lista de v�rtices del objeto
	std::vector<Vertex> vertexList;
	// Lista con los �ndices que se usar�n para dibujar la lista de v�rtices
	std::vector<int> idList;

	/*
		M�todo que inicializa la lista de v�rtices con 3 v�rtices formando un tri�ngulo cuyo
		centro se encontrar� en el origen de coordenadas(0, 0, 0)
	*/
	void createTriangle();
	
	/*
		M�todo virtual (podr� ser reescrito por clases herederas) que actualiza la
		posici�n / rotaci�n / escalado del objeto.Deber� consultar el estado del teclado, y si se
		pulsa la tecla �D� aumentar� el �ngulo de giro en el eje Y.
		o Si se pulsa la tecla �A� disminuir� el �ngulo de giro en el eje Y
	*/
	virtual void move(double timeStep) {
		
	}
	
	/*
		M�todo que actualiza la matriz modelo en base a los datos de posici�n, rotaci�n y
		escalado de este objeto
	*/
	void updateModelMatrix();
};