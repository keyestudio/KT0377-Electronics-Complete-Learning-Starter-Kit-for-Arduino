# Проект 15: 4-значный светодиодный сегментный дисплей


![](../media/b1f91aef96b13289f2d8b72836087fbc.png)

#### Описание

Четырёхзначный индикатор состоит из четырёх отдельных семисегментных цифровых индикаторов, которые могут отображать четыре цифры или символа.

В этом проекте мы покажем, как создать проект Arduino, который отображает нужные вам числа с помощью платы разработки UNO R3 (ch340) и 4-значного светодиодного сегментного дисплея.

#### Аппаратное обеспечение

1\. Плата разработки UNO R3 (ch340) x1

2\. 4-значный светодиодный сегментный дисплей x1

3\. Макетная плата x1

4\. Соединительные провода

#### Принцип работы

Четырёхзначный индикатор состоит из четырёх отдельных семисегментных цифровых индикаторов, которые могут отображать четыре цифры или символа.

![IMG_256](../media/a9d51eebe95581f6413424ceee8c4b7f.jpeg)

Это уменьшает количество выводов многоразрядного дисплея, но увеличивает сложность управления им. Например, при таком подключении, если мы подадим напряжение на вывод A 4-значного дисплея, сегменты A всех светодиодных блоков включатся. Чтобы контролировать, какой светодиодный блок будет пропускать этот сигнал, у каждого блока есть дополнительный вывод — вывод цифры. Таким образом, в 4-значном дисплее также есть 4 вывода цифр, которые управляют светодиодными блоками индивидуально. Ниже показан 4-значный светодиодный дисплей с дополнительными 4 управляющими входами, по одному для каждого светодиодного блока.

![IMG_256](../media/905bfc7adc1126a24f8a7a95ee8adbe1.jpeg)Внутреннее соединение 4-значного *7-сегментного* светодиодного дисплея, показывающее выводы сегментов и управляющие выводы цифр, которые контролируют, будет ли сигнал с выводов сегментов отображаться на соответствующем светодиодном блоке.

В результате, если мы хотим отобразить число 1111, нам нужно подать напряжение на D1, D2, D3 и D4, потому что все дисплеи должны показать цифру. Также необходимо подать напряжение на входы B и C, как показано ниже:

![IMG_257](../media/e92e4aa83279f8ef20f4f5c356e4d8b6.jpeg)Изображение с красным цветом проводов, которые должны быть активированы для отображения числа «1111»

#### Технические характеристики

Функция: SDK

Цвет сегмента: Молочно-белый или такой же, как цвет свечения

Высота цифры: 0.28 дюйма

Цвет лицевой панели: Чёрный, серый или красный

Количество цифр: 4

Особенности: Энергосбережение и высокая стабильность

#### Распиновка

Типичный 4-значный 7-сегментный светодиодный дисплей имеет 12 выводов, по шесть с каждой стороны, как показано на рисунке ниже.

![IMG_258](../media/effde62c9d161a476dcbc6fe76e2da5a.jpeg)

Распиновка 4-значного *7-сегментного* светодиодного дисплея

Четыре из этих выводов (D1, D2, D3 и D4) используются для управления отдельными цифрами и определения, какие сигналы проходят через светодиодные блоки. Остальные выводы соответствуют отдельным сегментам.

#### Схема подключения

Подключите катодные выводы (D1, D2, D3, D4) цифрового индикатора к цифровым выводам (D2, D3, D4, D5) на плате.

Подключите анодные выводы (a, b, c, d, e, f, g, dp) цифрового индикатора к цифровым выводам (D6, D7, D8, D9, D10, D11, D12, D13) на плате.

![Img](../media/img-20260401190656.png)




#### Установка библиотеки

Перед началом программирования необходимо сначала установить библиотеку TimerOne.

**Откройте менеджер библиотек**: Нажмите на меню «Инструменты», затем выберите «Управление библиотеками…».

![](../media/7bb083e374003eb07f5eb6228618191d.png)

**Поиск библиотеки**:

В появившемся окне менеджера библиотек вы увидите поле поиска. Введите название библиотеки "TimerOne".

