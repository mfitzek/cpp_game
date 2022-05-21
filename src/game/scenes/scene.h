#pragma once




class Scene{
public:
    virtual void update(double delta) = 0;
    virtual void tick() = 0;
    virtual void render() = 0;
    virtual ~Scene() = default;
};
