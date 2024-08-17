#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : name(name), title(title)
{
	std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << getName() << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const { return (name); }

const std::string &Warlock::getTitle() const { return (title); }

void Warlock::setTitle(const std::string &title) { this->title = title; }

void Warlock::introduce() const
{
	std::cout << getName() << ": I am: " << getName() << ", " << getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if (!spell)
		return;
	for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++)
	{
		if ((*it)->getName() == spell->getName())
			return;
	}
	spells.push_back(spell);
}

void Warlock::forgetSpell(std::string spellName)
{
	for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++)
	{
		if ((*it)->getName() == spellName)
		{
			spells.erase(it);
			return;
		}
	}
}

void Warlock::launchSpell(std::string spellName, ATarget &target)
{
	for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++)
	{
		if ((*it)->getName() == spellName)
		{
			(*it)->launch(target);
			return;
		}
	}
}
