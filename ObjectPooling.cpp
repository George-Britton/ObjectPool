#pragma once
#include <iostream>
#include "Gun.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"

int main()
{
    Gun* gun = new Gun;

    std::cout << "Press the spacebar to shoot\n";
    while (true)
    {
        if (GetAsyncKeyState(VK_SPACE)) gun->Fire();
    }
}

/// DEMO OF UNOPTIMISED VERSION
/*
#pragma once
#include <iostream>
#include <vector>
#include <future>
#include <chrono>

class Bullet
{
public:
    Bullet(int InID);
    ~Bullet() {};

    int ID;
    float damage = 5.f;
    std::future<void> despawn;
};

static void DespawnBullet(Bullet* bullet)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Destroyed bullet: " << bullet->ID << std::endl;
    delete bullet;
}

Bullet::Bullet(int InID)
{
    this->ID = InID;
    std::cout << "Created bullet: " << this->ID << std::endl;
    this->despawn = std::async(std::launch::async, DespawnBullet, this);
}

int main()
{
    std::vector<Bullet*> bullets;
    for (int i = 0; i < 10; i++)
    {
        Bullet* bullet = new Bullet(i);
        bullets.push_back(bullet);
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
*/