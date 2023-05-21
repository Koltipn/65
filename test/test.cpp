
#include <gtest/gtest.h>
// Включаем заголовочные файлы с определениями функций
#include "../src/helper.hpp"
#include "test.hpp"

extern bool isPlaying;
extern int delay;
extern bool isInputMode;
extern const int DELAY_INC = 50;
// Тест для функции wrapValue
TEST(HelperFunctionsTest, WrapValue) {
  // Проверяем, что функция wrapValue возвращает ожидаемые значения
  EXPECT_EQ(wrapValue(-1, 10), 9);
  EXPECT_EQ(wrapValue(5, 10), 5);
  EXPECT_EQ(wrapValue(10, 10), 0);
}


// Тест для функции handleKeyboardInput - проверка правильного нажатия кнопки паузы "p"
TEST(HelperFunctionsTest, HandleKeyboardInput_PauseButtonPressed) {
  sf::Event event;
  event.key.code = sf::Keyboard::P;
  handleKeyboardInput(event);

  // Проверяем, что isPlaying стало false
  EXPECT_FALSE(isPlaying);
}

int mainTest(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);

  // Проверяем наличие аргумента командной строки "nographic" для запуска только тестов без открытия графического окна
  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "nographic") {
      // Запускаем тесты без открытия графического окна
      return RUN_ALL_TESTS();
    }
  }

  // Открытие графического окна
  // ...

  return 0;
}
