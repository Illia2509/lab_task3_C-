#include <iostream>     // Бібліотека для введення та виведення
#include <sstream>      // Бібліотека для роботи з рядками через stringstream
#include <string>       // Бібліотека для роботи з рядками
#include <algorithm>    // Бібліотека для алгоритмічних функцій

// Функція для очищення слова, видаляючи всі символи, крім букв
std::string cleanWord(const std::string& word) {
    std::string cleanedWord;  // Змінна для збереження очищеного слова
    for (char ch : word) {    // Проходимо по кожному символу в слові
        if (std::isalpha(ch)) {  // Якщо символ є буквою
            cleanedWord += ch;   // Додаємо його до очищеного слова
        }
    }
    return cleanedWord;  // Повертаємо очищене слово
}

int main() {
    // Змінна для збереження введеного тексту
    std::string text;
    std::cout << "Введіть ваш текст: ";
    std::getline(std::cin, text);  // Зчитуємо весь рядок тексту

    std::string longestWord;       // Змінна для зберігання найдовшого слова
    std::string word;              // Змінна для зберігання кожного слова з тексту

    // Створюємо stringstream для зручного поділу тексту на слова
    std::stringstream ss(text);

    // Проходимо по кожному слову в тексті
    while (ss >> word) {
        // Очищуємо слово, видаляючи небуквені символи
        std::string cleanedWord = cleanWord(word);

        // Якщо очищене слово довше за попереднє найдовше, оновлюємо найдовше слово
        if (cleanedWord.length() > longestWord.length()) {
            longestWord = cleanedWord;
        }
    }

    // Перевіряємо, чи знайдено найдовше слово, і виводимо результат
    if (!longestWord.empty()) {
        std::cout << "Найдовше слово: " << longestWord << std::endl;
    } else {
        std::cout << "Не було введено жодного слова." << std::endl;
    }

    return 0;  // Завершуємо програму
}
