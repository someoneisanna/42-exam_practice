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
	spells.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName)
{
	spells.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, ATarget &target)
{
	ASpell *spell = spells.createSpell(spellName);
	if (!spell)
		return;
	spell->launch(target);
	delete(spell);
}
