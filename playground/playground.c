#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>

#define BUFFER 256
#define RESULTS_FILE "playground/results.log"
static void log_quiz_result(const char *title, size_t score, size_t total) {
    FILE *fp = fopen(RESULTS_FILE, "a");
    if (!fp) {
        perror("Не мога да запиша резултат");
        return;
    }
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char timestamp[64];
    if (tm_info) {
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);
    } else {
        snprintf(timestamp, sizeof(timestamp), "без време");
    }
    double percent = (total > 0) ? (100.0 * score / total) : 0.0;
    fprintf(fp, "[%s] %s -> %zu/%zu (%.1f%%)\n", timestamp, title, score, total, percent);
    fclose(fp);
}

typedef struct {
    const char *question;
    const char *answers[4];
    char correct;
    const char *explanation;
} Question;

static void wait_for_enter(void) {
    printf("\nНатисни Enter за продължение...");
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* изчистваме буфера */
    }
}

static int read_int_choice(void) {
    char buf[BUFFER];
    if (!fgets(buf, sizeof(buf), stdin)) {
        return -1;
    }
    char *end = NULL;
    long value = strtol(buf, &end, 10);
    if (end == buf) {
        return -1;
    }
    return (int)value;
}

static int is_valid_identifier(const char *name) {
    if (!name || !name[0]) {
        return 0;
    }
    if (!(isalpha((unsigned char)name[0]) || name[0] == '_')) {
        return 0;
    }
    for (size_t i = 1; name[i]; ++i) {
        if (name[i] == '\n') {
            break;
        }
        if (!(isalnum((unsigned char)name[i]) || name[i] == '_')) {
            return 0;
        }
    }
    return 1;
}

static void lesson_levels(void) {
    puts("\n=== Стъпка 1: Нива на езиците и транслация (8 клас, ТУЕС) ===\n");
    puts("• I поколение – машинни езици. Работят с 0 и 1 и зависят изцяло от процесора.");
    puts("• II поколение – асемблерни езици. Използват мнемоники (MOV, ADD) и все още са машинно зависими.");
    puts("• III поколение – езици от високо ниво (C, Pascal, Python). Те са машинно независими и се четат като псевдоезик.");
    puts("\nТрансляторът е специална програма, която превежда изходния код на машинен език.");
    puts("Основни видове транслятори:");
    puts("1) Компилатор – анализира целия файл (пример: `опит.c`) и създава готов изпълним файл (`opit.exe`).");
    puts("2) Интерпретатор – превежда и изпълнява ред по ред, без отделен .exe.");
    puts("3) Линкер/свързващ редактор – комбинира обектните файлове и стандартните библиотеки.");
    puts("\n⚙️ В C най-често използваме компилатор: `clang opit.c -o opit`.");
    puts("   Получената програма се стартира самостоятелно, независимо от IDE.");
    wait_for_enter();
}

static void lesson_identifiers(void) {
    puts("\n=== Стъпка 2: Азбука и идентификатори ===\n");
    puts("Азбуката на C се състои от три групи:");
    puts(" 1) Букви – латински, малки и големи (A..Z, a..z).");
    puts(" 2) Цифри – 0..9.");
    puts(" 3) Специални символи – + - * / % = < > ! & | ^ # ( ) { } [ ] , ; : ? _ \" ' и др.");
    puts("\nЛексема е най-малката смислена единица в програмата. Видове:");
    puts(" • Ключови думи (if, else, while, do, int, char). Задължително се пишат с малки букви.");
    puts(" • Идентификатори – имена на променливи, функции, константи.");
    puts(" • Константи и оператори.");
    puts("\nПравила за идентификатори:");
    puts(" - започват с буква или `_`;");
    puts(" - съдържат букви, цифри и `_`;");
    puts(" - чувствителни са към регистъра (Main != main);");
    puts(" - не могат да съвпадат с ключова дума.");
    printf("\nВъведи примерен идентификатор за проверка: ");
    char name[BUFFER];
    if (!fgets(name, sizeof(name), stdin)) {
        puts("Грешка при въвеждане.");
        return;
    }
    if (is_valid_identifier(name)) {
        puts("✅ Поздравления! Името е валиден идентификатор.");
    } else {
        puts("⚠️ Това не е валиден идентификатор. Опитайте отново.");
    }
    wait_for_enter();
}

