#pragma once

#include "Message.h"

/**
 *
 */
class DataProcessing {
	virtual bool run(const Message& msg) const = 0;
};
