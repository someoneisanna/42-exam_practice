#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::vector<ATarget *> targets;

		TargetGenerator(const TargetGenerator &src);
		TargetGenerator &operator=(const TargetGenerator &src);

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *targetType);
		void forgetTargetType(std::string targetType);
		ATarget *createTarget(const std::string &targetType);
};
