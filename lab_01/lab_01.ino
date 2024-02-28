/*
Лабораторная 1
Задача: зажигать светодиод по нажатию кнопки
*/

// Номера пинов
int led = 7;
int button = 13;
// Переменные состояния
bool button_not_pressed = true;
bool led_shine = false;

void setup() {
  // Настройка пинов на выход/вход
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  // Берем состояние кнопки на данный момент
  bool button_not_pressed_now = digitalRead(button);
  // Если кнопка была НЕ нажата, а сейчас нажата
  if (button_not_pressed && !button_not_pressed_now) {
    delay(10);
    // Повторно проверяем что кнопка сейчас НЕ нажата
    button_not_pressed_now = digitalRead(button);
    if (!button_not_pressed_now) {
      // Меняем состояние светодиода на противоположное
      led_shine = !led_shine;
      digitalWrite(led, led_shine);
    }
  }
  button_not_pressed = button_not_pressed_now;
}
