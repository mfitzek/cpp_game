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
    if(key_map.contains(key)){
        return key_map[key];
    }
    return false;
}

void Input::SetKeyDown(SDL_Keycode key)
{
   key_map.insert_or_assign(key, true);
}
void Input::SetKeyUp(SDL_Keycode key)
{
     key_map.insert_or_assign(key, false);
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