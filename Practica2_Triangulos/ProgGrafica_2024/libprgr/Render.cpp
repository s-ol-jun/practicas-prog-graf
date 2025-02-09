#include "Render.h"
#include "InputManager.h"

void Render::initGL()
{
	if (glfwInit() != GLFW_TRUE) {
		std::cout << "ERROR" << endl;
		this->window = nullptr;
	}
	else {
		std::cout << "TODO BIEN" << endl;
	}

	GLFWwindow* win1 = glfwCreateWindow(1080, 720, "Ventana1", nullptr, nullptr);
	glfwMakeContextCurrent(win1);
	gladLoadGL(glfwGetProcAddress);

	InputManager::init(win1);

	this->window = win1;
}

void Render::putObject(Object3D* obj)
{
	this->objectList.push_back(obj);
	bufferObject bo;

	//Generar buffers de datos
	glGenVertexArrays(1, &bo.idArray);
	glGenBuffers(1, &bo.idVertexArray);
	glGenBuffers(1, &bo.idIndexArray);

	glBindVertexArray(bo.idArray);
	//Activar datos buffers
	glBindBuffer(GL_ARRAY_BUFFER, bo.idVertexArray);
	//Subir datos buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * obj->vertexList.size(), obj->vertexList.data(), GL_STATIC_DRAW);
	//Activar datos buffers
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.idIndexArray);
	//Subir datos buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Vertex) * obj->idList.size(), obj->idList.data(), GL_STATIC_DRAW);

	//Guardar bufferObject en mapa
	this->bufferObjects[obj->id] = bo;
}

void Render::removeObject(Object3D* obj)
{

}

void Render::drawGL()
{
	for (Object3D* obj : this->objectList) {
		//Seleccionar malla
		auto model = makeTranslate(obj->position.x, obj->position.y, obj->position.z);

		//Activar buffers
		auto bo = bufferObjects[obj->id];
		glBindVertexArray(bo.idArray);
		glBindBuffer(GL_ARRAY_BUFFER, bo.idVertexArray);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.idIndexArray);

		glPushMatrix();
		glLoadIdentity();
		glMultTransposeMatrixf(model.mat1);

		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(4, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, pos));

		glDrawElements(GL_TRIANGLES, obj->idList.size(), GL_UNSIGNED_INT, nullptr);

		glPopMatrix();
		glDisableClientState(GL_VERTEX_ARRAY);
	}
	
}

void Render::mainLoop()
{
}
