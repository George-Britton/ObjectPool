#pragma once
#include <iostream>
#include <vector>
#include <future>
#include <chrono>

#define Transform std::vector<std::vector<float>>

class Bullet
{
public:
    Bullet() {};
    ~Bullet() {};

    int ID = 0;
    float damage = 5.f;
    std::future<void> despawn;
    bool isVisible = false;
    bool isCollidable = false;

    void Activate(Transform launchPoint);
    void SetLocation(Transform launchPoint) {};
};