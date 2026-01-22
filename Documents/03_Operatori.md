# Оператори

## 1. Оператор за присвояване

**а/** **Синтаксис:**

```c
променлива = израз;
```

**б/** **Начин на изпълнение:**

Изчислява се стойността на израза отдясно на знака за присвояване и получената стойност се присвоява на променливата отляво.

### Терминология:

- **`=` (знак за присвояване)** - оператор за присвояване, който записва стойността отдясно в променливата отляво. **Важно:** Не е равенство! В C равенството се проверява с `==`

## 2. Условен оператор

**а/** **Синтаксис:**

**Пълна форма:**

```c
if (израз)
    оператор1
else
    оператор2
```

**Непълна форма:**

```c
if (израз)
    оператор
```

**б/** **Начин на изпълнение:**

**Пълна форма:**

![][image1]

**Непълна форма:**

![][image2]

### Терминология:

- **`if`** - условен оператор, проверява дали условието в скобите е истина (различно от 0)
- **`else`** - алтернативен оператор, изпълнява се когато условието на `if` е лъжа (равно на 0)
- **Условие (израз)** - израз, който се оценява като истина (ненулева стойност) или лъжа (0)

## 3. Съставен оператор

- Служи за обединяване на няколко оператора в един
- **Синтаксис** - започва с отваряща фигурна (къдрава) скоба, следва един или повече оператори и завършва със затваряща фигурна скоба

```c
{                     // { - начало на съставния оператор (блок)
    оператор1;        // ; - край на оператора
    оператор2;        // ; - край на оператора
    оператор3;        // ; - край на оператора
}                     // } - край на съставния оператор
```

### Терминология:

- **Съставен оператор (блок)** - група от оператори, заградени във фигурни скоби `{ }`. Позволява няколко оператора да се третират като един оператор. Използва се в `if`, `else`, `while`, `do-while` и други конструкции

## 4. Оператор за цикъл с предусловие

**а/** **Синтаксис:**

```c
while (израз)         // while - цикъл с предусловие, (условие) - кръгли скоби
    оператор          // тяло на цикъла (може да бъде съставен оператор { })
```

**б/** **Начин на изпълнение:**

![][image3]

### Терминология:

- **`while`** - оператор за цикъл с предусловие. Проверява условието **преди** да изпълни тялото. Ако условието е лъжа от самото начало, тялото няма да се изпълни нито веднъж
- **Цикъл** - конструкция, която повтаря изпълнението на оператор(и) докато условието е истина

## 5. Оператор за цикъл с постусловие

**а/** **Синтаксис:**

```c
do                   // do - начало на цикъл с постусловие
    оператор         // тяло на цикъла (може да бъде съставен оператор { })
while (израз);       // while - условие за продължение, (условие) - кръгли скоби, ; - край на оператора
```

**б/** **Начин на изпълнение:**

![][image4]

### Терминология:

- **`do-while`** - оператор за цикъл с постусловие. Изпълнява тялото **поне веднъж**, след това проверява условието. Ако условието е истина, цикълът се повтаря
- **Постусловие** - условието се проверява **след** изпълнение на тялото, за разлика от предусловието при `while`

## 6. Оператор за цикъл for

**а/** **Синтаксис:**

```c
for (инициализация; условие; стъпка)
    оператор
```

**б/** **Начин на изпълнение:**

1. Изпълнява се **инициализацията** (обикновено задаване на начална стойност на брояч)
2. Проверява се **условието** - ако е истина, изпълнява се операторът
3. Изпълнява се **стъпката** (обикновено увеличаване/намаляване на брояча)
4. Връща се на стъпка 2

**Пример:**

```c
#include <stdio.h>    // препроцесорна директива - включва стандартната библиотека за вход/изход (виж [Препроцесор](../01_Въведение%20в%20С.md#4-препроцесор-и-етапи-на-компилация))

int main(void) {
    int i;            // декларация на променлива (виж [Променливи](../02_Целочислени%20типове%20данни.md#2-променливи))
    
    // Отпечатва числата от 1 до 5
    for (i = 1; i <= 5; i = i + 1) {  // for - цикъл (виж [Оператор за цикъл for](#6-оператор-за-цикъл-for)), (инициализация; условие; стъпка) - кръгли скоби, = - присвояване (виж [Оператор за присвояване](#1-оператор-за-присвояване)), <= - сравнение (виж [Оператори за сравнение](#7-оператори-за-сравнение)), + - събиране (виж [Операции](../02_Целочислени%20типове%20данни.md#3-операции))
        printf("%d ", i);              // printf - функция за изход от #include <stdio.h> (виж [Въвеждане и извеждане](../02_Целочислени%20типове%20данни.md#5-въвеждане-и-извеждане-на-данни-от-целочислен-тип)), ; - край на оператора
    }                                  // } - край на съставния оператор (тяло на for) (виж [Съставен оператор](#3-съставен-оператор))
    
    return 0;
}
```

**Изход:** `1 2 3 4 5`

### Терминология:

- **`for`** - оператор за цикъл с брояч. Удобен когато знаем колко пъти искаме да повторим операцията
- **Инициализация** - задава начална стойност на променливата-брояч (изпълнява се веднъж в началото)
- **Условие** - определя до кога ще продължи цикълът (проверява се преди всяка итерация)
- **Стъпка** - определя как се променя броячът на всяка итерация (изпълнява се след всяка итерация)

**Примери:**

```c
// Въвеждане на n числа
for (i = 1; i <= n; i = i + 1) {  // for - цикъл (виж [Оператор за цикъл for](#6-оператор-за-цикъл-for)), (инициализация; условие; стъпка) - кръгли скоби, <= - сравнение (виж [Оператори за сравнение](#7-оператори-за-сравнение))
    scanf("%d", &number);         // scanf - функция за вход от #include <stdio.h> (виж [Въвеждане и извеждане](../02_Целочислени%20типове%20данни.md#5-въвеждане-и-извеждане-на-данни-от-целочислен-тип)), & - оператор за адрес, ; - край на оператора
}                                 // } - край на съставния оператор (виж [Съставен оператор](#3-съставен-оператор))

// Обратен ред
for (i = 10; i >= 1; i = i - 1) {  // for - цикъл (виж [Оператор за цикъл for](#6-оператор-за-цикъл-for)), (инициализация; условие; стъпка) - кръгли скоби, >= - сравнение (виж [Оператори за сравнение](#7-оператори-за-сравнение)), - - изваждане (виж [Операции](../02_Целочислени%20типове%20данни.md#3-операции))
    printf("%d ", i);               // printf - функция за изход от #include <stdio.h> (виж [Въвеждане и извеждане](../02_Целочислени%20типове%20данни.md#5-въвеждане-и-извеждане-на-данни-от-целочислен-тип)), ; - край на оператора
}                                   // } - край на съставния оператор (виж [Съставен оператор](#3-съставен-оператор))
```

### Сравнение между for и while - кога кое да използваме?

#### Основни разлики:

| Характеристика | `for` | `while` |
|----------------|-------|---------|
| **Структура** | Три части в заглавието: инициализация, условие, стъпка | Само условие в заглавието |
| **Инициализация** | В заглавието на цикъла | Преди цикъла |
| **Стъпка (увеличаване/намаляване)** | В заглавието на цикъла | В тялото на цикъла |
| **Кога е подходящ** | Когато знаем колко пъти искаме да повторим | Когато не знаем колко пъти ще се повтори |

#### Кога да използваме `for`:

**`for` е по-подходящ когато:**
- Знаем **точно колко пъти** искаме да повторим операцията
- Имаме **брояч**, който се променя с фиксирана стъпка
- Искаме **компактност** - инициализацията, условието и стъпката са на едно място

**Примери:**
- Отпечатване на числа от 1 до n
- Въвеждане на точно n числа
- Обработка на всеки елемент в известен диапазон

```c
// Пример: Отпечатване на числа от 1 до 10
for (i = 1; i <= 10; i = i + 1) {  // for - цикъл (виж [Оператор за цикъл for](#6-оператор-за-цикъл-for)), (инициализация; условие; стъпка) - кръгли скоби
    printf("%d ", i);               // printf - функция за изход от #include <stdio.h> (виж [Въвеждане и извеждане](../02_Целочислени%20типове%20данни.md#5-въвеждане-и-извеждане-на-данни-от-целочислен-тип))
}                                   // } - край на съставния оператор (виж [Съставен оператор](#3-съставен-оператор))
```

#### Кога да използваме `while`:

**`while` е по-подходящ когато:**
- **Не знаем** колко пъти ще се повтори операцията
- Условието зависи от **данни, които се променят в тялото**
- Искаме да **проверим условие преди** да изпълним тялото
- Обработваме данни докато не се достигне определено условие

**Примери:**
- Обработка на цифри на число (докато числото не стане 0)
- Четене на данни докато не се въведе специална стойност (напр. 0 или -1)
- Повтаряне на операция докато условието е изпълнено

```c
// Пример: Обработка на цифри докато числото не стане 0
int n = 1234;                      // декларация и инициализация (виж [Променливи](../02_Целочислени%20типове%20данни.md#2-променливи)), = - присвояване (виж [Оператор за присвояване](#1-оператор-за-присвояване))
while (n > 0) {                    // while - цикъл с предусловие (виж [Оператор за цикъл с предусловие](#4-оператор-за-цикъл-с-предусловие)), (условие) - кръгли скоби, > - сравнение (виж [Оператори за сравнение](#7-оператори-за-сравнение))
    digit = n % 10;                // % - модуло (виж [Операции](../02_Целочислени%20типове%20данни.md#3-операции)), = - присвояване
    printf("%d ", digit);          // printf - функция за изход от #include <stdio.h> (виж [Въвеждане и извеждане](../02_Целочислени%20типове%20данни.md#5-въвеждане-и-извеждане-на-данни-от-целочислен-тип))
    n = n / 10;                    // / - деление (виж [Операции](../02_Целочислени%20типове%20данни.md#3-операции)), = - присвояване
}                                  // } - край на съставния оператор (виж [Съставен оператор](#3-съставен-оператор))
```

#### Еквивалентност между for и while:

Всеки `for` цикъл може да се запише като `while` цикъл и обратно:

**Пример - for като while:**

```c
// for цикъл
for (i = 1; i <= 5; i = i + 1) {  // for - цикъл (виж [Оператор за цикъл for](#6-оператор-за-цикъл-for)), (инициализация; условие; стъпка) - кръгли скоби
    printf("%d ", i);              // printf - функция за изход от #include <stdio.h>
}                                  // } - край на съставния оператор

// Еквивалентен while цикъл
i = 1;                             // = - присвояване (инициализация) (виж [Оператор за присвояване](#1-оператор-за-присвояване))
while (i <= 5) {                   // while - цикъл с предусловие (виж [Оператор за цикъл с предусловие](#4-оператор-за-цикъл-с-предусловие)), (условие) - кръгли скоби, <= - сравнение (виж [Оператори за сравнение](#7-оператори-за-сравнение))
    printf("%d ", i);              // printf - функция за изход от #include <stdio.h>
    i = i + 1;                     // = - присвояване, + - събиране (стъпка) (виж [Операции](../02_Целочислени%20типове%20данни.md#3-операции))
}                                  // } - край на съставния оператор (виж [Съставен оператор](#3-съставен-оператор))
```

**Пример - while като for:**

```c
// while цикъл
int n = 1234;                      // декларация и инициализация (виж [Променливи](../02_Целочислени%20типове%20данни.md#2-променливи)), = - присвояване (виж [Оператор за присвояване](#1-оператор-за-присвояване))
while (n > 0) {                    // while - цикъл с предусловие (виж [Оператор за цикъл с предусловие](#4-оператор-за-цикъл-с-предусловие)), (условие) - кръгли скоби, > - сравнение (виж [Оператори за сравнение](#7-оператори-за-сравнение))
    digit = n % 10;                // % - модуло (виж [Операции](../02_Целочислени%20типове%20данни.md#3-операции)), = - присвояване
    printf("%d ", digit);          // printf - функция за изход от #include <stdio.h>
    n = n / 10;                    // / - деление (виж [Операции](../02_Целочислени%20типове%20данни.md#3-операции)), = - присвояване (стъпка)
}                                  // } - край на съставния оператор (виж [Съставен оператор](#3-съставен-оператор))

// Еквивалентен for цикъл (по-малко читаем в този случай)
for (n = 1234; n > 0; n = n / 10) {  // for - цикъл (виж [Оператор за цикъл for](#6-оператор-за-цикъл-for)), (инициализация; условие; стъпка) - кръгли скоби
    digit = n % 10;                  // % - модуло, = - присвояване
    printf("%d ", digit);            // printf - функция за изход от #include <stdio.h>
}                                    // } - край на съставния оператор (виж [Съставен оператор](#3-съставен-оператор))
```

#### Практически съвети:

1. **Използвай `for`** когато:
   - Имаш брояч, който се променя с фиксирана стъпка
   - Знаеш колко пъти искаш да повториш операцията
   - Кодът става по-четим с инициализация, условие и стъпка на едно място

2. **Използвай `while`** когато:
   - Условието зависи от данни, които се променят в тялото
   - Не знаеш колко пъти ще се повтори операцията
   - Условието е по-сложно и не се вписва добре в заглавието на `for`

3. **Читаемост на кода:**
   - `for` е по-компактен и ясен когато имаш брояч
   - `while` е по-ясен когато условието е по-сложно или зависи от данни в тялото

#### Резюме:

- **`for`** - за цикли с **известен брой итерации** и брояч с фиксирана стъпка
- **`while`** - за цикли с **неизвестен брой итерации**, където условието зависи от данни в тялото

И двата цикъла могат да се използват за едни и същи задачи, но изборът зависи от читаемостта и яснотата на кода.

## 7. Оператори за сравнение

Използват се за сравняване на две стойности. Резултатът е **истина** (1) или **лъжа** (0).

| Оператор | Значение | Пример | Резултат |
|----------|----------|--------|----------|
| `==` | Равно | `5 == 5` | 1 (истина) |
| `!=` | Различно | `5 != 3` | 1 (истина) |
| `>` | По-голямо | `5 > 3` | 1 (истина) |
| `<` | По-малко | `5 < 3` | 0 (лъжа) |
| `>=` | По-голямо или равно | `5 >= 5` | 1 (истина) |
| `<=` | По-малко или равно | `3 <= 5` | 1 (истина) |

**Важно:** `==` е за сравнение, `=` е за присвояване!

**Пример:**

```c
int a = 5, b = 3;              // декларация и инициализация (виж [Променливи](../02_Целочислени%20типове%20данни.md#2-променливи)), = - оператор за присвояване (виж [Оператор за присвояване](#1-оператор-за-присвояване))

if (a == b) {                  // if - условен оператор (виж [Условен оператор](#2-условен-оператор)), (условие) - кръгли скоби, == - оператор за сравнение (виж [Оператори за сравнение](#7-оператори-за-сравнение))
    printf("Числата са равни\n");  // printf - функция за изход от #include <stdio.h> (виж [Въвеждане и извеждане](../02_Целочислени%20типове%20данни.md#5-въвеждане-и-извеждане-на-данни-от-целочислен-тип))
} else {                       // else - алтернативен оператор (виж [Условен оператор](#2-условен-оператор))
    printf("Числата са различни\n");
}                              // } - край на съставния оператор (виж [Съставен оператор](#3-съставен-оператор))

if (a > b) {                   // if - условен оператор (виж [Условен оператор](#2-условен-оператор)), (условие) - кръгли скоби, > - оператор за сравнение (виж [Оператори за сравнение](#7-оператори-за-сравнение))
    printf("%d е по-голямо от %d\n", a, b);  // printf - функция за изход от #include <stdio.h>
}                              // } - край на съставния оператор (виж [Съставен оператор](#3-съставен-оператор))
```

## 8. Логически оператори

Използват се за комбиниране на условия.

| Оператор | Значение | Пример | Обяснение |
|----------|----------|--------|-----------|
| `&&` | И (AND) | `(a > 5) && (a < 10)` | Истина само ако и двете условия са истина |
| `\|\|` | ИЛИ (OR) | `(a < 5) \|\| (a > 10)` | Истина ако поне едно условие е истина |
| `!` | НЕ (NOT) | `!(a == 5)` | Обръща резултата (истина става лъжа и обратно) |

**Приоритет:** `!` > `&&` > `\|\|`

**Пример:**

```c
int age = 20;                  // декларация и инициализация (виж [Променливи](../02_Целочислени%20типове%20данни.md#2-променливи)), = - присвояване (виж [Оператор за присвояване](#1-оператор-за-присвояване))

// Проверка дали възрастта е между 18 и 65
if (age >= 18 && age <= 65) {  // if - условен оператор (виж [Условен оператор](#2-условен-оператор)), (условие) - кръгли скоби, >=, <= - оператори за сравнение (виж [Оператори за сравнение](#7-оператори-за-сравнение)), && - логически оператор И (виж [Логически оператори](#8-логически-оператори))
    printf("Възрастта е валидна\n");  // printf - функция за изход от #include <stdio.h> (виж [Въвеждане и извеждане](../02_Целочислени%20типове%20данни.md#5-въвеждане-и-извеждане-на-данни-от-целочислен-тип))
}                              // } - край на съставния оператор (виж [Съставен оператор](#3-съставен-оператор))

// Проверка дали числото е извън интервала [10, 20]
int number = 25;
if (number < 10 || number > 20) {  // if - условен оператор (виж [Условен оператор](#2-условен-оператор)), (условие) - кръгли скоби, <, > - оператори за сравнение (виж [Оператори за сравнение](#7-оператори-за-сравнение)), || - логически оператор ИЛИ (виж [Логически оператори](#8-логически-оператори))
    printf("Числото е извън интервала\n");  // printf - функция за изход от #include <stdio.h>
}                              // } - край на съставния оператор (виж [Съставен оператор](#3-съставен-оператор))
```

[image1]: data:image/png;base64,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

[image2]: data:image/png;base64,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

[image3]: data:image/png;base64,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

[image4]: data:image/png;base64,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
