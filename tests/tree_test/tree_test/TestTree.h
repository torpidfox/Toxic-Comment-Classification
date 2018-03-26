#include <QtCore/QCoreApplication>
#include<QtTest/QtTest>
#include<ctime>
#include<cstdlib>
#include "Vocab.h"


class TestTree : public QObject {
	Q_OBJECT
		private slots:
	void test_null_data_provided();

	bool assert_bstness(tcc::BSTNode* n);

	void test_consistency();

	void test_benchmark();
};
