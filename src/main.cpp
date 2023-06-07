#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <LiquidCrystal.h>

#define led_pin_1 4
#define led_pin_2 6
#define led_pin_3 5
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void TaskBlink1(void *pvParameters);
void TaskBlink2(void *pvParameters);
void TaskBlink3(void *pvParameters);
//  protótipos para as tarefas
void TaskReadTemperature(void *pvParameters);
// Variável para armazenar a temperatura lida
volatile float temperature = 0.0;

void setup()
{
  pinMode(led_pin_1, OUTPUT);
  pinMode(led_pin_2, OUTPUT);
  pinMode(led_pin_3, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  // cria as tarefas
  xTaskCreate(
      TaskReadTemperature,
      "ReadTemperature",
      128,
      NULL,
      3,
      NULL);

  xTaskCreate(
      TaskBlink1, // função da tarefa - ponteiro
      "Blink1",
      128,   // tamanho da pilha
      NULL,  // parametro da tarefa
      2,     // prioridade - numeros mais altos - proporcional ao numero
      NULL); // agendar tarefa

  xTaskCreate(
      TaskBlink2, // função da tarefa - ponteiro
      "Blink2",
      128,   // tamanho da pilha
      NULL,  // parametro da tarefa
      1,     // prioridade - numeros mais altos - proporcional ao numero
      NULL); // agendar tarefa

  xTaskCreate(
      TaskBlink3, // função da tarefa - ponteiro
      "Blink3",
      128,   // tamanho da pilha
      NULL,  // parametro da tarefa
      1,     // prioridade - numeros mais altos - proporcional ao numero
      NULL); // agendar tarefa

  // Crie as outras tarefas aqui
}
void loop()
{
  // nada aqui!
}
void TaskReadTemperature(void *pvParameters)
{
  (void)pvParameters;
  float sensorValue = 0.0;
  for (;;)
  {
    lcd.setCursor(0, 0);
    lcd.print("                ");
    // Aqui você normalmente leria o valor do sensor de temperatura.
    // Por simplicidade, vamos apenas simular um sensor variando a temperatura de - 10 a 40.
    sensorValue = -10.0 + (rand() % 51);
    // gera um número aleatório entre -10 e 40
    temperature = sensorValue;
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");
    if (temperature >= 26)
    {
      lcd.setCursor(0, 1);
      lcd.print("Ligar Ar-condic");
    }
    else if (temperature <= 10)
    {
      lcd.setCursor(0, 1);
      lcd.print("Ligar Aquecedor");
    }
    else
    {
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
    vTaskDelay(2000 / portTICK_PERIOD_MS); // aguarda por 2 segundos
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
void TaskBlink1(void *pvParameters)
{
  (void)pvParameters;
  for (;;)
  { // loop infinito
    digitalWrite(led_pin_1, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS); // função millis do RTOS
    digitalWrite(led_pin_1, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void TaskBlink2(void *pvParameters)
{
  (void)pvParameters;
  for (;;)
  { // loop infinito
    if (temperature >= 26)
    {
      digitalWrite(led_pin_2, HIGH);
    }
    else
    {
      digitalWrite(led_pin_2, LOW);
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void TaskBlink3(void *pvParameters)
{
  (void)pvParameters;
  for (;;)
  { // loop infinito
    if (temperature <= 10)
    {
      digitalWrite(led_pin_3, HIGH);
    }
    else
    {
      digitalWrite(led_pin_3, LOW);
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}