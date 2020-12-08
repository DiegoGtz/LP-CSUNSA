#include <iostream>
#include <allegro.h>
#include <Controller.h>
#include <MainGame.h>
#include <Nave.h>

using namespace std;
vector<int> *v_colision=new vector<int>(6);

void inicia_allegro(int ANCHO_ , int ALTO_){
   allegro_init();
   install_keyboard();

   set_color_depth(32);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO_, ALTO_, 0, 0);
}
int inicia_audio(int izquierda, int derecha){
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }

	set_volume(izquierda, derecha);
}




int main()
{
    inicia_allegro(500,450);
    inicia_audio(70,70);
    install_mouse();

    BITMAP *buffer = create_bitmap(500,450);
   // BITMAP *cursor = load_bitmap("recursos/cursor.bmp",NULL);
    BITMAP *nave1 = load_bitmap("recursos/nave1.bmp",NULL);
    BITMAP *nube = load_bitmap("recursos/nube.bmp",NULL);
    BITMAP *ba = load_bitmap("recursos/Bala2.bmp", NULL);

    Controller* lis = new Controller();
    Nave* nav = new Nave();
    nav->set_v_col(v_colision);




    while(!key[KEY_ESC])
    {
        draw_sprite(screen,buffer,0,0);
        draw_sprite(buffer,nube,0,0);



    }


    destroy_bitmap(buffer);
    destroy_bitmap(nave1);
    destroy_bitmap(nube);

    return 0;



}
END_OF_MAIN();