static void lesson_constants_ops(void) {
    puts("\n=== Стъпка 3: Константи и оператори ===\n");
    puts("Константата е стойност, която не се променя по време на изпълнение: 12, -45, 2.5, 'a', \"text\".");
    puts("• Цели константи могат да имат знак (+/-).");
    puts("• Реални числа се записват с точка (2.5).");
    puts("• Символни – оградени с апострофи 'A'.");
    puts("\nОсновни групи оператори:");
    puts(" 1) Аритметични: +  -  *  /  %");
    puts(" 2) Оператори за присвояване: =, +=, -=, *=, /=, %=.");
    puts(" 3) Сравнения: ==  !=  <  <=  >  >=");
    puts(" 4) Логически: &&  ||  !");
    puts(" 5) Оператори за групиране: ( ) { } , ; – точката и запетая приключва всеки оператор.");
    puts("\nВъвеждането на няколко променливи става с запетаи: `int a, b;`");
    puts("Операторът `;` завършва инструкциите, а `{ }` ограждат блок.");
    puts("\nМини упражнение: въведи проста аритметична стойност (пример 3+4*2).");
    printf("Израз = ");
    char expr[BUFFER];
    if (fgets(expr, sizeof(expr), stdin)) {
        puts("☺️ Запиши си резултата и го провери в реален компилатор по-късно.");
    }
    wait_for_enter();
}

static void lesson_structure(void) {
    puts("\n=== Стъпка 4: Структура на програма и функции ===\n");
    puts("Една C програма се състои от една или повече функции.");
    puts("Главната функция е `main()` – от нея започва изпълнението.");
    puts("\nДефиницията на функция има две части:");
    puts(" 1) Заглавие (прототип): тип_връщане име(параметри)");
    puts(" 2) Тяло: блок между `{` и `}` с оператори, подредени алгоритмично.");
    puts("\nПримерен скелет:");
    puts("#include <stdio.h>");
    puts("int main(void) {");
    puts("    // стъпки от алгоритъма");
    puts("    return 0; // 0 означава успешно приключване");
    puts("}");
    puts("\nАко функцията не връща стойност, използваме ключовата дума `void`.");
    puts("Коментарите описват какво прави даден блок и се пишат с // или /* */.");
    puts("Всяка помощна функция се описва преди или след main и се декларира с прототип.");
    wait_for_enter();
}

static void lesson_types(void) {
    puts("\n=== Стъпка 5: Типове данни и диапазони ===\n");
    puts("Типовете се делят на:");
    puts(" • Цели (integral) – signed/unsigned char, short, int, long.");
    puts(" • Реални – float, double (64-bit), long double.");
    puts(" • Символни – char (пази ASCII код).");
    puts(" • Структурирани – масиви, структури, enum (ще разгледаме по-късно).");
    puts("\nРазмери на базовите типове на повечето 64-bit компютри:");
    printf("%-12s %-12s %-12s\n", "Тип", "sizeof", "Пример");
    printf("%-12s %-12zu %-12s\n", "char", sizeof(char), "'A'");
    printf("%-12s %-12zu %-12s\n", "short", sizeof(short), "-32768..32767");
    printf("%-12s %-12zu %-12s\n", "int", sizeof(int), "-2147483648..2147483647");
    printf("%-12s %-12zu %-12s\n", "long", sizeof(long), ">= int");
    printf("%-12s %-12zu %-12s\n", "float", sizeof(float), "3.14f");
    printf("%-12s %-12zu %-12s\n", "double", sizeof(double), "2.71828");
    puts("\nЗапомни: short <= int <= long по брой байтове.");
    puts("Когато използваме `unsigned`, диапазонът започва от 0 и горната граница се удвоява.");
    puts("Всяка променлива пази ЕДНА стойност в даден момент – ако присвоиш нова, старата се губи.");
    wait_for_enter();
}