![](../media/a4be0ce7debc116f05c1da5834546828.png)

**Выбор и установка библиотеки**:

Найдите нужную библиотеку в результатах поиска и кликните по ней.

Справа появится кнопка «Установить». Нажмите на неё.

![](../media/860091441538594f42eecb411adcd5cd.png)

**Ожидание установки**: Arduino IDE автоматически загрузит и установит выбранную библиотеку. После завершения установки кнопка «Установить» изменится на «Установлено», что означает успешную установку.

#### Пример кода

```cpp

/*

Electronics Learning Starter Kit for Arduino

Project 15

4 digit LED Segment Display

Edit By Keyes

*/

#include <TimerOne.h>

//the pins of 4-digit 7-segment display attach to pin2-13 respectively

int a = 6;

int b = 7;

int c = 8;

int d = 9;

int e = 10;

int f = 11;

int g = 12;

int p = 13;

int d4 = 5;

int d3 = 4;

int d2 = 3;

int d1 = 2;

long n = 0;// n represents the value displayed on the LED display. For example, when n=0, 0000 is displayed. The maximum value is 9999.

int x = 100;

int del = 5;//Set del as 5; the value is the degree of fine tuning for the clock

int count = 0;//Set count=0. Here count is a count value that increases by 1 every 0.1 second, which means 1 second is counted when the value is 10

void setup()

{

//set all the pins of the LED display as output

pinMode(d1, OUTPUT);

pinMode(d2, OUTPUT);

pinMode(d3, OUTPUT);

pinMode(d4, OUTPUT);

pinMode(a, OUTPUT);

pinMode(b, OUTPUT);

pinMode(c, OUTPUT);

pinMode(d, OUTPUT);

pinMode(e, OUTPUT);

pinMode(f, OUTPUT);

pinMode(g, OUTPUT);

pinMode(p, OUTPUT);

Timer1.initialize(100000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)

Timer1.attachInterrupt( add ); // attach the service routine here

}

/*************************************\**/

void loop()

{

clearLEDs();//clear the 7-segment display screen

pickDigit(0);//Light up 7-segment display d1

pickNumber((n/1000));// get the value of thousand

delay(del);//delay 5ms

clearLEDs();//clear the 7-segment display screen

pickDigit(1);//Light up 7-segment display d2

pickNumber((n%1000)/100);// get the value of hundred

delay(del);//delay 5ms

clearLEDs();//clear the 7-segment display screen

pickDigit(2);//Light up 7-segment display d3

pickNumber(n%100/10);//get the value of ten

delay(del);//delay 5ms

clearLEDs();//clear the 7-segment display screen

pickDigit(3);//Light up 7-segment display d4

pickNumber(n%10);//Get the value of single digit

delay(del);//delay 5ms

}

/**************************************/

void pickDigit(int x) //light up a 7-segment display

{

//The 7-segment LED display is a common-cathode one. So also use digitalWrite to set d1 as high and the LED will go out

digitalWrite(d1, HIGH);

digitalWrite(d2, HIGH);

digitalWrite(d3, HIGH);

digitalWrite(d4, HIGH);

switch(x)

{

case 0:

digitalWrite(d1, LOW);//Light d1 up

break;

case 1:

digitalWrite(d2, LOW); //Light d2 up

break;

case 2:

digitalWrite(d3, LOW); //Light d3 up

break;

default:

digitalWrite(d4, LOW); //Light d4 up

break;

}

}

//The function is to control the 7-segment LED display to display numbers. Here x is the number to be displayed. It is an integer from 0 to 9

void pickNumber(int x)

{

switch(x)

{

default:

zero();

break;

case 1:

one();

break;

case 2:

two();

break;

case 3:

three();

break;

case 4:

four();

break;

case 5:

five();

break;

case 6:

six();

break;

case 7:

seven();

break;

case 8:

eight();

break;

case 9:

nine();

break;

}

}

void clearLEDs() //clear the 7-segment display screen

{

digitalWrite(a, LOW);

digitalWrite(b, LOW);

digitalWrite(c, LOW);

digitalWrite(d, LOW);

digitalWrite(e, LOW);

digitalWrite(f, LOW);

digitalWrite(g, LOW);

digitalWrite(p, LOW);

}

void zero() //the 7-segment led display 0

{

digitalWrite(a, HIGH);

digitalWrite(b, HIGH);

digitalWrite(c, HIGH);

digitalWrite(d, HIGH);

digitalWrite(e, HIGH);

digitalWrite(f, HIGH);

digitalWrite(g, LOW);

}

void one() //the 7-segment led display 1

{

digitalWrite(a, LOW);

digitalWrite(b, HIGH);

digitalWrite(c, HIGH);

digitalWrite(d, LOW);

digitalWrite(e, LOW);

digitalWrite(f, LOW);

digitalWrite(g, LOW);

}

void two() //the 7-segment led display 2

{

digitalWrite(a, HIGH);

digitalWrite(b, HIGH);

digitalWrite(c, LOW);

digitalWrite(d, HIGH);

digitalWrite(e, HIGH);

digitalWrite(f, LOW);

digitalWrite(g, HIGH);

}

void three() //the 7-segment led display 3

{

digitalWrite(a, HIGH);

digitalWrite(b, HIGH);

digitalWrite(c, HIGH);

digitalWrite(d, HIGH);

digitalWrite(e, LOW);

digitalWrite(f, LOW);

digitalWrite(g, HIGH);

}

void four() //the 7-segment led display 4

{

digitalWrite(a, LOW);

digitalWrite(b, HIGH);

digitalWrite(c, HIGH);

digitalWrite(d, LOW);

digitalWrite(e, LOW);

digitalWrite(f, HIGH);

digitalWrite(g, HIGH);

}

void five() //the 7-segment led display 5

{

digitalWrite(a, HIGH);

digitalWrite(b, LOW);

digitalWrite(c, HIGH);

digitalWrite(d, HIGH);

digitalWrite(e, LOW);

digitalWrite(f, HIGH);

digitalWrite(g, HIGH);

}

void six() //the 7-segment led display 6

{

digitalWrite(a, HIGH);

digitalWrite(b, LOW);

digitalWrite(c, HIGH);

digitalWrite(d, HIGH);

digitalWrite(e, HIGH);

digitalWrite(f, HIGH);

digitalWrite(g, HIGH);

}

void seven() //the 7-segment led display 7

{

digitalWrite(a, HIGH);

digitalWrite(b, HIGH);

digitalWrite(c, HIGH);

digitalWrite(d, LOW);

digitalWrite(e, LOW);

digitalWrite(f, LOW);

digitalWrite(g, LOW);

}

void eight() //the 7-segment led display 8

{

digitalWrite(a, HIGH);

digitalWrite(b, HIGH);

digitalWrite(c, HIGH);

digitalWrite(d, HIGH);

digitalWrite(e, HIGH);

digitalWrite(f, HIGH);

digitalWrite(g, HIGH);

}

void nine() //the 7-segment led display 9

{

digitalWrite(a, HIGH);

digitalWrite(b, HIGH);

digitalWrite(c, HIGH);

digitalWrite(d, HIGH);

digitalWrite(e, LOW);

digitalWrite(f, HIGH);

digitalWrite(g, HIGH);

}

/*****************************************\**/

void add()

{

// Toggle LED

count ++;

if(count == 10)

{

count = 0;

n++;

if(n == 10000)

{

n = 0;

}

}

}
```

