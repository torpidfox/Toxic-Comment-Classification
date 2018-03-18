#include<QtTest/QtTest>
#include "TestKaggleDataProvider.h"
#include "DataProviders/DataProvider.h"


void TestKaggleDataProvider::test_null_data_provided() {
	std::string file_name = "nonexistent_file";
	tcc::KaggleDataProvider parser(file_name);
	QVERIFY(parser.get_data().size() == 0);
}

void TestKaggleDataProvider::test_bad_mem_alloc() {
	std::string file_name = "C:\\tmp\\test.csv";
	tcc::KaggleDataProvider parser(file_name);
	std::vector<int> memory_keeper(1);
	int memory_limit = memory_keeper.max_size();
	memory_keeper.resize(memory_limit * 0.99);
	parser.get_data();
}

void TestKaggleDataProvider::test_format_data() {
	QTest::addColumn<QString>("tag");
	QTest::addColumn<QString>("type");

	QTest::newRow("text") << "comment_text" << "string";
	QTest::newRow("ids per record") << "id" << "string";
	QTest::newRow("ratings per record") << "rating" << "object";
}

void TestKaggleDataProvider::test_format() {
	std::string file_name = "C:\\git\\DataProviders\\test.csv";
	tcc::KaggleDataProvider parser(file_name);
	std::vector<json> data = parser.get_data();


	for (json el : data) {
		QFETCH(QString, tag);
		QFETCH(QString, type);

		QCOMPARE(QString(el[tag.toLatin1().data()].type_name()), type);
	}
}
