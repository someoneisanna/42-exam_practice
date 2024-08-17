#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::vector<ASpell *> spells;

		SpellBook(const SpellBook &src);
		SpellBook &operator=(const SpellBook &src);

	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spellName);
		ASpell *createSpell(const std::string &spellName);
};