#### Объяснение кода

```cpp
#include <TimerOne.h>
```

Эта строка подключает библиотеку `TimerOne`, которая используется для создания таймеров и прерываний.

```cpp

int a = 6;

int b = 7;

int c = 8;

int d = 9;

int e = 10;

int f = 11;

int g = 12;

int p = 13;

int d4 = 5;

int d3 = 4;

int d2 = 3;

int d1 = 2;

long n = 0;

int x = 100;

int del = 5;

int count = 0;

```

Эти строки определяют ряд переменных и констант:

`a` по `g` и `p` — выводы, используемые для подключения 7-сегментного светодиода.

`d1` по `d4` — выводы, используемые для выбора отображаемой цифры.

`n` хранит число, которое будет отображаться.

`x` задаёт частоту мигания светодиода, установленную в 100 раз в секунду.

`del` — задержка между обновлениями каждой цифры в миллисекундах.

`count` используется для подсчёта интервалов по 0.1 секунды для обновления дисплея.

```cpp
void setup() {

pinMode(d1, OUTPUT);

pinMode(d2, OUTPUT);

pinMode(d3, OUTPUT);

pinMode(d4, OUTPUT);

pinMode(a, OUTPUT);

pinMode(b, OUTPUT);

pinMode(c, OUTPUT);

pinMode(d, OUTPUT);

pinMode(e, OUTPUT);

pinMode(f, OUTPUT);

pinMode(g, OUTPUT);

pinMode(p, OUTPUT);

Timer1.initialize(100000);

Timer1.attachInterrupt( add );

}
```

