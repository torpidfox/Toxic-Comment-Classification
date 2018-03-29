#include "TestStreamDataWriter.h"

void TestStreamDataWriter::test_null_data_provided() {
	tcc::StreamDataWriter tested = tcc::StreamDataWriter();
	std::string to_console = "test console output\n";

	tested << to_console;
	QVERIFY(tested.state() == tcc::StreamDataWriter::GOOD);
}

void TestStreamDataWriter::test_file_created() {
	std::string filename = "writer_test.txt";
	tcc::StreamDataWriter tested = tcc::StreamDataWriter(filename);

	tested << "success";
	std::ifstream infile(filename);

	QVERIFY(infile.good());
}


void TestStreamDataWriter::test_file_content() {
	std::string filename = "writer_test.txt";
	tcc::StreamDataWriter tested = tcc::StreamDataWriter(filename);

	std::string test_string = "test_string";
	double test_double = 5e-7;
	std::vector<int> test_vec = { 1, 2, 3 };

	tested << test_string;
	tested << "\n";
	tested << test_double;
	tested << "\n";
	tested << test_vec;

	tested.close();

	QVERIFY(tested.state() == tcc::StreamDataWriter::GOOD);

	std::ifstream infile(filename);

	std::string s_file;
	infile >> s_file;

	QVERIFY(s_file.compare(test_string) == 0);

	double d_file;
	infile >> d_file;

	QVERIFY(d_file == test_double);

	std::vector<int> v_file(3);
	for(auto i = v_file.begin(); i != v_file.end(); i++)
		infile >> *i;

	QVERIFY(v_file == test_vec);
}