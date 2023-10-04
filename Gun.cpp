#include "Gun.h"

Gun::Gun()
{
	for (int bulletCount = 0; bulletCount < this->magazineSize; bulletCount++)
	{
		Bullet* newBullet = new Bullet();
		newBullet->ID = bulletCount;
		bullets.push_back(newBullet);
	}
}

bool Gun::Fire()
{
	std::chrono::duration<double> timeElapsed = std::chrono::high_resolution_clock::now() - this->lastShot;

	if (timeElapsed.count() > this->fireRate)
	{
		this->lastShot = std::chrono::high_resolution_clock::now();
		for (Bullet* bullet : this->bullets)
		{
			if (!bullet->isCollidable)
			{
				bullet->Activate(this->muzzle);
				std::cout << "bang!\n";
				return true;
			}
		}
		std::cout << "click\n";
		return false;
	}
	return false;
}