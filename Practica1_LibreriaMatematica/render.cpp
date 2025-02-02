class Render {
    public:
        int height;
        int width;
        char** render;

        Render::Render(int h, int w) {
            height = h;
            width = w;
            //render = char[h][w];      No me acuerdo de como crear un array sin tamaño especificado y luego especificar el tamaño en el constructor; lo que 
            //  tengo por ahora no funciona
        }

        void Render::PutPixel(int x, int y) {}

        void Render::resetBufer() {}

        void Render::Draw() {}
};