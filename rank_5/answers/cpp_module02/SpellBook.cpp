#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++)
		delete(*it);
	spells.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (!spell)
		return;
	for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++)
	{
		if ((*it)->getName() == spell->getName())
			return;
	}
	spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(std::string spellName)
{
	for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++)
	{
		if ((*it)->getName() == spellName)
		{
			delete(*it);
			spells.erase(it);
			return;
		}
	}
}

ASpell *SpellBook::createSpell(const std::string &spellName)
{
	for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++)
	{
		if ((*it)->getName() == spellName)
			return ((*it)->clone());
	}
	return (NULL);
}
