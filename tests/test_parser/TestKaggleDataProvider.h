#include <QtCore/QCoreApplication>

/**
@brief QT Unit Tests для класса, обрабатывающего тестовые данные с kaggle
*/

class TestKaggleDataProvider : public QObject {
	Q_OBJECT
		private slots:
	//некорректное имя входного файла
	void test_null_data_provided();
	//нехватка оперативной памяти
	void test_bad_mem_alloc();
	//тестовые данные для проверки корректности считывания в структуру и сама проверка
	void test_format_data();
	void test_format();
};
