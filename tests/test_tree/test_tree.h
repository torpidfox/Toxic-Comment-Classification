#pragma once

#include <QtCore/QCoreApplication>
#include<QtTest/QtTest>
#include<ctime>
#include<cstdlib>
#include "Classification/BSTNode.h"


class TestTree : public QObject {
	Q_OBJECT
		private slots:

	bool assert_bstness(tcc::BSTNode* n);

	void test_consistency();

	void test_benchmark();
};

