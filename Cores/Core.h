#pragma once

#include "../DataTypes/Message.h"

/**
 *
 */
class Core {
	virtual void run(const Message& msg) const = 0;
};