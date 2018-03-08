#pragma once

#include "DataProvider.h"
#include "Core.h"
#include "DataProcessing.h"


/**
 *
 */
class Controller {
private:
	std::shared_ptr<DataProvider> _data_provider;
	std::shared_ptr<Core> _core;
	std::shared_ptr<DataProcessing> _data_processing;

public:
	Controller(std::shared_ptr<DataProvider> data_provider, std::shared_ptr<Core> core,
		std::shared_ptr<DataProcessing> data_processing)
		: _data_provider(data_provider), _core(core), _data_processing(data_processing)
	{};

	void run();
};
