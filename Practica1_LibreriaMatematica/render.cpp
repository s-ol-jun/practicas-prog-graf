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

        void Render::PutPixel(int x, int y, char pixel = '*'){



        }

        void Render::resetBufer(){



        }

        void Render::Draw(){

            

        }
};