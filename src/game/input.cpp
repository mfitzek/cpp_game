#include "input.h"
#include <iostream>

Input::Input() {

}

Input Input::s_Instance;

Input& Input::Get()
{
    return s_Instance;
}

bool Input::GetKeyDown(SDL_Keycode key)
{
    return keys_down[key];
}

void Input::SetKeyDown(SDL_Keycode key)
{
    keys_down[key] = true;
}
void Input::SetKeyUp(SDL_Keycode key)
{
    keys_down[key] = false;
}

void Input::SetMouseCoords(int x, int y){
   // std::cout << mouse_x << ":" << mouse_y << std::endl;
    mouse_x = x;
    mouse_y = y;
}

void Input::GetMouseCoords(int &x, int &y){
    x = mouse_x;
    y = mouse_y;
}


void Input::SetMouseBtn(uint8_t btn, bool pressed){
    mouse_btn[btn] = pressed;
}
bool Input::GetMouseBtn(uint8_t btn){
    return mouse_btn[btn];
}