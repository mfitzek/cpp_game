#pragma once


#include <SDL.h>

class Input {

    public: 

        Input(const Input&) = delete;
        static Input& Get();

        bool GetKeyDown(SDL_Keycode);
        void SetKeyDown(SDL_Keycode);
        void SetKeyUp(SDL_Keycode);

        void SetMouseCoords(int x, int y);
        void GetMouseCoords(int &x, int &y);

        void SetMouseBtn(uint8_t btn, bool pressed);
        bool GetMouseBtn(uint8_t btn);


    private:
        static Input s_Instance;

        bool mouse_btn[5];
        int mouse_x=0, mouse_y=0;
        bool keys_down[322]; 
        Input();

};

