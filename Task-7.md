<h1 align='center'>ТРПО. Структуры и строки</h1>

# Структуры 


## Определение структур

Чтобы хранить совокупность данных используются структуры.
Структура определяется ключевым словом `struct`.

struct structName 
{  
     fields;      
};

`structName` -> имя структуры
`fields` -> поля структуры

> В конце объявления струтуры ставится точка с запятой 


Пример структуры `student` 

struct student
{
     int age;
     string name;
};

`age`, `name` - поля структуры

В качестве полей структуры могут выступать другие структуры

Пример структуры `group`

struct group
{
     student* students;
     string specialityName;
     student headman;
};

## Использование структур


Чтобы использовать структуру, нам нужно просто объявить переменную типа структуры

Пример использования структуры student 

`student victor;  // создаем отдельную структуру student для victor`
`student victoria; // создаём отдельную структуру student для victoria`

Доступ к членам-полям структуры осущевствяется при помощи оператора `.` (точка).

`victor.age = 22;`
`victor.name = "Victor";`

`cout<<"Name: "<<victor.name<<endl;`
`cout<<"Age: "<<victor.age<<endl;`

Инициализация полей 

`student victor = {22,"Victor"}`
`student victor {22,"Victor"}`

Если значение не заданно, то используется значение по-умолчанию 

Значения по-умолчанию
struct student 
{
     int age = 18;
     string name = "Victor"
};

Структуры можно передавать в функции

string toString(student victor){
        return victor.name+"   "+ to_string(victor.age); 
}

> Чтобы получить размер структуры используется оператор `sizeof()` 

# Строки

Для чтения строк лучше всего использовать `getline()`

`getline(cin, string)`

Выводить строки можно при помощи функции `cout<<string`;

Над строками можно выполнять некоторые операции:
- сложение;
- сравнение;
- присваивание;

 *[Функции для работы со строками](https://server.179.ru/tasks/cpp/total/161.html)*


# Требования к коду

Использовать Enum для константных значений в switch/case и при возврате кодов ошибок

# Задания

Базовое задание

1. Создать структуру, которая будет описывать  студента не менее 3 полей (обязательные поля - ФИО, дата рождения) 
> Дата рождения должна представлять из себя структуру {день, месяц, год}
2. Создать массив студентов
3. Заполнить массив студентов
4. Вывести студентов на экран
5. Найти самое распространённое имя
6. Отсортировать студентов по каком-либо признаку
7. Вывести каждого студента в формате -  Фамилия И.О., возраст, остальные данные
8. Найти средний возраст студентов


Повышенное задание

1. Открыть картинку (лучше использовать расширение .bmp)
2. Перевести картинку в чёрно-белую. Сохранить результат в отдельной картинке.
3. Перевести картивку в градацию серого. Сохранить результат в отдельной картинке.
4. Добавить на изображение белые точки (шумы), случайное кол-во (20-30% от оригинального изображения). Сохранить результат в отдельной картинке.
5. Применить к изображению из пункта 4 медианный фильтр. Матрицы 3х3 или 5х5. Сохранить результат.
   
Изображения лучше брать от 1280x720




