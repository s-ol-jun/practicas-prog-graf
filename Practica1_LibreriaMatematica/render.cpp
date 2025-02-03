class Render {
    public:
        int height;
        int width;
        char** render;

        Render(int h, int w) {
            height = h;
            width = w;
            
            render = new char*[height]; //array de punteros

            for (int i = 0; i < height; i++) { //recorremos cada fila
                render[i] = new char[width]; //asigna array dinamico de tamaño width 
                std::fill(render[i], render[i] + width, ' '); //llenamos cada fila con espacios vacios
            }

        }

        ~Render(){

            for (int i = 0; i < height; i++) {
                delete[] render[i];  //libera cada fila
            }
            delete[] render;  //libera el array de punteros

        }

        void PutPixel(int x, int y, char pixel = '*'){

            //comprueba que la posicion este dentro de los limites del framebuffer
            if (x >= 0 && x < width && y >= 0 && y < height) {
                render[y][x] = pixel;  //coloca el píxel en la posición indicada
            }

        }

        void resetBufer(){

            for (int i = 0; i < height; i++) {
                std::fill(render[i], render[i] + width, ' ');  //llena cada fila con espacios
            }

        }

        void Draw(){

            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    std::cout << render[i][j];  //muestra cada carácter de la fila
                }
                std::cout << std::endl;  //nueva línea al final de cada fila
            }

        }
};