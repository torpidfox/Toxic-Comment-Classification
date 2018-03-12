#pragma once

#include<memory>

#include "../DataProviders/DataProvider.h"
#include "../Cores/Core.h"
#include "../DataHandlers/DataPreprocessing.h"


/**
namespace tcc
@brief Пространство имен tcc
*/
namespace tcc {
	/**
	@brief Интерфейс для классов контроллеров управляющими ходом программы
	*/
	class Controller {
		/**
		@brief Виртуальная функция для запуска сценария программы
		*/
		virtual void run() const = 0;
	};


	/**
	@brief Основной класс контроллер управляющий ходом программы
	*/
	class MainController : public Controller {
	private:
		std::shared_ptr<DataProvider> _data_provider;
		std::shared_ptr<Core> _core;
		std::shared_ptr<DataPreprocessing> _data_processing;

	public:
		/**
		@brief Конструктор класса
		@param data_provider Указатель на используемый провайдер
		@param data_processing Указатель на используемый предобработчик данных
		@param core Указатель на используемое ядро
		*/
		MainController(std::shared_ptr<DataProvider> data_provider,
			std::shared_ptr<DataPreprocessing> data_processing,
			std::shared_ptr<Core> core)
			: _data_provider(data_provider), _core(core), _data_processing(data_processing)
		{};

		/**
		@brief Функция для запуска сценария программы
		*/
		void run() const override;
	};
}
