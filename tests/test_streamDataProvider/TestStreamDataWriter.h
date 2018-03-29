#include<QTest>
#include <iostream>
#include "DataConsumers\StreamDataWriter.h"

class TestStreamDataWriter : public QObject {
	Q_OBJECT
	private slots:
		void test_null_data_provided();
		void test_file_created();
		void test_file_content();
};