static void run_quiz_set(const Question *quiz, size_t total, const char *title) {
    printf("\n=== Тест: %s ===\n", title);
    size_t score = 0;
    char answer[BUFFER];

    for (size_t i = 0; i < total; ++i) {
        puts(quiz[i].question);
        for (int opt = 0; opt < 4; ++opt) {
            puts(quiz[i].answers[opt]);
        }
        printf("Избор (a/b/c/d): ");
        if (!fgets(answer, sizeof(answer), stdin)) {
            continue;
        }
        if (answer[0] == quiz[i].correct || answer[0] == toupper((unsigned char)quiz[i].correct)) {
            printf("✅ Вярно! %s\n\n", quiz[i].explanation);
            ++score;
        } else {
            printf("❌ Невярно. Правилен отговор: %c\n", quiz[i].correct);
            printf("ℹ️ Защо: %s\n\n", quiz[i].explanation);
        }
    }
    double percent = (total > 0) ? (100.0 * score / total) : 0.0;
    printf("Резултат: %zu/%zu верни отговора (%.1f%%).\n", score, total, percent);
    log_quiz_result(title, score, total);
    puts("✍️ Резултатът е записан в файл `playground/results.log`.");
    wait_for_enter();
}

static void run_quizzes(void) {
    static const Question quiz_levels[] = {
        {
            "1) Кой език е машинно зависим?",
            {"a) C", "b) Python", "c) Асемблер", "d) HTML"},
            'c',
            "Асемблерът използва мнемоники за конкретен процесор и е II поколение."
        },
        {
            "2) Каква е основната роля на компилатора?",
            {"a) Стартира програмата", "b) Превежда целия код в машинни инструкции", "c) Рисува диаграми", "d) Управлява паметта"},
            'b',
            "Компилаторът анализира и превежда целия файл преди изпълнение."
        },
        {
            "3) Как се нарича файлът след компилация?",
            {"a) .txt", "b) .exe или .out", "c) .py", "d) .ppt"},
            'b',
            "Компилацията създава изпълним файл (.exe в Windows, .out в Unix)."
        }
    };

    static const Question quiz_identifiers[] = {
        {
            "1) Кое име е НЕвалидно?",
            {"a) dataSum", "b) _result3", "c) for", "d) max_value"},
            'c',
            "`for` е ключова дума и не може да се използва като идентификатор."
        },
        {
            "2) Какво означава \"лексема\"?",
            {"a) Оператор за деление", "b) Най-малката смислена единица в програмата", "c) Процесорна инструкция", "d) Вид константа"},
            'b',
            "Лексема е символна последователност със самостоятелен смисъл (ключова дума, идентификатор...)."
        },
        {
            "3) Какво е вярно за идентификаторите?",
            {"a) Могат да започват с цифра", "b) Могат да съдържат интервали", "c) Чувствителни са към регистъра", "d) Пишат се само с главни букви"},
            'c',
            "Main и main са различни имена – C е case sensitive."
        }
    };

    static const Question quiz_constants[] = {
        {
            "1) Как записваме реално число?",
            {"a) 5,2", "b) 5.2", "c) 5:2", "d) 5;2"},
            'b',
            "В C използваме точка като разделител на цялата и дробната част."
        },
        {
            "2) Кой оператор връща остатъка от деление?",
            {"a) /", "b) %", "c) *", "d) +"},
            'b',
            "`%` дава остатъка: 7 % 3 == 1."
        },
        {
            "3) Как се разделят няколко декларации от един тип?",
            {"a) С интервал", "b) С ':'", "c) С запетая", "d) С '/'"},
            'c',
            "Пример: `int a, b, c;` – имената са разделени със запетая."
        }
    };

    static const Question quiz_structure[] = {
        {
            "1) Коя функция винаги присъства в C програмата?",
            {"a) calc()", "b) start()", "c) main()", "d) print()"},
            'c',
            "`main()` е входната точка – без нея програмата няма откъде да започне."
        },
        {
            "2) С какво завършва всеки оператор?",
            {"a) С ','", "b) С ';'", "c) С ')'", "d) С празен ред"},
            'b',
            "Точката и запетаята маркира края на инструкциите."
        },
        {
            "3) Какво ограждат `{` и `}`?",
            {"a) Коментари", "b) Текст на екрана", "c) Блок от оператори", "d) Константи"},
            'c',
            "Блоковете (тяло на функция, условие, цикъл) се ограничават с къдрави скоби."
        }
    };

    static const Question quiz_types[] = {
        {
            "1) Кой тип е подходящ за символ?",
            {"a) int", "b) char", "c) double", "d) long"},
            'b',
            "`char` съхранява един ASCII символ."
        },
        {
            "2) Какво прави ключовата дума `unsigned`?",
            {"a) Забранява числата", "b) Прави типа с плаваща запетая", "c) Позволява само положителни стойности", "d) Превръща го в текст"},
            'c',
            "`unsigned int` започва от 0 и удвоява максималната граница."
        },
        {
            "3) Кое твърдение е вярно?",
            {"a) short е по-дълъг от long", "b) Всички типове имат еднакъв размер", "c) float е по-малък от double", "d) char може да съхранява низ"},
            'c',
            "Обикновено float е 4 байта, а double – 8 байта, тоест double е по-прецизен."
        }
    };

    const struct {
        const char *title;
        const Question *questions;
        size_t count;
    } sets[] = {
        {"Нива и транслация", quiz_levels, sizeof(quiz_levels) / sizeof(quiz_levels[0])},
        {"Азбука и идентификатори", quiz_identifiers, sizeof(quiz_identifiers) / sizeof(quiz_identifiers[0])},
        {"Константи и оператори", quiz_constants, sizeof(quiz_constants) / sizeof(quiz_constants[0])},
        {"Структура на програма", quiz_structure, sizeof(quiz_structure) / sizeof(quiz_structure[0])},
        {"Типове данни", quiz_types, sizeof(quiz_types) / sizeof(quiz_types[0])}
    };

    for (;;) {
        puts("\n=== Стъпка 6: Избери тест ===");
        for (size_t i = 0; i < sizeof(sets) / sizeof(sets[0]); ++i) {
            printf("%zu) %s\n", i + 1, sets[i].title);
        }
        puts("0) Назад");
        printf("Избор: ");
        int choice = read_int_choice();
        if (choice == 0) {
            return;
        }
        if (choice < 0 || (size_t)choice > sizeof(sets) / sizeof(sets[0])) {
            puts("⚠️ Невалидна опция. Опитай пак.");
            continue;
        }
        run_quiz_set(sets[choice - 1].questions, sets[choice - 1].count, sets[choice - 1].title);
    }
}

static void show_menu(void) {
    puts("\n=============================");
    puts(" C Playground – избери стъпка");
    puts("=============================");
    puts("1) Нива на езиците и транслация");
    puts("2) Азбука и идентификатори");
    puts("3) Константи и оператори");
    puts("4) Структура на програма");
    puts("5) Типове данни");
    puts("6) Тестове (5 комплекта)");
    puts("0) Изход");
    printf("Избор: ");
}

int main(void) {
    setlocale(LC_ALL, "");

    for (;;) {
        show_menu();
        int choice = read_int_choice();
        switch (choice) {
            case 1:
                lesson_levels();
                break;
            case 2:
                lesson_identifiers();
                break;
            case 3:
                lesson_constants_ops();
                break;
            case 4:
                lesson_structure();
                break;
            case 5:
                lesson_types();
                break;
            case 6:
                run_quizzes();
                break;
            case 0:
                puts("До скоро! Продължавай да упражняваш C.");
                return 0;
            default:
                puts("Моля, избери валидна опция.");
                break;
        }
    }
}

