#include <iostream>
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int	main( void )
{
	Character*	zaz = new Character("zaz");
	Enemy*		a = new SuperMutant();
	Enemy*		b = new RadScorpion();
	AWeapon*	pr = new PlasmaRifle();
	AWeapon* 	pf = new PowerFist();

	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	zaz->attack(b);
	zaz->attack(b);
	zaz->attack(b);

	zaz->equip(pf);
	std::cout << *zaz;
	zaz->attack(a);
	zaz->attack(a);
	zaz->attack(a);
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->attack(a);
	zaz->attack(a);

	delete zaz;

	return 0;
}
