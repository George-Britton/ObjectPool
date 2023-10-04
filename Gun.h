#pragma once
#include "Bullet.h"

class Gun
{
public:
	Gun();
	~Gun() {};

	float fireRate = 1.f / 20.f;
	int magazineSize = 12;
	std::vector<Bullet*> bullets;
	Transform muzzle;
	std::chrono::steady_clock::time_point lastShot = std::chrono::high_resolution_clock::now();

	bool Fire();
};

