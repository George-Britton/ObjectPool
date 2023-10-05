#pragma once
#include "Bullet.h"
#include "Gun.h"

static void DeactivateBullet(Bullet* bullet)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    bullet->isCollidable = false;
    bullet->isVisible = false;
    std::cout << "Bullet #" << bullet->ID << " deactivated\n";
}

void Bullet::Activate(Transform launchPoint)
{
    this->SetLocation(launchPoint);
    this->isCollidable = true;
    this->isVisible = true;
    std::cout << "Bullet #" << this->ID << " activated\n";
    this->despawn = std::async(std::launch::async, DeactivateBullet, this);
}

