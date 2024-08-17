#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *targetType)
{
	if (!targetType)
		return;
	for (std::vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++)
	{
		if ((*it)->getType() == targetType->getType())
			return;
	}
	targets.push_back(targetType);
}

void TargetGenerator::forgetTargetType(std::string targetType)
{
	for (std::vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++)
	{
		if ((*it)->getType() == targetType)
		{
			targets.erase(it);
			return;
		}
	}
}

ATarget *TargetGenerator::createTarget(const std::string &targetType)
{
	for (std::vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++)
	{
		if ((*it)->getType() == targetType)
			return (*it);
	}
	return (NULL);
}