В функции `setup()`:

Все выводы для светодиодов и цифр устанавливаются как выходы.

Таймер инициализируется с интервалом 100 000 микросекунд (0.1 секунды).

К таймеру привязывается функция обработки прерывания `add`.

```cpp
void loop() {

clearLEDs();

pickDigit(0);

pickNumber((n/1000));

delay(del);

clearLEDs();

pickDigit(1);

pickNumber((n%1000)/100);

delay(del);

clearLEDs();

pickDigit(2);

pickNumber(n%100/10);

delay(del);

clearLEDs();

pickDigit(3);

pickNumber(n%10);

delay(del);

}
```

В функции `loop()` повторяются следующие шаги для отображения цифр:

Очистка дисплея.

Последовательный выбор каждой цифры и отображение соответствующего числа.

```cpp
void pickDigit(int x) {

digitalWrite(d1, HIGH);

digitalWrite(d2, HIGH);

digitalWrite(d3, HIGH);

digitalWrite(d4, HIGH);

switch(x) {

case 0:

digitalWrite(d1, LOW);

break;

case 1:

digitalWrite(d2, LOW);

break;

case 2:

digitalWrite(d3, LOW);

break;

default:

digitalWrite(d4, LOW);

break;

}

}
```

Функция `pickDigit(int x)` используется для подсветки конкретной цифры:

Сначала все цифры выключаются.

В зависимости от значения параметра `x` выбирается цифра для подсветки.

```cpp

void pickNumber(int x) {

switch(x) {

default:

zero();

break;

case 1:

one();

break;

case 2:

two();

break;

case 3:

three();

break;

case 4:

four();

break;

case 5:

five();

break;

case 6:

six();

break;

case 7:

seven();

break;

case 8:

eight();

break;

case 9:

nine();

break;

}

}

```

Функция `pickNumber(int x)` используется для выбора отображаемого числа на основе параметра `x` и вызывает соответствующую функцию отображения цифры.

```cpp
void clearLEDs() {

digitalWrite(a, LOW);

digitalWrite(b, LOW);

digitalWrite(c, LOW);

digitalWrite(d, LOW);

digitalWrite(e, LOW);

digitalWrite(f, LOW);

digitalWrite(g, LOW);

digitalWrite(p, LOW);

}
```

Функция `clearLEDs()` используется для выключения всех светодиодов и очистки дисплея.

```cpp

void add() {

count ++;

if(count == 10) {

count = 0;

n++;

if(n == 10000) {

n = 0;

}

}

}

```

Функция `add()` — это обработчик прерывания таймера, используемый для обновления отображаемого числа:

Увеличивает `count` каждые 0.1 секунды.

Когда `count` достигает 10, сбрасывает его в 0 и увеличивает `n`.

Если `n` достигает 10 000, сбрасывает его в 0 для циклического отображения.

#### Результат проекта

После загрузки кода на плату Arduino вы увидите, как четырёхзначный 7-сегментный светодиодный дисплей начнёт мигать числами с заданным интервалом. Отображаемые числа будут постепенно увеличиваться от 0 до 9999, а затем снова начинаться с 0. Светодиод будет мигать 5 раз в секунду, обновляя число каждые 0.1 секунды.

![P15](../media/P15.gif)