#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;

		SpellBook spells;

		Warlock();
		Warlock(const Warlock &src);
		Warlock &operator=(const Warlock &src);

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &title);

		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget &target);
};
