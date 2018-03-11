#include "Core.h";
#include <vector>
#include <string>


void tcc::RandomCore::run(json& msg) const {
	std::string classes[] = { "toxic", "severe_toxic", "obscene", "threat", "insult", "identity_hate" };
	for each (std::string some_class in classes)
	{
		msg[some_class] = (double)(std::rand()) / RAND_MAX * MAX_PERCENT;
	}
}