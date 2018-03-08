#pragma once

#include "Message.h"

/**
 *
 */
class Core {
	virtual void run(const Message& msg) const = 0;
};