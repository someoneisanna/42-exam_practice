#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string &type) : type(type) {}

ATarget::ATarget(const ATarget &src)
{
	*this = src;
}

ATarget::~ATarget() {}

ATarget &ATarget::operator=(const ATarget &src)
{
	if (this != &src)
		type = src.type;
	return (*this);
}

const std::string &ATarget::getType() const { return (type); }

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}
